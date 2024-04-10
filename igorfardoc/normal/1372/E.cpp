#include<bits/stdc++.h>
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
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> a(n, vector<pair<int, int>>(m));
    for(int i = 0; i < n; i++) {
        int k;
        cin >> k;
        for(int j = 0; j < k; j++) {
            int l, r;
            cin >> l >> r;
            --l;
            --r;
            for(int h = l; h <= r; h++) {
                a[i][h] = {l, r};
            }
        }
    }
    vvi dp(m, vi(m));
    for(int len = 1; len <= m; len++) {
        for(int l = 0; l < m - len + 1; l++) {
            int r = l + len - 1;
            dp[l][r] = 0;
            for(int c = l; c <= r; c++) {
                int here = 0;
                if(c != l) {
                    here += dp[l][c - 1];
                }
                if(c != r) {
                    here += dp[c + 1][r];
                }
                int ans = 0;
                for(int i = 0; i < n; i++) {
                    if(a[i][c].first >= l && a[i][c].second <= r) {
                        ++ans;
                    }
                }
                here += ans * ans;
                dp[l][r] = max(dp[l][r], here);
            }
        }
    }
    cout << dp[0][m - 1]; 
}