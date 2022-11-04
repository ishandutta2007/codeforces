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
    int n, m;
    cin >> n >> m;
    vvi pos(n);
    vi a;
    for(int i = 0; i < m; i++) {
        int val;
        cin >> val;
        --val;
        if(a.empty() || val != a[a.size() - 1]) {
            a.push_back(val);
        }
    }
    m = a.size();
    for(int i = 0; i < m; i++) {
        pos[a[i]].push_back(i);
    }
    if(m > 2 * n) {
        cout << 0;
        return 0;
    }
    vvi dp(m, vi(m, 0));
    for(int len = 1; len <= m; len++) {
        for(int l = 0; l < m + 1 - len; l++) {
            int r = l + len - 1;
            int mn = 10000;
            int mnid = -1;
            for(int i = l; i <= r; i++) {
                if(a[i] < mn) {
                    mn = a[i];
                    mnid = i;
                }
            }
            if(pos[mn][0] < l || pos[mn][pos[mn].size() - 1] > r) {
                dp[l][r] = 0;
                continue;
            }
            int ans = 1;
            for(int i = 0; i < (int)pos[mn].size() - 1; i++) {
                int l1 = pos[mn][i];
                int r1 = pos[mn][i + 1];
                if(l1 == r1 - 1) continue;
                ans = (ll)ans * dp[l1 + 1][r1 - 1] % mod;
            }
            int l1 = 0;
            int r1 = 0;
            mnid = pos[mn][0];
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
            mnid = pos[mn][pos[mn].size() - 1];
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
            ans = (ll)ans * l1 % mod;
            ans = (ll)ans * r1 % mod;
            dp[l][r] = ans;
            //cout << l << ' ' << r << ' ' << dp[l][r] << endl;
        }
    }
    cout << dp[0][m - 1];
}