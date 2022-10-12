#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
#include <map>
using namespace std;
#define prev prev228
#define all(x) (x).begin(), (x).end()

int n, m, k;
int dp[55][21000];
int a[55][21000];
int dpmaxL[55][21000];
int dpmaxR[55][21000];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++) cin >> a[i][j];
    }
    for (int i = 0; i + k <= m; i++)
    {
        for (int j = 0; j < k; j++)
        {
            dp[0][i] += a[0][i + j] + a[1][i + j];
        }
    }
    for (int i = m - 1; i >= 0; i--)
    {
        dpmaxR[0][i] = max(dpmaxR[0][i + 1], dp[0][i]);
    }
    for (int i = 0; i < m; i++)
    {
        if (i) dpmaxL[0][i] = max(dpmaxL[0][i - 1], dp[0][i]);
        else dpmaxL[0][i] = dp[0][i];
    }
    for (int i = 1; i < n; i++)
    {
        for (int w = 0; w + k <= m; w++)
        {
            int si = 0;
            for (int j = 0; j < k; j++) si += a[i][w + j] + a[i + 1][w + j];
            if (w - k >= 0) dp[i][w] = max(dp[i][w], dpmaxL[i - 1][w - k] + si);
            dp[i][w] = max(dp[i][w], dpmaxR[i - 1][w + k] + si);
            for (int j = max(0, w - k + 1); j < w + k; j++)
            {
                int inter = 0;
                for (int e = j; e < j + k; e++) if (w <= e && e < w + k) inter += a[i][e];
                dp[i][w] = max(dp[i][w], dp[i - 1][j] + si - inter);
            }
        }
        for (int j = m - 1; j >= 0; j--)
        {
            dpmaxR[i][j] = max(dpmaxR[i][j + 1], dp[i][j]);
        }
        for (int j = 0; j < m; j++)
        {
            if (j) dpmaxL[i][j] = max(dpmaxL[i][j - 1], dp[i][j]);
            else dpmaxL[i][j] = dp[i][j];
        }
    }
    cout << dpmaxL[n - 1][m - 1];
}