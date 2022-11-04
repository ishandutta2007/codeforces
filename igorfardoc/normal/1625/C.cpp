#include<bits/stdc++.h>
#define inf 2000000000
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifdef _FILE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n, l, k;
    cin >> n >> l >> k;
    vi d(n);
    vi a(n);
    for(int i = 0; i < n; i++) {
        cin >> d[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    d.push_back(l);
    a.push_back(0);
    vvi dp(n, vi(k + 1, inf));
    for(int i = n - 1; i >= 0; i--) {
        for(int j = 0; j <= k; j++) {
            int now = 0;
            for(int k1 = i + 1; k1 <= n; k1++) {
                now += (d[k1] - d[k1 - 1]) * a[i];
                int minus = k1 - i - 1;
                if(minus > j) break;
                if(k1 == n) {
                    dp[i][j] = min(dp[i][j], now);
                    continue;
                }
                dp[i][j] = min(dp[i][j], dp[k1][j - minus] + now);
            }
        }
    }
    cout << dp[0][k];
}