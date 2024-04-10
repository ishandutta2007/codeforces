#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, d;
    cin >> n >> m >> d;
    vector<int> c(m);
    for (int i = 0; i < m; ++i)
        cin >> c[i];
    int res = n + 1 - accumulate(c.begin(), c.end(), 0) + m;
    if (d * (m + 1) < res) {
        cout << "NO" << "\n";
        return 0;
    }
    cout << "YES" << "\n";
    res -= m + 1;
    vector<int> x(m + 1);
    for (int i = 0; i <= m; ++i) {
        x[i] = min(d - 1, res);
        res -= x[i];
    }
    vector<int> ans;
    for (int i = 0; i <= m; ++i) {
        for (int j = 0; j < x[i]; ++j)
            ans.push_back(0);
        if (i != m)
            for (int j = 0; j < c[i]; ++j)
                ans.push_back(i + 1);
    }
    for (int i = 0; i < n; ++i)
        cout << ans[i] << " \n"[i == n - 1];
    return 0;
}