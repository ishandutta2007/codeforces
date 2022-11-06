#include <bits/stdc++.h>

using namespace std;

#define int long long

struct Segment {
    int left, right;
    int number;
};

bool cmp(const Segment &a, const Segment &b) {
    return a.right < b.right;
}

signed main() {
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    vector<Segment> segments(n - 1, Segment{});
    int prev_l, prev_r;
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        if (i > 0) {
            segments[i - 1] = Segment {l - prev_r, r - prev_l, i - 1};
        }
        prev_l = l;
        prev_r = r;
    }

    set< pair<int, int> > bridges;
    for (int i = 0; i < m; i++) {
        pair<int, int> p;
        cin >> p.first;
        p.second = i;
        bridges.insert(p);
    }

    sort(segments.begin(), segments.end(), cmp);

    vector<int> result(n - 1, -1);
    for (auto &s: segments) {
        auto it = bridges.upper_bound(make_pair(s.left, -1));
        if (it == bridges.end() || it->first > s.right) {
            cout << "No" << endl;
            return 0;
        }
        result[s.number] = it->second + 1;
        bridges.erase(it);
    }

    cout << "Yes" << '\n';
    for (auto i: result) {
        cout << i << ' ';
    }
}