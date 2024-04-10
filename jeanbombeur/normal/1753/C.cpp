#include <iostream>
#include <cstdio>
#include <vector>
#define int long long
using namespace std;

//  <|_|>

//  M. Broccoli

const int MOD = (998244353);
const int MAX_VALUES = (2e5 + 1);

int Val[MAX_VALUES];

int Fact[MAX_VALUES];
int InvFact[MAX_VALUES];

int nbValues;

int Exp(int a, int n = MOD - 2) {
    int ans = 1, cur = a;
    for (; n; n >>= 1, cur = (cur * cur) % MOD)
        if (n & 1)
            ans = (ans * cur) % MOD;
    return ans;
}

void Read() {
    scanf("%lld", &nbValues);
    int sum = nbValues;
    for (int i = 0; i < nbValues; i ++)
    {
        scanf("%lld", &Val[i]);
        sum -= Val[i];
    }
    int nb = 0;
    for (int i = 0; i < sum; i ++)
    {
        nb += Val[i];
    }
    Fact[0] = 1;
    for (int i = 1; i <= nb; i ++)
    {
        Fact[i] = (i * Fact[i - 1]) % MOD;
    }
    InvFact[nb] = Exp(Fact[nb]);
    for (int i = nb - 1; i >= 0; i --)
    {
        InvFact[i] = ((i + 1) * InvFact[i + 1]) % MOD;
    }
    int ans = 0;
    for (int i = 1; i <= nb; i ++)
    {
        int inv = (Fact[i - 1] * InvFact[i]) % MOD;
        ans += (inv * inv) % MOD;
        ans %= MOD;
    }
    ans = (ans * nbValues) % MOD;
    ans = (ans * (nbValues - 1)) % MOD;
    ans = (ans * Exp(2)) % MOD;
    printf("%lld\n", ans);
    return;
}

signed main() {
    int nbTests = 1;
    scanf("%lld", &nbTests);
    while (nbTests --)
    {
        Read();
    }
    return 0;
}