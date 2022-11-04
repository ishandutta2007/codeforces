#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifdef _FILE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<vector<int>> dp(n + 1, vector<int>(n + 1));
        for(int i = n - 1; i >= 0; i--)
        {
            for(int j = n - 1; j >= 0; j--)
            {
                if(s[i] != s[j])
                {
                    continue;
                }
                dp[i][j] = 1 + dp[i + 1][j + 1];
            }
        }
        int result = n;
        vector<int> ans(n);
        ans[0] = n;
        for(int i = 1; i < n; i++)
        {
            ans[i] = n - i;
            for(int j = i - 1; j >= 0; j--)
            {
                int lcp = dp[i][j];
                int a = i + lcp;
                int b = j + lcp;
                if(a >= n || s[a] < s[b])
                {
                    continue;
                }
                ans[i] = max(ans[i], ans[j] + (n - i - lcp));
            }
            result = max(result, ans[i]);
        }
        cout << result << '\n';
    }
}