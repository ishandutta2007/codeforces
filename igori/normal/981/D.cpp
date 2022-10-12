#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    long long ans = 0;
    for (int b = 55; b >= 0; b--)
    {
        long long req = ans + (1ll << b);
        vector<vector<long long> > dp(n + 1, vector<long long>(k + 1));
        dp[0][0] = 1;
        for (int i = 0; i < n; i++)
        {
            long long cur = 0;
            for (int j = i; j < n; j++)
            {
                 cur += a[j];
                 if ((cur & req) == req)
                 {
                     for (int jo = 0; jo < k; jo++)
                        if (dp[i][jo]) dp[j + 1][jo + 1] = 1;
                 }
            }
        }
        if (dp[n][k])
            ans = req;
    }
    cout << ans << "\n";
}