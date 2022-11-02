#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#define int long long
using namespace std;

//  <|_|>

//  Ah shit, here we go again

const int MAX_VALEURS = (200 * 1000);

int Val[MAX_VALEURS];
vector <int> Occ[MAX_VALEURS];
int Couleur[MAX_VALEURS];

set <pair <int, int>> ToGet;

int nbValeurs, nbCouleurs;

void Solve() {
    scanf("%lld %lld", &nbValeurs, &nbCouleurs);
    int nbLibres = 0;
    for (int i = 0; i < nbValeurs; i ++)
    {
        Occ[i].clear();
    }
    for (int i = 0; i < nbValeurs; i ++)
    {
        scanf("%lld", &Val[i]);
        Occ[-- Val[i]].push_back(i);
    }
    for (int i = 0; i < nbValeurs; i ++)
    {
        if ((int)Occ[i].size() > nbCouleurs)
            Occ[i].resize(nbCouleurs);
        nbLibres += Occ[i].size();
        Couleur[i] = 0;
    }
    ToGet.clear();
    int ans = nbLibres / nbCouleurs;
    for (int i = 0; i < nbCouleurs; i ++)
    {
        ToGet.insert({ans, i + 1});
    }
    for (int i = 0; i < nbValeurs; i ++)
    {
        vector <pair <int, int>> old;
        for (int j = 0; j < (int)Occ[i].size(); j ++)
        {
            if (!ToGet.empty())
            {
                old.push_back(*(-- ToGet.end()));
                Couleur[Occ[i][j]] = (*(-- ToGet.end())).second;
                ToGet.erase(-- ToGet.end());
            }
        }
        for (pair <int, int> a : old)
        {
            if (a.first > 1)
                ToGet.insert({a.first - 1, a.second});
        }
    }
    for (int i = 0; i < nbValeurs; i ++)
    {
        printf("%lld ", Couleur[i]);
    }
    printf("\n");
    return;
}

signed main() {
    int nbTests = 1;
    scanf("%lld", &nbTests);
    while (nbTests --)
    {
        Solve();
    }
    return 0;
}