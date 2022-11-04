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
    int n;
    cin >> n >> n;
    vi a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vvi dp(n, vi(n, 0));
    for(int len = 1; len <= n; len++) {
        for(int l = 0; l < n - len + 1; l++) {
            int r = l + len - 1;
            int mnid = -1;
            int mn = 1000;
            for(int i = l; i <= r; i++) {
                if(mn > a[i]) {
                    mn = a[i];
                    mnid = i;
                }
            }
            int l1 = 0;
            for(int i = l; i <= mnid; i++) {
                int lhere = 1;
                int rhere = 1;
                if(i != l) {
                    lhere = dp[l][i - 1];
                }
                if(i != mnid) {
                    rhere = dp[i][mnid - 1];
                }
                l1 = (l1 + (ll)lhere * rhere) % mod;
            }
            int r1 = 0;
            for(int i = mnid; i <= r; i++) {
                int lhere = 1;
                int rhere = 1;
                if(i != mnid) {
                    lhere = dp[mnid + 1][i];
                }
                if(i != r) {
                    rhere = dp[i + 1][r];
                }
                r1 = (r1 + (ll)lhere * rhere) % mod;
            }
            dp[l][r] = (ll)l1 * r1 % mod;
            //cout << l << ' ' << r << ' ' << dp[l][r] << endl;
        }
    }
    cout << dp[0][n - 1];
}