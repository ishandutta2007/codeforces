#include <bits/stdc++.h>

using namespace std;

#define int long long

const int INF = 1e18;

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n, st;
    cin >> n >> st;
    vector< pair<int, int> > seg(n);
    vector<int> points = {st};
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        points.push_back(l); points.push_back(r);
        seg[i] = {l, r};
    }

    sort(points.begin(), points.end());
    points.resize(unique(points.begin(), points.end()) - points.begin());
    int m = points.size();

    vector<int> d(m, INF);
    d[lower_bound(points.begin(), points.end(), st) - points.begin()] = 0;
    for (int i = 0; i < n; i++) {
        int l = lower_bound(points.begin(), points.end(), seg[i].first) - points.begin();
        int r = lower_bound(points.begin(), points.end(), seg[i].second) - points.begin();
        for (int j = 0; j <= l; j++) {
            d[j] += seg[i].first - points[j];
            if (j > 0) d[j] = min(d[j], d[j - 1]);
        }
        for (int j = m - 1; j >= r; j--) {
            d[j] += points[j] - seg[i].second;
            if (j < m - 1) d[j] = min(d[j], d[j + 1]);
        }
    }

    int result = INF;
    for (auto i: d) result = min(result, i);
    cout << result << '\n';
}