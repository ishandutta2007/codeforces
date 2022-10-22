#include<bits/stdc++.h>

using namespace std;

#define int long long

vector<vector<int>> g;

int L = 20;
vector<vector<int>> PR;
vector<int> h;

void dfs(int v, int p, int H) {
    h[v] = H;
    PR[v][0] = p;
    for (int i = 1; i < L; i++) {
        PR[v][i] = PR[PR[v][i - 1]][i - 1];
    }
    for (auto el : g[v]) {
        if (el != p) dfs(el, v, H + 1);
    }
}

int get(int x, int y) {
    if (h[x] < h[y]) swap(x, y);
    int z = h[x] - h[y];
    for (int i = 0; i < L; i++) {
        if (z & (1 << i)) {
            x = PR[x][i];
        }
    }
    if (x == y) return x;
    for (int i = L - 1; i >= 0; i--) {
        int a = PR[x][i];
        int b = PR[y][i];
        if (a != b) {
            x = a;
            y = b;
        }
    }
    return PR[x][0];
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, q;
    cin >> n >> q;
    g.resize(n);
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    PR.resize(n, vector<int> (L, 0));
    h.resize(n);
    dfs(0, 0, 0);
    while (q--) {
        int k;
        cin >> k;
        vector<int> a(k);
        for (int i = 0; i < k; i++) cin >> a[i];
        for (int i = 0; i < k; i++) a[i]--;
        int mx = 0;
        for (auto v : a) if (h[v] > h[mx]) mx = v;
        bool f = true;
        for (auto v : a) {
            int x = get(mx, v);
            if (x == v || x == PR[v][0]) continue;
            f = false;
        }
        if (f) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}