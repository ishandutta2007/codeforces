// Retired?
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

int n, m;
int sol;

set<int> s[200005];
int g[200005];

void cg(int x) {
    g[x] = s[x].empty() || (x > *s[x].rbegin());
}

void ad(int x, int y) {
    sol -= g[x] + g[y];
    s[x].insert(y);
    s[y].insert(x);
    cg(x);
    cg(y);
    sol += g[x] + g[y];
}

void rm(int x, int y) {
    sol -= g[x] + g[y];
    s[x].erase(y);
    s[y].erase(x);
    cg(x);
    cg(y);
    sol += g[x] + g[y];
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        g[i] = 1;
    }
    sol = n;

    for (int i=0; i<m; i++) {
        int x, y;
        cin >> x >> y;
        ad(x, y);
    }
    
    int q;
    cin >> q;
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int x, y;
            cin >> x >> y;
            ad(x, y);
        } else if (t == 2) {
            int x, y;
            cin >> x >> y;
            rm(x, y);
        } else {
            cout << sol << '\n';
        }
    }

}