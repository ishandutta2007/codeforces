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
const int NB_LETTRES = (5);

char Val[MAX_VALEURS];
int Delta[5][MAX_VALEURS];
int Occ[NB_LETTRES];

int nbMots;

void Solve() {
    scanf("%lld", &nbMots);
    for (int i = 0; i < nbMots; i ++)
    {
        scanf("%s", Val);
        int sz = strlen(Val);
        for (int j = 0; j < sz; j ++)
        {
            Occ[Val[j] - 'a'] ++;
        }
        for (int j = 0; j < NB_LETTRES; j ++)
        {
            Delta[j][i] = sz - 2 * Occ[j];
            Occ[j] = 0;
        }
    }
    int maxi = 0;
    for (int i = 0; i < NB_LETTRES; i ++)
    {
        sort(Delta[i], Delta[i] + nbMots);
        int sum = Delta[i][0];
        int cur = 1;
        while (cur < nbMots && sum < 0)
            sum += Delta[i][cur ++];
        if (sum >= 0)
            cur --;
        maxi = max(maxi, cur);
    }
    printf("%lld\n", maxi);
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