#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int T;
    for (cin >> T; T; T -= 1) {
        int n, m;
        cin >> n >> m;
        vector<int> v(n * m);
        for (int& x : v) cin >> x;
        vector<int> w = v;
        sort(w.begin(), w.end());
        vector<vector<int>> u(n, vector<int>(m));
        map<int, vector<pair<int, int>>> mp;
        for (int i = 0; i < n; i += 1)
            for (int j = 0; j < m; j += 1)
                mp[w[i * m + j]].push_back({i, j});
        for (auto& [x, v] : mp)
            sort(v.begin(), v.end(), [&](const pair<int, int>& x, const pair<int, int>& y){
                if (x.first != y.first) return x.first > y.first;
                return x.second < y.second;
            });
        int ans = 0;
        for (int x : v) {
            auto [i, j] = mp[x].back();
            mp[x].pop_back();
            u[i][j] = 1;
            for (int k = 0; k < j; k += 1) ans += u[i][k];
        }
        cout << ans << "\n";
    }
    return 0;
}