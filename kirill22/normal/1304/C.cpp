#include<bits/stdc++.h>

using namespace std;

#define int long long

void solve() {
    int n, m;
    cin >> n >> m;
    map<int, pair<int, int>> a;
    for (int i = 0; i < n; i++) {
        int t, x, y;
        cin >> t >> x >> y;
        if (a.find(t) != a.end()) {
            a[t].first = max(a[t].first, x);
            a[t].second = min(a[t].second, y);
        }
        else {
            a[t] = {x, y};
        }
    }
    bool f = true;
    int t = 0, x = m, y = m;
    for (auto el : a) {
        //cout << t << " " << x << " " << y << endl;
        int x2 = el.second.first;
        int y2 = el.second.second;
        if (y2 < x2) {
            f = false;
            break;
        }
        int t2 = el.first - t;
        x -= t2;
        y += t2;
        x = max(x, x2);
        y = min(y, y2);
        if (y < x) {
            f = false;
            break;
        }
        t = el.first;
    }
    if (f) cout << "YES" << endl;
    else cout << "NO" << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> q;
    while (q--) {
        solve();
    }
}