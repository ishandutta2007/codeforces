#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

const ld eps = 1e-7;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifdef _FILE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n, k;
    cin >> n >> k;
    vi a(n), b(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }
    vector<vector<ld>> dp(n + 1, vector<ld>(k));
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j < k; j++) {
            if(i == 0) {
                dp[i][j] = 0;
                continue;
            }
            ll ama = a[i - 1] + j;
            ll amb = b[i - 1];
            dp[i][j] = (ld)amb / k + ama / k + dp[i - 1][ama % k];
            for(int takea = 1; takea < min(a[i - 1] + 1, k); takea++) {
                int takeb = k - takea;
                if(takeb > amb) {
                    continue;
                }
                ll nowa = ama - takea;
                ll nowb = amb - takeb;
                dp[i][j] = max(dp[i][j], 1 + (ld)nowb / k + nowa / k + dp[i - 1][nowa % k]);
            }
        }
    }
    //cout << fixed << setprecision(10) << dp[n][0] << endl;
    ll ans = dp[n][0];
    if(abs(ans + 1 - dp[n][0]) < eps) {
        ++ans;
    }
    cout << ans;
}