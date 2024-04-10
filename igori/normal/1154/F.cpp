#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, k;
long long a[500000];
long long x[500000];
long long y[500000];
long long dp[5000];
long long ps[5000];
long long segm[2040][2040];

int main()
{
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    for (int i = 0; i <= k; i++)
    {
        long long sm = 0;
        for (int j = i; j <= k; j++)
        {
            sm += a[j];
            segm[i][j] = sm;
        }
    }
    for (int i = 0; i < m; i++)
    {
        cin >> x[i] >> y[i];
    }
    long long int INF = 1e18;
    fill(dp, dp + k + 1, INF);
    dp[0] = 0;
    for (int i = 1; i <= k; i++)
    {
        for (int j = 0; j < m; j++)
        {
            long long s = i - x[j];
            long long pays = i - (x[j] - y[j]);
            if (s >= 0 && pays >= 0)
                dp[i] = min(dp[i], dp[s] + segm[pays][i - 1]);
        }
        dp[i] = min(dp[i], dp[i - 1] + a[i - 1]);
        //cout << dp[i] << endl;
    }
    cout << dp[k];
}