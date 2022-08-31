#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(m, vector<int>(n));
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            cin >> a[i][j];
    pair<int, vector<bool>> ans;
    ans.first = m;
    ans.second.assign(m, true);
    auto solve = [&](int x) {
        vector<pair<int, int>> f(m);
        for (int i = 0; i < m; ++i)
            f[i] = {a[i][x] - a[i][n - 1], i};
        sort(f.begin(), f.end(), greater<pair<int, int>>());
        int sum = 0, c = 0;
        vector<bool> b(m, true);
        while (c < m && sum + f[c].first >= 0) {
            sum += f[c].first;
            b[f[c].second] = false;
            ++c;
        }
        return make_pair(m - c, b);
    };
    for (int i = 0; i < n - 1; ++i)
        ans = min(ans, solve(i));
    cout << ans.first << "\n";
    for (int i = 0; i < m; ++i)
        if (ans.second[i])
            cout << i + 1 << " ";
    cout << endl;
    return 0;
}