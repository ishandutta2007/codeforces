#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3e5;
int usedg[MAXN], usede[MAXN], col[MAXN];
vector<int> g[MAXN], e[MAXN];

void check(int v) {
    col[v] = 1;
    for (auto u : g[v]) {
        if (col[u] == 1) {
            cout << -1;
            exit(0);
        } else if (col[u] == 0) {
            check(u);
        }
    }
    col[v] = 2;
}

void fillg(int v) {
    usedg[v] = true;
    for (auto u : g[v]) {
        if (!usedg[u]) {
            fillg(u);
        }
    }
}

void fille(int v) {
    usede[v] = true;
    for (auto u : e[v]) {
        if (!usede[u]) {
            fille(u);
        }
    }
}

main() {
    int n, m;
    cin >> n >> m;
    while (m--) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        e[v].push_back(u);
    }
    for (int i = 0; i < n; ++i) {
        if (col[i] == 0) {
            check(i);
        }
    }
    int ans = 0;
    string res;
    for (int i = 0; i < n; ++i) {
        if (!usedg[i] && !usede[i]) {
            ans++;
            res.push_back('A');
        } else {
            res.push_back('E');
        }
        if (!usedg[i]) {
            fillg(i);
        }
        if (!usede[i]) {
            fille(i);
        }
    }
    cout << ans << endl;
    cout << res;
    return 0;
}