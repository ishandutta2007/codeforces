#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

//  <|_|>

//  Hello there

const int MOD = (1e9 + 7);
const int MAX_TEAMS = (14);
const int MAX_MASK = (5e6);

int Powers[MAX_TEAMS + 1];

int Strenght[MAX_TEAMS];

int Proba[MAX_TEAMS][MAX_TEAMS];

int ProbaMask[MAX_MASK];

int Transpo[1 << MAX_TEAMS];

int DP[1 << MAX_TEAMS];

int nbTeams;

int GetBit(int mask, int index) {
    return (mask / Powers[index]) % 3;
}

int fast_expo(int a, int n) {
    int ans = 1, cur = a;
    for (; n > 0; n >>= 1, cur = (cur * cur) % MOD)
    {
        if (n & 1)
            ans = (ans * cur) % MOD;
    }
    return ans;
}

void Solve() {
    scanf("%lld", &nbTeams);
    Powers[0] = 1;
    for (int i = 0; i < nbTeams; i ++)
    {
        scanf("%lld", &Strenght[i]);
        Powers[i + 1] = 3 * Powers[i];
    }
    int nbMasks = Powers[nbTeams];
    for (int i = 0; i < nbTeams; i ++)
    {
        for (int j = 0; j < nbTeams; j ++)
        {
            Proba[i][j] = Strenght[i] * fast_expo(Strenght[i] + Strenght[j], MOD - 2);
            Proba[i][j] %= MOD;
        }
    }
    for (int m = 0; m < (1 << nbTeams); m ++)
    {
        for (int j = 0; j < nbTeams; j ++)
        {
            if ((m >> j) & 1)
                Transpo[m] += Powers[j];
        }
    }
    ProbaMask[nbMasks - 1] = 1;
    for (int m = nbMasks - 2; m >= 0; m --)
    {
        int in = 0;
        for (int i = 0; i < nbTeams; i ++)
        {
            if (GetBit(m, i) < 2)
                in = i;
        }
        ProbaMask[m] = ProbaMask[m + (2 - GetBit(m, in)) * Powers[in]];
        for (int i = 0; i < nbTeams; i ++)
        {
            if (GetBit(m, in) == 1 && GetBit(m, i) == 0)
            {
                ProbaMask[m] *= Proba[i][in];
                ProbaMask[m] %= MOD;
            }
            if (GetBit(m, in) == 0 && GetBit(m, i) == 1)
            {
                ProbaMask[m] *= Proba[in][i];
                ProbaMask[m] %= MOD;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < nbTeams; i ++)
    {
        fill_n(DP, 1 << nbTeams, 0);
        for (int mask = 1 << i; mask < (1 << nbTeams); mask = (mask + 1) | (1 << i))
        {
            int newMask = Transpo[mask];
            DP[mask] = ProbaMask[newMask];
            for (int m = (mask - 1) & mask; m > 0; m = (m - 1) & mask)
            {
                if (!((m >> i) & 1))
                    continue;
                DP[mask] -= DP[m] * ProbaMask[newMask + Transpo[m]];
                DP[mask] %= MOD;
            }
            if (DP[mask] < 0)
                DP[mask] += MOD;
        }
        ans += DP[(1 << nbTeams) - 1];
    }
    printf("%lld\n", ans % MOD);
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