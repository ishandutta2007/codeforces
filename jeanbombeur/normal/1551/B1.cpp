#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#define int long long
using namespace std;

//  <|_|>

//  Ah shit, here we go again

const int MAX_VALEURS = (200 * 1000);

char Val[MAX_VALEURS];
int Occ[MAX_VALEURS];

int nbValeurs, nbCouleurs;

void Solve() {
    scanf("%s", Val);
    nbValeurs = strlen(Val);
    nbCouleurs = 2;
    int nbLibres = 0;
    fill_n(Occ, 26, 0LL);
    for (int i = 0; i < nbValeurs; i ++)
    {
        Occ[Val[i] - 'a'] ++;
    }
    for (int i = 0; i < 26; i ++)
    {
        nbLibres += min(2LL, Occ[i]);
    }
    printf("%lld\n", nbLibres / 2);
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