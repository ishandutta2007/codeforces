#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

const int N = int(3e5) + 5;

int n, x;
int p[N], r[N];

int64 ans;
int64 c[N], d[N], ms[N], mp[N], ts[N];

array<int64, 2> e[N];

int find(int x) { return x == p[x] ? x : (p[x] = find(p[x])); }

void join(int x, int y, int64 d) {
    if ((x = find(x)) == (y = find(y))) return;
    ans = max(ms[x] + mp[y] + d, ans);
    int64 cms = max(ms[y], ts[y] + ms[x]);
    int64 cmp = max(mp[x], ts[x] + mp[y]);
    if (r[x] < r[y]) swap(x, y);
    p[y] = x;
    r[x] += r[x] == r[y];
    ms[x] = cms;
    mp[x] = cmp;
    ts[x] += ts[y];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> x;
    iota(p, p + n, 0);
    for (int i = 0; i < n; ++i)
        cin >> d[i] >> c[i], ms[i] = mp[i] = ts[i] = c[i] = x - c[i],
                             ans = max(c[i], ans);
    for (int i = 0; i < n; ++i) e[i] = {d[i + 1] - d[i], i};
    sort(e, e + n - 1);
    for (int i = 0; i < n - 1; ++i) {
        join(e[i][1], e[i][1] + 1, -e[i][0] * e[i][0]);
    }
    cout << ans;
    return 0;
}