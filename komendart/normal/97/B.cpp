#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second

int n;
vector< pair<int, int> > a;
set< pair<int, int> > d;

void solve(int l, int r) {
    if (r - l <= 1) return;
    int m = (l + r) / 2;
    solve(l, m);
    solve(m, r);
    for (int i = l; i < r; ++i) {
        d.insert({a[m].x, a[i].y});
    }
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n;
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].x >> a[i].y;
        d.insert(a[i]);
    }
    sort(a.begin(), a.end());

    solve(0, n);
    cout << d.size() << '\n';
    for (auto i: d) {
        cout << i.x << ' ' << i.y << '\n';
    }
}