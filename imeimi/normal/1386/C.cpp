#include <bits/stdc++.h>

using namespace std;

int n, m, q;
int X[200002], Y[200002];

vector<int> op;
int par[400005], sz[400005];

void restore(int psz) {
    while (psz < int(op.size())) {
        int x = op.back();
        op.pop_back();
        sz[par[x]] -= sz[x];
        par[x] = x;
    }
}

int find(int x) {
    return par[x] != x ? find(par[x]) : x;
}

void merge(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return;
    if (sz[x] < sz[y]) swap(x, y);
    par[y] = x;
    sz[x] += sz[y];
    op.push_back(y);
}

bool merge_v(int x, int y) {
    --x, --y;
    merge(x << 1 | 0, y << 1 | 1);
    merge(x << 1 | 1, y << 1 | 0);
    return (find(x << 1 | 0) == find(x << 1 | 1));
}

int mv[200001];
void solve(int s, int e, int x, int y, bool odd) {
    if (s > e) return;
    int psz = op.size();
    int m = (s + e) / 2;
    bool nodd = odd;
    for (int i = m; i <= min(e, ::m); ++i) nodd |= merge_v(X[i], Y[i]);
    if (nodd) mv[m] = x;
    else for (int i = x + 1; i <= y; ++i) {
        nodd |= merge_v(X[i], Y[i]);
        if (nodd) {
            mv[m] = i;
            break;
        }
    }
    restore(psz);
    nodd = odd;
    for (int i = m; i <= min(e, ::m); ++i) nodd |= merge_v(X[i], Y[i]);
    solve(s, m - 1, x, mv[m], nodd);
    restore(psz);
    nodd = odd;
    for (int i = x + 1; i <= mv[m]; ++i) nodd |= merge_v(X[i], Y[i]);
    solve(m + 1, e, mv[m], y, nodd);
    restore(psz);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> q;
    for (int i = 1; i <= m; ++i) {
        cin >> X[i] >> Y[i];
    }
    X[m + 1] = Y[m + 1] = 1;
    for (int i = 0; i < n + n; ++i) par[i] = i, sz[i] = 1;
    solve(1, m + 1, 0, m + 1, 0);
    while (q--) {
        int l, r;
        cin >> l >> r;
        printf(l - 1 >= mv[r + 1] ? "YES\n" : "NO\n");
    }
    return 0;
}