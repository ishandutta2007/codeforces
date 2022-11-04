#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
int dp[401][401][401];


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifdef _FILE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n, m;
    cin >> n >> m;
    vi a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int l = n - 1; l >= 0; l--) {
        for(int am = 0; am <= n; am++) {
            int now = l;
            for(int r = l; r < n; r++) {
                if(am == 0) {
                    dp[l][r][am] = a[r] - a[l];
                    continue;
                }
                int valnow = max(a[now] - a[l], dp[now][r][am - 1]);
                while(now < r && max(a[now + 1] - a[l], dp[now + 1][r][am - 1]) < valnow) {
                    valnow = max(a[now + 1] - a[l], dp[now + 1][r][am - 1]);
                    ++now;
                }
                dp[l][r][am] = valnow;
            }
        }
    }
    ll ans = 0;
    for(int i = 0; i < m; i++) {
        int s, f, c, r;
        cin >> s >> f >> c >> r;
        --s;
        --f;
        ans = max(ans, (ll)dp[s][f][r] * c);
    }
    cout << ans;
}