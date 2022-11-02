#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#define int long long
using namespace std;

//  <|_|>

//  The hardest choices require the strongest wills
//  We must be better

const int MOD = (998244353);
const int MAX_PORTAILS = (300 * 1000);

set <pair <int, int>> Positions;

int Fenwick[MAX_PORTAILS];

int Pos[MAX_PORTAILS];
int Teleporte[MAX_PORTAILS];

int State[MAX_PORTAILS];

int DP[MAX_PORTAILS];

int nbPortails;

void Add(int a, int d) {
    for (int i = a; i < MAX_PORTAILS; i |= (i + 1))
    {
        Fenwick[i] += d;
        Fenwick[i] %= MOD;
    }
    return;
}

int GetSum(int a) {
    int ans = 0;
    for (int i = a; i > 0; i &= (i - 1))
    {
        ans += Fenwick[i - 1];
    }
    return ans % MOD;
}

void Read() {
    scanf("%lld", &nbPortails);
    for (int i = 0; i < nbPortails; i ++)
    {
        scanf("%lld %lld %lld", &Pos[i], &Teleporte[i], &State[i]);
        Positions.insert({Pos[i], i});
    }
    for (int i = 0; i < nbPortails; i ++)
    {
        int next = (*Positions.lower_bound({Teleporte[i], 0})).second;
        DP[i] = GetSum(i) - GetSum(next) + Pos[i] - Teleporte[i];
        DP[i] %= MOD;
        if (DP[i] < 0)
            DP[i] += MOD;
        Add(i, DP[i]);
    }
    int ans = (Pos[nbPortails - 1] + 1) % MOD;
    for (int i = 0; i < nbPortails; i ++)
    {
        ans += DP[i] * State[i];
        ans %= MOD;
    }
    printf("%lld\n", ans % MOD);
    return;
}

signed main() {
    Read();
    return 0;
}