#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int N = 3E5;
vector<pair<int, int>> e[4 * N];
int f[N], fa[N], cnt[N];
vector<pair<int *, int>> stk;
LL ans;
int find(int x) {
    while (fa[x] >= 0)
        x = fa[x];
    return x;
}
void rangeCover(int p, int l, int r, int s, int t, const pair<int, int> &v) {
    if (l >= t || r <= s)
        return;
    if (l >= s && r <= t) {
        e[p].push_back(v);
        return;
    }
    int mid = (l + r) / 2;
    rangeCover(2 * p, l, mid, s, t, v);
    rangeCover(2 * p + 1, mid, r, s, t, v);
}
void solve(int p, int l, int r) {
    int clc = (int)stk.size();
    LL bak = ans;
    for (auto v : e[p]) {
        int x, y;
        tie(x, y) = v;
        y = find(y);
        if (f[x] == -1) {
            stk.emplace_back(&f[x], -1);
            f[x] = y;
            stk.emplace_back(&cnt[y], cnt[y]);
            ++cnt[y];
            ans -= fa[y];
        } else {
            int z = find(f[x]);
            if (y == z)
                continue;
            if (fa[y] < fa[z])
                swap(y, z);
            ans += 1LL * fa[y] * cnt[y] + 1LL * fa[z] * cnt[z];
            stk.emplace_back(&fa[z], fa[z]);
            fa[z] += fa[y];
            stk.emplace_back(&fa[y], fa[y]);
            fa[y] = z;
            stk.emplace_back(&cnt[z], cnt[z]);
            cnt[z] += cnt[y];
            ans -= 1LL * fa[z] * cnt[z];
        }
    }
    if (r - l == 1) {
        cout << ans << " ";
    } else {
        int mid = (l + r) / 2;
        solve(2 * p, l, mid);
        solve(2 * p + 1, mid, r);
    }
    while ((int)stk.size() > clc) {
        *stk.back().first = stk.back().second;
        stk.pop_back();
    }
    ans = bak;
}
int main() {
    memset(f, -1, sizeof(f));
    memset(fa, -1, sizeof(fa));
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int q;
    cin >> q;
    map<pair<int, int>, int> in;
    for (int i = 0; i < q; ++i) {
        int x, y;
        cin >> x >> y;
        --x;
        --y;
        if (in.count({x, y})) {
            rangeCover(1, 0, q, in[{x, y}], i, {x, y});
            in.erase({x, y});
        } else {
            in[{x, y}] = i;
        }
    }
    for (auto p : in)
        rangeCover(1, 0, q, p.second, q, p.first);
    solve(1, 0, q);
    cout << endl;
    return 0;
}