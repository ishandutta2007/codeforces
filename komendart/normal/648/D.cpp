#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    sort(x.begin(), x.end());

    vector< pair<int, int> > left(m);
    for (int i = 0; i < m; i++) {
        int u, t; cin >> u >> t;
        left[i] = {u - t, u + t};
    }
    sort(left.begin(), left.end());

    int pl = 0;
    multiset<int> d;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        while (pl < m && left[pl].first <= x[i]) {
            d.insert(left[pl].second);
            pl++;
        }
        while (!d.empty() && *d.begin() < x[i]) {
            d.erase(d.begin());
        }
        if (!d.empty()) {
            d.erase(d.begin());
            ans++;
        }
    }

    cout << ans << '\n';

}