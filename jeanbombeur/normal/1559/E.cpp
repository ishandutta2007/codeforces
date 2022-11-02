#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

//  <|_|>

//  I'm Batman

const int MOD = (998244353);
const int MAX_VALEURS = (200 * 1000);
const int MAX_ETOILES = (50);

int Ans[MAX_VALEURS];

int DP[MAX_VALEURS];

pair <int, int> Bornes[MAX_ETOILES];

int nbEtoiles, borneSup;

int FindDP(int d) {
    int borne = borneSup / d;
    fill_n(DP + 1, borne, 0LL);
    DP[0] = 1;
    for (int i = 0; i < nbEtoiles; i ++)
    {
        int sum = 0;
        int inf = (Bornes[i].first + d - 1) / d, sup = Bornes[i].second / d;
        for (int j = inf; j <= sup; j ++)
        {
            sum += DP[borne - j];
        }
        sum %= MOD;
        for (int j = borne; j >= 0; j --)
        {
            DP[j] = sum;
            if (j >= inf)
                sum -= DP[j - inf];
            if (j > sup)
                sum += DP[j - sup - 1];
            sum %= MOD;
            if (sum < 0)
                sum += MOD;
        }
    }
    int ans = 0;
    for (int i = 0; i <= borne; i ++)
    {
        ans += DP[i];
    }
    return ans % MOD;
}

void Solve() {
    scanf("%lld %lld", &nbEtoiles, &borneSup);
    for (int i = 0; i < nbEtoiles; i ++)
    {
        scanf("%lld %lld", &Bornes[i].first, &Bornes[i].second);
    }
    for (int i = 1; i <= borneSup; i ++)
    {
        Ans[i] = FindDP(i);
    }
    for (int i = borneSup; i > 0; i --)
    {
        for (int j = 2 * i; j <= borneSup; j += i)
        {
            Ans[i] -= Ans[j];
        }
        Ans[i] %= MOD;
        if (Ans[i] < 0)
            Ans[i] += MOD;
    }
    printf("%lld\n", Ans[1]);
    return;
}

signed main() {
    int nbTests = 1;
    // scanf("%lld", &nbTests);
    while (nbTests --)
    {
        Solve();
    }
    return 0;
}