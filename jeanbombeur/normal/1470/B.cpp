#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#define int long long
using namespace std;

//    <|_|>

const int MAX_VALEURS = (300 * 1000);

const int MAX_PREMIERS = (1000 * 1000);

vector <int> Premiers;

bool IsPrime[MAX_PREMIERS];

int Val[MAX_VALEURS];

int Occ[MAX_PREMIERS + 1];

int nbValeurs, nbRequetes;

void FindPremiers() {
    IsPrime[0] = true;
    IsPrime[1] = true;
    for (int i = 2; i < MAX_PREMIERS; i ++)
    {
        if (!IsPrime[i])
        {
            Premiers.push_back(i);
            for (int j = 2 * i; j < MAX_PREMIERS; j += i)
            {
                IsPrime[j] = true;
            }
        }
    }
    return;
}

int Treat(int a) {
    int act = a;
    int cur = 0;
    while (act > 1)
    {
        int carre = Premiers[cur] * Premiers[cur];
        if (carre > act)
        {
            return act;
        }
        while (act % carre == 0)
        {
            act /= carre;
        }
        cur ++;
    }
    return act;
}

void Read() {
    scanf("%lld", &nbValeurs);
    for (int i = 0; i < nbValeurs; i ++)
    {
        scanf("%lld", &Val[i]);
        Val[i] = Treat(Val[i]);
        Occ[Val[i]] ++;
    }
    int maxi = 0;
    int nb = Occ[1];
    for (int i = 0; i < nbValeurs; i ++)
    {
        maxi = max(maxi, Occ[Val[i]]);
        if (Val[i] != 1 && Occ[Val[i]] % 2 == 0)
        {
            nb += Occ[Val[i]];
        }
        Occ[Val[i]] = 0;
    }
    scanf("%lld", &nbRequetes);
    for (int i = 0; i < nbRequetes; i ++)
    {
        int a;
        scanf("%lld", &a);
        if (a == 0)
        {
            printf("%lld\n", maxi);
        }
        else
        {
            printf("%lld\n", max(maxi, nb));
        }
    }
    return;
}

signed main() {
    FindPremiers();
    int nbTests;
    scanf("%lld", &nbTests);
    for (int i = 0; i < nbTests; i ++)
    {
        Read();
    }
    return 0;
}