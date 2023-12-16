#include <iostream>
#include <string>
#include <locale>

using namespace std;

class Ability {
public:
    virtual void Use() const = 0;
    virtual ~Ability() {}
};

class FlyingAbility : public Ability {
public:
    void Use() const override {
        cout << "Летает!\n";
    }
};

class SuperStrengthAbility : public Ability {
public:
    void Use() const override {
        cout << "Сверхсила!\n";
    }
};

class SuperSpeedAbility : public Ability {
public:
    void Use() const override {
        cout << "Сверхскорость!\n";
    }
};

class Alignment {
public:
    virtual const string& GetAlignment() const = 0;
    virtual ~Alignment() {}
};

class GoodAlignment : public Alignment {
public:
    const string& GetAlignment() const override {
        return alignment;
    }

private:
    const string alignment = "Добрый";
};

class EvilAlignment : public Alignment {
public:
    const string& GetAlignment() const override {
        return alignment;
    }

private:
    const string alignment = "Злой";
};

class Species {
public:
    virtual const string& GetSpecies() const = 0;
    virtual ~Species() {}
};

class Human : public Species {
public:
    const string& GetSpecies() const override {
        return species;
    }

private:
    const string species = "Человек";
};

class Animal : public Species {
public:
    const string& GetSpecies() const override {
        return species;
    }

private:
    const string species = "Животное";
};

class Deity : public Species {
public:
    const string& GetSpecies() const override {
        return species;
    }

private:
    const string species = "Божество";
};

class Superhero : public Alignment, public Species {
public:
    Superhero(const string& name) : name(name), ability(nullptr) {}

    const string& GetName() const {
        return name;
    }

    void SetAbility(Ability* newAbility) {
        ability = newAbility;
    }

    void UseAbility() const {
        if (ability) {
            ability->Use();
        }
        else {
            cout << "У супергероя нет способности!\n";
        }
    }

    virtual const string& GetAlignment() const override {
        return ""; // Заглушка, т.к. в данном контексте не используется
    }

    virtual const string& GetSpecies() const override {
        return ""; // Заглушка, т.к. в данном контексте не используется
    }

    ~Superhero() {
        delete ability;
    }

private:
    string name;
    Ability* ability;
};

class Mystic : public Superhero {
public:
    Mystic() : Superhero("Мистик") {
        SetAbility(new FlyingAbility());
    }
};

class Wolverine : public Superhero {
public:
    Wolverine() : Superhero("Росомаха") {
        SetAbility(new SuperStrengthAbility());
    }
};

class IronMan : public Superhero {
public:
    IronMan() : Superhero("Человек-Железный") {
        SetAbility(new FlyingAbility());
    }
};

int main() {
    setlocale(LC_ALL, "ru");

    Mystic mystic;
    Wolverine wolverine;
    IronMan ironMan;

    cout << "Супергерои, которые умеют летать:\n";
    mystic.UseAbility();
    ironMan.UseAbility();

    return 0;
}