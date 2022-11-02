#include <iostream>
#include <cstdio>
#define int long long
using namespace std;

//  <|_|>

//  Ah shit, here we go again

const int MAX_VALEURS = (200 * 1000);

int Val[MAX_VALEURS];

int DP[MAX_VALEURS];

int nbValeurs, nbFixes;

void Solve() {
    scanf("%lld %lld", &nbValeurs, &nbFixes);
    fill_n(DP, nbValeurs, - (1 << 30));
    DP[0] = 0;
    for (int i = 0; i < nbValeurs; i ++)
    {
        scanf("%lld", &Val[i]);
        Val[i] = (i + 1) - Val[i];
        int newVal = 0;
        if (Val[i] >= 0)
            newVal = DP[Val[i]] + 1;
        for (int j = nbValeurs - 1; j > 0; j --)
        {
            DP[j] = max(DP[j], DP[j - 1]);
        }
        if (Val[i] >= 0)
            DP[Val[i]] = max(DP[Val[i]], newVal);
    }
    for (int i = 0; i < nbValeurs; i ++)
    {
        if (DP[i] >= nbFixes)
        {
            printf("%lld\n", i);
            return;
        }
    }
    printf("-1\n");
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