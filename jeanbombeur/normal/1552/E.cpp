#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#define int long long
using namespace std;

//  <|_|>

//  The hardest choices require the strongest wills
//  We must be better

const int MAX_VALEURS = (100);

int Couleur[MAX_VALEURS * MAX_VALEURS];

int Last[MAX_VALEURS];

int Count[MAX_VALEURS];

bool Pris[MAX_VALEURS];

pair <int, int> Ans[MAX_VALEURS];

int nbCouleurs, nbDeChaque;

void Read() {
    scanf("%lld%lld", &nbCouleurs, &nbDeChaque);
    int nbCases = nbCouleurs * nbDeChaque;
    for (int i = 0; i < nbCases; i ++)
    {
        scanf("%lld", &Couleur[i]);
        Couleur[i] --;
    }
    int nbPris = 0;
    while (nbPris < nbCouleurs)
    {
        fill_n(Count, nbCouleurs, 0);
        int cur = 0;
        while (cur < nbCases)
        {
            if (!Pris[Couleur[cur]] && ++ Count[Couleur[cur]] >= 2)
            {
                Ans[Couleur[cur]] = {Last[Couleur[cur]] + 1, cur + 1};
                Pris[Couleur[cur]] = true;
                nbPris ++;
                fill_n(Count, nbCouleurs, 0);
            }
            Last[Couleur[cur]] = cur;
            cur ++;
        }
    }
    for (int i = 0; i < nbCouleurs; i ++)
    {
        printf("%lld %lld\n", Ans[i].first, Ans[i].second);
    }
    return;
}

signed main() {
    int nbTests = 1;
    // scanf("%lld", &nbTests);
    for (int i = 0; i < nbTests; i ++)
    {
        Read();
    }
    return 0;
}