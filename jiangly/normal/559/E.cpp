#include <bits/stdc++.h>
using namespace std;
constexpr int INF = 1E9;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<tuple<int, int, int>> p(n);
    vector<int> x;
    for (int i = 0; i < n; ++i) {
        int a, l;
        cin >> a >> l;
        p[i] = {a, a - l, a + l};
        x.push_back(a);
        x.push_back(a - l);
        x.push_back(a + l);
    }
    
    sort(x.begin(), x.end());
    x.resize(unique(x.begin(), x.end()) - x.begin());
    sort(p.begin(), p.end());
    for (auto &_p : p) {
        int a, l, r;
        tie(a, l, r) = _p;
        a = lower_bound(x.begin(), x.end(), a) - x.begin();
        l = lower_bound(x.begin(), x.end(), l) - x.begin();
        r = lower_bound(x.begin(), x.end(), r) - x.begin();
        _p = {a, l, r};
    }
    
    vector<int> sorted_by_l(n);
    iota(sorted_by_l.begin(), sorted_by_l.end(), 0);
    sort(sorted_by_l.begin(), sorted_by_l.end(), [&](int i, int j) {return get<1>(p[i]) > get<1>(p[j]);});
    
    vector<vector<int>> dp(n + 1);
    for (int i = 0; i <= n; ++i)
        dp[i].resize(x.size());
    for (int i = 0; i < n; ++i) {
        int a, l, r;
        tie(a, l, r) = p[i];
        for (int j = l; j <= a; ++j)
            dp[i + 1][a] = max(dp[i + 1][a], dp[i][j] + x[a] - x[j]);
        for (int j = a; j <= r; ++j)
            dp[i + 1][r] = max(dp[i + 1][r], dp[i][j] + x[r] - x[j]);
        for (int j = 0; j < x.size(); ++j) {
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
            if (j > 0)
                dp[i + 1][j] = max(dp[i + 1][j], dp[i + 1][j - 1]);
        }
        int k = x.size();
        int mx = -INF;
        for (int j : sorted_by_l) {
            if (j <= i)
                continue;
            int _a, _l, _r;
            tie(_a, _l, _r) = p[j];
            while (_l < k) {
                --k;
                mx = max(mx, dp[i][k] - x[k]);
            }
            dp[j + 1][r] = max(dp[j + 1][r], mx + x[r]);
        }
    }
    cout << dp[n].back() << endl;
    return 0;
}