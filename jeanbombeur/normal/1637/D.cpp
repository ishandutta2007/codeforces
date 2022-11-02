#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

//  <|_|>

// Finally

const int MAX_VALUES = (2e5);
const int MAX_SUM = (2e4);

bool DP[2][2 * MAX_SUM];

int Val[2][MAX_VALUES];

int nbValues;

void Solve() {
    int sumSquares = 0;
    int sum = 0;
    scanf("%lld", &nbValues);
    fill_n(DP[0], 2 * MAX_SUM, false);
    DP[0][MAX_SUM] = true;
    for (int k = 0; k < 2; k ++)
    {
        for (int i = 0; i < nbValues; i ++)
        {
            scanf("%lld", &Val[k][i]);
            sumSquares += Val[k][i] * Val[k][i];
            sum += Val[k][i];
        }
    }
    for (int i = 0; i < nbValues; i ++)
    {
        int cur = abs(Val[0][i] - Val[1][i]);
        for (int j = cur; j < 2 * MAX_SUM - cur; j ++)
        {
            if (DP[0][j])
            {
                DP[1][j + cur] = true;
                DP[1][j - cur] = true;
            }
        }
        for (int j = 0; j < 2 * MAX_SUM; j ++)
        {
            DP[0][j] = DP[1][j];
        }
        fill_n(DP[1], 2 * MAX_SUM, false);
    }
    int minimum = MAX_SUM;
    for (int i = 0; i < 2 * MAX_SUM; i ++)
    {
        if (DP[0][i])
            minimum = min(minimum, abs(i - MAX_SUM));
    }
    int ans = (nbValues - 2) * sumSquares + (sum * sum + minimum * minimum) / 2;
    printf("%lld\n", ans);
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