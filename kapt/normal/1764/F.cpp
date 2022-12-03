#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int MAXN = 2e3 + 100;
int f[MAXN][MAXN];

int p[MAXN], sz[MAXN];

int get(int v) {
    if (p[v] == v) return p[v];
    return p[v] = get(p[v]);
}

bool join(int u, int v) {
    u = get(u); v = get(v);
    if (u == v) return false;
    if (sz[u] <= sz[v]) swap(u, v);
    sz[u] += sz[v];
    p[v] = u;
    return true;
}

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        p[i] = i;
        sz[i] = 1;
        for (int j = 0; j <= i; ++j) {
            cin >> f[i][j];
        }
    }
    vector<array<int, 3>> ed(n * (n - 1) / 2);
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            int val = (f[i][i] + f[j][j] - f[i][j] * 2) / n;
            ed[cnt] = {val, i, j};
            cnt++;
        }
    }
    sort(ed.begin(), ed.end());
    for (auto elem : ed) {
        if (join(elem[1], elem[2])) {
            cout << elem[1] + 1 << " " << elem[2] + 1 << " " << elem[0] << '\n';
        }
    }
    return 0;
}