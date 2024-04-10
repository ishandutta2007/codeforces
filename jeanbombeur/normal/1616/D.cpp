#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

//  <|_|>

//

const int MAX_VALUES = (2e5);

int Val[MAX_VALUES];

int DP[MAX_VALUES][4];
int Best[MAX_VALUES];

int nbValues, medium;

void Solve() {
    scanf("%lld", &nbValues);
    for (int i = 1; i <= nbValues; i ++)
    {
        scanf("%lld", &Val[i]);
        DP[i][0] = DP[i][1] = DP[i][2] = DP[i][3] = 0;
        Best[i] = 0;
    }
    Val[0] = (1 << 30);
    scanf("%lld", &medium);
    for (int i = 1; i <= nbValues; i ++)
    {
        Val[i] -= medium;
    }
    DP[1][1] = 1;
    Best[1] = 1;
    for (int i = 2; i <= nbValues; i ++)
    {
        DP[i][0] = Best[i - 2];
        DP[i][1] = Best[i - 2] + 1;
        DP[i][2] = max(DP[i - 1][1], DP[i - 1][3]);
        if (Val[i] + Val[i - 1] >= 0)
        {
            DP[i][3] = DP[i - 1][1] + 1;
            if (Val[i] + Val[i - 1] + Val[i - 2] >= 0)
                DP[i][3] = max(DP[i][3], DP[i - 1][3] + 1);
        }
        for (int j = 0; j < 4; j ++)
            Best[i] = max(Best[i], DP[i][j]);
    }
    printf("%lld\n", Best[nbValues]);
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