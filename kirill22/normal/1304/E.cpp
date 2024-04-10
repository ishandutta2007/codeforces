#include <bits/stdc++.h>

using namespace std;

#define int long long

vector<vector<int>> g;
vector<bool> used;
vector<vector<int>> p;
vector<int> PR;
vector<int> l;
int k = 0;

void dfs(int v, int pr, int gl) {
    used[v] = true;
    PR[v] = pr;
    l[v] = gl;
    int K = 0;
    while (K < k) {
        p[v][K] = pr;
        K++;
        pr = p[pr][K - 1];
    }
    for (auto c : g[v]) {
        if (!used[c]) {
            dfs(c, v, gl + 1);
        }
    }
}

int lca(int a, int b) {
    if (l[a] < l[b]) {
        swap(a, b);
    }
    int K = k - 1;
    while (l[a] > l[b] && K >= 0) {
        if (l[p[a][K]] < l[b]) {
            K--;
            continue;
        }
        a = p[a][K];
        K--;
    }
    K = k - 1;
    while (a != b && K >= 0) {
        if (p[a][K] == p[b][K]) {
            K--;
            continue;
        }
        a = p[a][K];
        b = p[b][K];
        K--;
    }
    if (a == b) return a;
    return PR[a];
}

int D(int a, int b) {
    int z = lca(a, b);
    return l[a] + l[b] - 2 * l[z];
}

signed main() {
    int n;
    cin >> n;
    g.resize(n);
    PR.resize(n);
    l.resize(n, 0);
    used.resize(n, false);
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    while ((1 << k) <= n) {
        k++;
    }
    p.resize(n, vector<int> (k, 0));
    dfs(0, 0, 0);
    int q;
    cin >> q;
    while (q--) {
        int x, y, a, b, k;
        cin >> x >> y >> a >> b >> k;
        x--;
        y--;
        a--;
        b--;
        int d = D(a, b);
        if (d <= k && d % 2 == k % 2) {
            cout << "YES" << endl;
            continue;
        }
        if (true) {
            d = D(a, x) + 1 + D(y, b);
            if (d <= k && d % 2 == k % 2) {
                cout << "YES" << endl;
                continue;
            }
            d = D(a, y) + 1 + D(b, x);
            if (d <= k && d % 2 == k % 2) {
                cout << "YES" << endl;
                continue;
            }
        }
        cout << "NO" << endl;
    }
}