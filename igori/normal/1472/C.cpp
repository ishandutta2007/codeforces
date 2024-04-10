#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int _ = 0; _ < t; _++)
    {
        int n;
        cin >> n;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        vector<int> dp(n + 1);
        for (int i = n; i > 0; i--)
            if (i + a[i] <= n) dp[i] = dp[i + a[i]] + a[i];
            else dp[i] = a[i];
        cout << *max_element(dp.begin(), dp.end()) << "\n";
    }
}