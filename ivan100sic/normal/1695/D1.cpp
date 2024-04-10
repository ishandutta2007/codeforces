// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

struct union_find {
    vector<int> p;
    union_find(int n) : p(n) { iota(begin(p), end(p), 0); }
    bool operator() (int x, int y) { return e(x) == e(y); }
    int e(int x) {
        if (p[x] == x) return x;
        return p[x] = e(p[x]);
    }
    bool join(int x, int y) {
        x = e(x), y = e(y);
        if (x == y) return false;
        p[x] = y;
        return true;
    }
};

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<array<int, 2>> e(n-1);
        vector<vector<int>> g(n);
        vector<int> deg(n);
        for (auto& [x, y] : e) {
            cin >> x >> y;
            x--, y--;
            deg[x]++;
            deg[y]++;
            g[x].push_back(y);
            g[y].push_back(x);
        }

        union_find uf(n+1);

        int leaves = 0; 
        for (int i : ra(0, n)) {
            if (deg[i] == 1) {
                uf.join(i, n);
                leaves++;
            }
        }

        if (leaves == 0) {
            // single point
            cout << "0\n";
            continue;
        }
        
        if (leaves == 2) {
            cout << "1\n";
            continue;
        }

        for (auto [x, y] : e) {
            if (deg[x] <= 2 && deg[y] <= 2) {
                uf.join(x, y);
            }
        }

        int conn = 0;
        for (int i : ra(0, n)) {
            bool f = 0;
            for (int j : g[i]) {
                if (uf(j, n)) f = 1;
            }
            
            if (deg[i] >= 3 && f) {
                conn++;
            }
        }

        cout << leaves - conn << '\n';
    }
}