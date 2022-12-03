#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

//  <|_|>

//  M. Broccoli

const int MAX_VALUES = (1e5);

int Fact[MAX_VALUES];

int InvFact[MAX_VALUES];

int nbPoints, MOD;

int fast_expo(int a, int n, int m) {
    int ans = 1, cur = a;
    for (; n; n >>= 1, cur = (cur * cur) % m)
        if (n & 1)
            ans = (ans * cur) % m;
    return ans;
}

int Choose(int k, int n) {
    return k > n ? 0 : (((Fact[n] * InvFact[k]) % MOD) * InvFact[n - k]) % MOD;
}

void Read() {
    scanf("%lld %lld", &nbPoints, &MOD);
    Fact[0] = 1;
    for (int i = 1; i <= nbPoints; i ++)
    {
        Fact[i] = (Fact[i - 1] * i) % MOD;
    }
    InvFact[nbPoints] = fast_expo(Fact[nbPoints], MOD - 2, MOD);
    for (int i = nbPoints - 1; i >= 0; i --)
    {
        InvFact[i] = (InvFact[i + 1] * (i + 1)) % MOD;
    }
    int ans = 0;
    for (int d = 2; d <= (nbPoints + 1) / 2; d ++)
    {
        int sum = 0;
        for (int k = 0; k <= d - 2; k ++)
        {
            sum += Choose(k, d - 2) * Fact[nbPoints - 3 - k];
            sum %= MOD;
        }
        sum *= d - (nbPoints & 1);
        sum %= MOD;
        ans += sum;
    }
    if (!(nbPoints & 1))
        ans += Fact[nbPoints - 2];
    ans *= nbPoints;
    ans %= MOD;
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