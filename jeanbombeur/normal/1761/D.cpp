#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

//  <|_|>

//  M. Broccoli

const int MOD = (1e9 + 7);
const int MAX_VALUES = (1e6 + 1);

int Fact[MAX_VALUES];
int InvFact[MAX_VALUES];

int Powers[MAX_VALUES];

int nbValues, nbCarries;

int fast_expo(int a, int n = MOD - 2, int m = MOD) {
    int ans = 1, cur = a;
    for (; n; n >>= 1, cur = (cur * cur) % m)
        if (n & 1)
            ans = (ans * cur) % m;
    return ans;
}

int Choose(int k, int n) {
    return n < k ? 0 : (((Fact[n] * InvFact[k]) % MOD) * InvFact[n - k]) % MOD;
}

void Read() {
    scanf("%lld %lld", &nbValues, &nbCarries);
    Fact[0] = 1;
    Powers[0] = 1;
    for (int i = 1; i <= nbValues; i ++)
    {
        Fact[i] = (i * Fact[i - 1]) % MOD;
        Powers[i] = (3 * Powers[i - 1]) % MOD;
    }
    InvFact[nbValues] = fast_expo(Fact[nbValues]);
    for (int i = nbValues - 1; i >= 0; i --)
    {
        InvFact[i] = (InvFact[i + 1] * (i + 1)) % MOD;
    }
    if (nbCarries == 0)
    {
        printf("%lld\n", fast_expo(3, nbValues));
        return;
    }
    int ans = 0;
    for (int nbBlocs = 1; nbBlocs <= nbCarries; nbBlocs ++)
    {
        int nbSplit = Choose(nbBlocs - 1, nbCarries - 1);
        int add = 0;
        if (nbValues >= nbCarries + nbBlocs)
            add += Choose(nbBlocs, nbValues - nbCarries) * Powers[nbValues - 2 * nbBlocs];
        add %= MOD;
        if (nbValues >= nbBlocs + nbCarries - 1)
            add += Choose(nbBlocs - 1, nbValues - nbCarries) * Powers[nbValues + 1 - 2 * nbBlocs];
        add %= MOD;
        ans = (ans + add * nbSplit) % MOD;
    }
    printf("%lld\n", ans);
    return;
}

signed main() {
    int nbTests = 1;
    // scanf("%lld", &nbTests);
    while (nbTests --)
    {
        Read();
    }
    return 0;
}