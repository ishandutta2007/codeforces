#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

//  <|_|>

//  It that's what it takes to save the world, it's better to let that world die

const int MAX_CASES = (4e6 + 1);

int MOD;

int DP[MAX_CASES];

void Solve() {
    int nbCases;
    scanf("%lld %lld", &nbCases, &MOD);
    int prefSum = 0;
    DP[1] = 1;
    DP[2] = -1;
    for (int i = 1; i <= nbCases; i ++)
    {
        prefSum += DP[i];
        prefSum %= MOD;
        if (prefSum < 0)
            prefSum += MOD;
        int ans = prefSum;
        prefSum += ans;
        for (int d = 2; d * i < MAX_CASES; d ++)
        {
            DP[d * i] += ans;
            if (DP[d * i] >= MOD)
                DP[d * i] -= MOD;
            if (d * (i + 1) < MAX_CASES)
            {
                DP[d * (i + 1)] -= ans;
                if (DP[d * (i + 1)] < 0)
                    DP[d * (i + 1)] += MOD;
            }
        }
        if (i == nbCases)
            printf("%lld\n", ans);
    }
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