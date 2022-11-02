#include <iostream>
#include <cstdio>
#include <set>
#include <iterator>
#include <map>
#define int long long
#define bgint __int128
using namespace std;
 
const int MAX_NOEUDS = (100 * 1000);
 
struct ratio {
    bgint num, denom;
    void Print() {
    //    printf("%lld %lld\n", num, denom);
    }
};
 
struct pente {
    int quart;
    ratio acc;
    void Print() {
    //    printf("%lld   ", quart);
        acc.Print();
    }
};
 
struct bottle {
    ratio salt, pepper;
    pente angle;
    void Print() {
        printf("b ");
        salt.Print();
        pepper.Print();
        angle.Print();
        printf("\n\n");
    }
};
 
set <pente> Pentes;
 
map <pente, int> Occurences;
 
int nbExacts = 0;
int nbPaires = 0;
int nbAct = 0;
bool isIn = false;
 
bottle Entree[MAX_NOEUDS];
 
bottle cible;
int nbRequetes;
 
bgint Pgcd(bgint a, bgint b) {
    if (b == 0)
    {
        return a;
    }
    return Pgcd(b, a % b);
}
 
ratio Simp(ratio a) {
    bgint d = Pgcd(max(a.num, - a.num), max(a.denom, - a.denom));
    d = max(d, -d);
    if (a.denom < 0)
    {
        a.num *= -1;
        a.denom *= -1;
    }
    return {a.num / d, a.denom / d};
}
 
ratio operator+(ratio const& a, ratio const& b) {
    return Simp({a.num * b.denom + b.num * a.denom, a.denom * b.denom});
}
 
ratio operator*(ratio const& a, ratio const& b) {
    return Simp({a.num * b.num, a.denom * b.denom});
}
 
ratio operator-(ratio const& a, ratio const& b) {
    return Simp({a.num * b.denom - b.num * a.denom, a.denom * b.denom});
}
 
bool operator>(ratio const& a, ratio const& b) {
    return a.num * b.denom > a.denom * b.num;
}
 
bool operator<(ratio const& a, ratio const& b) {
    return a.num * b.denom < a.denom * b.num;
}
 
bool operator<(pente const& a, pente const& b) {
    if (a.quart < b.quart)
    {
        return true;
    }
    if (a.quart > b.quart)
    {
        return false;
    }
    return a.acc > b.acc;
}
 
pente CalculePente(bottle a) {
    ratio h = a.salt - cible.salt;
    ratio v = a.pepper - cible.pepper;
    if (h.num == 0 && v.num == 0)
    {
        return {-1, {1, 1}};
    }
    if (h.num == 0)
    {
        if (v.num > 0)
        {
            return {0, {1, 0}};
        }
        return {2, {1, 0}};
    }
    if (v.num == 0)
    {
        if (h.num > 0)
        {
            return {1, {1, 0}};
        }
        return {3, {1, 0}};
    }
    if (h.num > 0 && v.num < 0)
    {
        v.num *= -1;
        return {1, Simp({h.num * v.denom, h.denom * v.num})};
    }
    if (h.num < 0 && v.num < 0)
    {
        h.num *= -1;
        v.num *= -1;
        return {2, Simp({v.num * h.denom, v.denom * h.num})};
    }
    if (h.num < 0 && v.num > 0)
    {
        h.num *= -1;
        return {3, Simp({h.num * v.denom, h.denom * v.num})};
    }
    return {0, Simp({v.num * h.denom, v.denom * h.num})};
}
 
bool IsOver180(pente a, pente b) {
    if (b < a)
    {
        //printf("666 ERROR\n");
        //a.Print();
        //b.Print();
        return !IsOver180(b, a);
    }
    else
    {
        //printf("noice\n");
    }
    if (b.quart - a.quart == 3)
    {
        return true;
    }
    if (b.quart - a.quart == 2 && b.acc < a.acc)
    {
        return true;
    }
    return false;
}
 
