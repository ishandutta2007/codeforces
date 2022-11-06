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
    int n;
    cin >> n;
    vector<vector<pair<int, int>>> a(n);
    for(int i = 0; i < n; i++) {
        int k;
        cin >> k;
        a[i].resize(k);
        for(int j = 0; j < k; j++) {
            int c, d;
            cin >> c >> d;
            a[i][j] = {d, c};
        }
    }
    for(int i = 0; i < n; i++) {
        vector<multiset<int, greater<int>>> c(4);
        for(int j = 0; j < a[i].size(); j++) {
            c[a[i][j].second].insert(a[i][j].first);
        }
        vector<pair<int, int>> here;
        for(int i = 1; i <= 3; i++) {
            auto it = c[i].begin();
            for(int j = 0; it != c[i].end() && j < 3 / i; j++, it++) {
                here.push_back({*it, i});
            }
        }
        a[i] = here;
    }
    vector<vector<ll>> dp(n + 1, vector<ll>(10, 0));
    for(int i = n - 1; i >= 0; i--) {
        for(int j = 0; j < 10; j++) {
            dp[i][j] = dp[i + 1][j];
            // 1
            for(int k = 0; k < a[i].size(); k++) {
                int sum = a[i][k].first;
                if(j == 9) {
                    dp[i][j] = max(dp[i][j], 2 * sum + dp[i + 1][(j + 1) % 10]);
                } else {
                    dp[i][j] = max(dp[i][j], sum + dp[i + 1][(j + 1) % 10]);
                }
            }
            // 2
            for(int k = 0; k < a[i].size(); k++) {
                for(int l = k + 1; l < a[i].size(); l++) {
                    ll sum = (ll)a[i][k].first + a[i][l].first;
                    int c = a[i][k].second + a[i][l].second;
                    int mx = max(a[i][k].first, a[i][l].first);
                    if(c > 3) {
                        continue;
                    }
                    if(j > 7) {
                        dp[i][j] = max(dp[i][j], sum + mx + dp[i + 1][(j + 2) % 10]);
                    } else {
                        dp[i][j] = max(dp[i][j], sum + dp[i + 1][(j + 2) % 10]);
                    }
                }
            }
            // 3
            for(int k = 0; k < a[i].size(); k++) {
                for(int l = k + 1; l < a[i].size(); l++) {
                    for(int g = l + 1; g < a[i].size(); g++) {
                        ll sum = (ll)a[i][k].first + a[i][l].first + a[i][g].first;
                        int c = a[i][k].second + a[i][l].second + a[i][g].second;
                        int mx = max(a[i][k].first, max(a[i][l].first, a[i][g].first));
                        if(c > 3) {
                            continue;
                        }
                        if(j > 6) {
                            dp[i][j] = max(dp[i][j], sum + mx + dp[i + 1][(j + 3) % 10]);
                        } else {
                            dp[i][j] = max(dp[i][j], sum + dp[i + 1][(j + 3) % 10]);
                        }
                    }
                }
            }
        }
    }
    cout << dp[0][0];
}