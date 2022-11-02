#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

//  I've been looking forward to this

//  <|_|>

const int MOD = (1e9 + 7);
const int MAX_VALUES = (5e5);

int Val[MAX_VALUES];
int Fact[MAX_VALUES];
int InvFact[MAX_VALUES];

int nbValues;

int Exp(int a, int n) {
    int ans = 1, cur = a;
    for (; n; cur = (cur * cur) % MOD, n >>= 1)
    {
        if (n & 1)
            ans = (ans * cur) % MOD;
    }
    return ans;
}

int Choose(int k, int n) {
    return (((Fact[n] * InvFact[k]) % MOD) * InvFact[n - k]) % MOD;
}

void Solve() {
    scanf("%lld", &nbValues);
    int ans = 0;
    Fact[0] = 1;
    for (int i = 1; i < MAX_VALUES; i ++)
    {
        Fact[i] = (Fact[i - 1] * i) % MOD;
    }
    InvFact[MAX_VALUES - 1] = Exp(Fact[MAX_VALUES - 1], MOD - 2);
    for (int i = MAX_VALUES - 2; i >= 0; i --)
    {
        InvFact[i] = (InvFact[i + 1] * (i + 1)) % MOD;
    }
    for (int i = 0; i <= nbValues; i ++)
    {
        scanf("%lld", &Val[i]);
        if (Val[i] > 0)
            ans += Choose(i + 1, Val[i] + i);
    }
    printf("%lld\n", ((ans % MOD) + MOD) % MOD);
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