void CheckAllAngles() {
    bool t = true;
    set<pente>::iterator it;
    for (it = Pentes.begin(); it != Pentes.end(); it ++)
    {
    //    printf("%lld ", (*it).quart);
    }
    printf("\n");
    return;
    for (it = Pentes.begin(); it != Pentes.end(); it ++)
    {
        set<pente>::iterator next = it;
        next ++;
        if (next == Pentes.end())
        {
            next = Pentes.begin();
        }
        if (IsOver180(*it, *next))
        {
            t = false;
        }
    }
    isIn = t;
    return;
}
 
void Read() {
    int a, b, c;
    cin >> a >> b >> c;
    //scanf("%lld%lld%lld", &a, &b, &c);
    a = (bgint)a;
    b = (bgint)b;
    c = (bgint)c;
    cible.salt = Simp({a, a + b + c});
    cible.pepper = Simp({b, a + b + c});
    cin >> nbRequetes;
    //scanf("%lld", &nbRequetes);
    return;
}
 
void Add(bottle a) {
    pente act = a.angle;
    if (act.quart < 0)
    {
        nbExacts ++;
        return;
    }
    Occurences[act] ++;
    pente opp = {(act.quart + 2) % 4, act.acc};
    nbPaires += Occurences[opp];
    if (Occurences[act] == 1)
    {
        Pentes.insert(act);
        set<pente>::iterator nv = Pentes.find(act);
        set<pente>::iterator prev = nv;
        if (prev == Pentes.begin())
        {
            prev = Pentes.end();
        }
        prev --;
        set<pente>::iterator next = nv;
        next ++;
        if (next == Pentes.end())
        {
            next = Pentes.begin();
        }
        nbAct ++;
        if (IsOver180(*prev, *next))
        {
            isIn = true;
        }
        if (IsOver180(*prev, *nv))
        {
            isIn = false;
        }
        if (IsOver180(*nv, *next))
        {
            isIn = false;
        }
    }
    return;
}
 
void Delete(bottle a) {
    pente act = a.angle;
    if (act.quart < 0)
    {
        nbExacts --;
        return;
    }
    Occurences[act] --;
    pente opp = {(act.quart + 2) % 4, act.acc};
    nbPaires -= Occurences[opp];
    if (Occurences[act] == 0)
    {
        set<pente>::iterator nv = Pentes.find(act);
        set<pente>::iterator prev = nv;
        if (prev == Pentes.begin())
        {
            prev = Pentes.end();
        }
        prev --;
        set<pente>::iterator next = nv;
        next ++;
        if (next == Pentes.end())
        {
            next = Pentes.begin();
        }
        if (IsOver180(*prev, *nv))
        {
            isIn = true;
        }
        if (IsOver180(*nv, *next))
        {
            isIn = true;
        }
        Pentes.erase(nv);
        nbAct --;
        if (nbAct < 1)
        {
            return;
        }
        if (IsOver180(*prev, *next))
        {
            isIn = false;
        }
    }
    return;
}
 
int FindMin() {
    if (nbExacts > 0)
    {
        return 1;
    }
    if (nbPaires > 0)
    {
        return 2;
    }
    if (nbAct >= 3 && isIn)
    {
        return 3;
    }
    return 0;
}
 
void Solve() {
    int nb = 0;
    for (int i = 0; i < nbRequetes; i ++)
    {
        char c;
        //scanf(" %c", &c);
        cin >> c;
        if (c == 'A')
        {
            int a, b, c;
            //scanf("%lld%lld%lld", &a, &b, &c);
            cin >> a >> b >> c;
            a = (bgint)a;
            b = (bgint)b;
            c = (bgint)c;
            Entree[nb].salt = Simp({a, a + b + c});
            Entree[nb].pepper = Simp({b, a + b + c});
            Entree[nb].angle = CalculePente(Entree[nb]);
            Add(Entree[nb ++]);
        }
        if (c == 'R')
        {
            int a;
            //scanf("%lld", &a);
            cin >> a;
            Delete(Entree[a - 1]);
        }
        cout << FindMin() << '\n';
        //printf("%lld\n", FindMin());
    }
}
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Read();
    Solve();
    //PRINT();
    return 0;
}