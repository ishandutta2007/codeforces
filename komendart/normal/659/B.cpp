#include <bits/stdc++.h>

using namespace std;

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector< vector< pair<int, string> > > a(m);
    for (int i = 0; i < n; i++) {
        string s; int reg, points;
        cin >> s >> reg >> points;
        a[reg - 1].push_back({points, s});
    }
    for (int i = 0; i < m; i++) {
        sort(a[i].rbegin(), a[i].rend());
        if (a[i].size() > 2 && a[i][2].first == a[i][1].first) {
            cout << "?\n";
        } else {
            cout << a[i][0].second << ' ' << a[i][1].second << '\n';
        }
    }
}