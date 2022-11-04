#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
const int mod = 998244353;



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifdef _FILE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n, k, len;
    cin >> n >> k >> len;
    vi a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        --a[i];
    }
    vvi dp(n + 1, vi(k, 0));
    vi dp1(n + 1, 0);
    dp1[0] = 1;
    vi am(k + 2, 0);
    for(int i = 1; i <= n; i++) {
        ++am[a[i - 1] + 2];
        if(i > len) {
            --am[a[i - 1 - len] + 2];
        }
        for(int j = 0; j < k; j++) {
            if(a[i - 1] != -2 && a[i - 1] != j) continue;
            dp[i][j] = dp1[i - 1];
            if(am[j + 2] + am[0] == len) {
                dp[i][j] = ((ll)dp[i][j] - dp1[i - len] + dp[i - len][j] + mod) % mod;
            }
            dp1[i] = (dp1[i] + dp[i][j]) % mod;
        }
    }
    cout << dp1[n];
}