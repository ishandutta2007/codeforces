#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;

int main() {
    ios_base::sync_with_stdio(false);
    int n, m;
    ll k;
    cin >> n >> m >> k;
    mt19937_64 mt(time(nullptr));
    ll key = (mt() % 1'000'000'000'000'000'000LL) ^ 99824435304561LL;
    vector<vector<ll>> a(n, vector<ll>(m, 0));
    vector<vector<unordered_map<ll, int>>> dp(n, vector<unordered_map<ll, int>>(m));
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cin >> a[i][j];
        }
    }
    dp[0][0][a[0][0] ^ key] = 1;
    int z = min(n + m - 2, 19);
    for(int s = 0; s < z; ++s){
        for(int i = max(0, s - m + 1); i < n && i <= s; ++i){
            int j = s - i;
            for(auto& p: dp[i][j]){
                if(i + 1 < n){
                    dp[i + 1][j][p.first ^ a[i + 1][j]] += p.second;
                }
                if(j + 1 < m){
                    dp[i][j + 1][p.first ^ a[i][j + 1]] += p.second;
                }
            }
            if(s != z - 1){
                dp[i][j].clear();
            }
        }
    }
          /*  cerr << "dp1:" << endl;
    for(int i = max(0, z - m + 1); i < n && i <= z; ++i){
        int j = z - i;
        for(auto& p: dp[i][j]){
            cerr << i << " " << j << " " << (p.first ^ key) << " " << p.second << endl;
        }
    }*/
    if(z == n + m - 2) {
        cout << dp[n - 1][m - 1][k ^ key] << endl;
        return 0;
    }

    for(int i = 0; i * 2 < n; ++i){
        for(int j = 0; j < m; ++j){
            swap(a[i][j], a[n - 1 - i][m - 1 - j]);
        }
    }
    vector<vector<unordered_map<ll, int>>> dp2(n, vector<unordered_map<ll, int>>(m));
    dp2[0][0][a[0][0] ^ key] = 1;
    for(int s = 0; s < n + m - 2 - z; ++s){
        for(int i = max(0, s - m + 1); i < n && i <= s; ++i){
            int j = s - i;
            for(auto& p: dp2[i][j]){
                if(i + 1 < n){
                    dp2[i + 1][j][p.first ^ a[i + 1][j]] += p.second;
                }
                if(j + 1 < m){
                    dp2[i][j + 1][p.first ^ a[i][j + 1]] += p.second;
                }
            }
            if(s != n + m - 2 - z - 1){
                dp2[i][j].clear();
            }
        }
    }
    int s = n + m - 2 - z;
/*
    cerr << "dp2:" << endl;
    for(int i = max(0, s - m + 1); i < n && i <= s; ++i){
        int j = s - i;
        for(auto& p: dp2[i][j]){
            cerr << i << " " << j << " " << (p.first ^ key) << " " << p.second << endl;
        }
    }*/
    ll ans = 0;
    for(int i = max(0, s - m + 1); i < n && i <= s; ++i) {
        int j = s - i;
        for (auto &p: dp2[i][j]) {
            ans += p.second * ll(dp[n - 1 - i][m - 1 - j][p.first ^ k ^ a[i][j]]);
//            cerr << p.second << " " << dp[n - 1 - i][m - 1 - j][p.first ^ k ^ a[i][j]] << endl;
        }
    }
    cout << ans << endl;
    return 0;
}