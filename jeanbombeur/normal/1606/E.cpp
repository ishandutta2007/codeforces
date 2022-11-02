#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

//  <|_|>

//  xiao xiao

const int MOD = (998244353);
const int MAX_HEROES = (501);

int DP[MAX_HEROES][MAX_HEROES];

int Fact[MAX_HEROES];
int InvFact[MAX_HEROES];

int nbHeroes, maxLife;

inline int fast_expo(int a, int n, int m) {
    int ans = 1, cur = a;
    for (; n; n >>= 1, cur = (cur * cur) % m)
        if (n & 1)
            ans = (ans * cur) % m;
    return ans;
}

int Choose(int n, int k) {
    return (Fact[n] * ((InvFact[k] * InvFact[n - k]) % MOD)) % MOD;
}

void Solve() {
    scanf("%lld %lld", &nbHeroes, &maxLife);
    DP[0][0] = 1;
    Fact[0] = 1;
    for (int i = 1; i < MAX_HEROES; i ++)
    {
        Fact[i] = (Fact[i - 1] * i) % MOD;
    }
    InvFact[MAX_HEROES - 1] = fast_expo(Fact[MAX_HEROES - 1], MOD - 2, MOD);
    for (int i = MAX_HEROES - 2; i >= 0; i --)
    {
        InvFact[i] = (InvFact[i + 1] * (i + 1)) % MOD;
    }
    for (int l = 1; l <= maxLife; l ++)
    {
        for (int n = 1; n <= nbHeroes; n ++)
        {
            for (int k = 0; k < n - 1; k ++)
            {
                DP[n][l] += ((DP[n - k][max(0LL, l - n + 1)] * fast_expo(min(n - 1, l), k, MOD) % MOD) * Choose(n, k)) % MOD;
            }
            if (n > 1)
                DP[n][l] += fast_expo(min(n - 1, l), n, MOD);
            DP[n][l] %= MOD;
        }
    }
    printf("%lld\n", DP[nbHeroes][maxLife]);
    return;
}

signed main() {
    int nbTests = 1;
    // scanf("%lld", &nbTests);
    while (nbTests --)
        Solve();
    return 0;
}