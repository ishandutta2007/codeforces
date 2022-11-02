#include <bits/stdc++.h>

using int64 = long long;

using namespace std;

const int N = 300001;

int g[N], sz[N], x[N];

pair<int64, int> a[N];

vector<int> e[N], e2[N];

int64 gethash(const vector<int>& x) {
    int64 cur = 0;
    for (int u : x) cur = (cur * int64(N) + u);
    cur = (cur * int64(N) + x.size());
    return cur;
}

void no() { cout << "NO" << endl, exit(0); }

void ad(vector<int>& where, int x) {
    for (int u : where) {
        if (x == u) return;
    }
    if (where.size() == 2) no();
    where.push_back(x);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), std::cout.tie(0);
    cout.setf(ios::fixed), cout.precision(20);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int a, b;
        cin >> a >> b;
        e[a].push_back(b);
        e[b].push_back(a);
    }
    for (int i = 1; i <= n; ++i) {
        e[i].push_back(i);
        sort(e[i].begin(), e[i].end());
        a[i] = make_pair(gethash(e[i]), i);
    }
    sort(a + 1, a + n + 1);
    int lc = 0, rc;
    int k = 0;
    for (lc = 1; lc <= n; lc = rc) {
        rc = lc;
        while ((rc <= n) && (a[rc].first == a[lc].first)) ++rc;
        for (int j = lc; j < rc; ++j) g[a[j].second] = k;
        sz[k] = rc - lc, ++k;
    }
    for (int i = 1; i <= n; ++i) {
        int same = 0;
        for (int u : e[i]) {
            if (g[i] != g[u]) {
                ad(e2[g[i]], g[u]);
            } else {
                ++same;
            }
        }
        if (same != sz[g[i]]) no();
    }
    int cx = 1;
    for (int i = 0; i < k; ++i) {
        if (x[i] != 0) continue;
        if (e2[i].size() == 0) {
            x[i] = cx + 2, cx += 5;
            continue;
        }
        if (e2[i].size() > 1) continue;
        cx += 2, x[i] = cx++;
        int nx = e2[i][0], pv = i;
        while (e2[nx].size() != 1) {
            int nnx = e2[nx][0] + e2[nx][1] - pv;
            x[nx] = cx++, pv = nx, nx = nnx;
        }
        x[nx] = cx, cx += 2;
    }
    for (int i = 0; i < k; ++i) {
        if (x[i] == 0) no();
    }
    cout << "YES\n";
    for (int i = 1; i <= n; ++i) cout << x[g[i]] << " ";
    cout << "\n";
    return 0;
}