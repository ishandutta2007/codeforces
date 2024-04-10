#include <bits/stdc++.h>
using namespace std;

const int max_n = 150555, inf = 1000111222;

int n, nxt[max_n], nxt_upd[max_n], first[max_n], last[max_n], f[max_n];

int find_root(int v) {
    if (v == nxt_upd[v]) {
        return v;
    }
    return nxt_upd[v] = find_root(nxt_upd[v]);
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        nxt_upd[i] = i;
        first[i] = i;
        last[i] = i;
    }
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        int ru = find_root(u);
        int rv = find_root(v);
        nxt[last[ru]] = first[rv];
        nxt_upd[last[ru]] = last[rv];
        first[rv] = first[ru];
    }
    for (int i = 1; i <= n; ++i) {
        f[nxt[i]] = 1;
    }
    int x;
    for (int i = 1; i <= n; ++i) {
        if (!f[i]) {
            x = i;
            break;
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << x << ' ';
        x = nxt[x];
    }
    return 0;
}