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

// testcase RO globals
int n;
int d[100][100][100];

bool verify(const vector<pair<int, int>>& e) {
    if (ssize(e) != n-1) {
        return false;
    }

    static int dist[100][100];

    memset(dist, 63, sizeof(dist));
    for (auto [x, y] : e) {
        dist[x][y] = dist[y][x] = 1;
    }
    for (int x : ra(0, n)) dist[x][x] = 0;

    for (int x : ra(0, n)) {
        for (int y : ra(0, n)) {
            for (int z : ra(0, n)) {
                dist[y][z] = min(dist[y][z], dist[y][x] + dist[x][z]);
            }
        }
    }

    for (int i : ra(0, n)) {
        for (int j : ra(0, n)) {
            if (j == i) continue;
            for (int k : ra(0, n)) {
                if ((dist[i][k] == dist[j][k]) != (d[i][j][k])) {
                    return false;
                }
            }
        }
    }

    return true;
}

vector<pair<int, int>> try_construct(int u0, int v0) {
    union_find uf(n);
    vector<pair<int, int>> sol = {{u0, v0}};
    uf.join(u0, v0);

    size_t qs = 0;
    while (qs != sol.size()) {
        auto [u, v] = sol[qs++];
        
        auto go = [&](int x, int y) {
            for (int w : ra(0, n)) {
                if (w != x && d[x][w][y]) {
                    // w-y
                    if (uf.join(y, w)) {
                        sol.emplace_back(y, w);
                    }
                }
            }
        };
        
        go(u, v);
        go(v, u);
    }

    return sol;
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        cin >> n;

        for (int i : ra(0, n-1)) {
            for (int j : ra(i+1, n)) {
                string str;
                cin >> str;
                for (int k : ra(0, n)) {
                    d[i][j][k] = str[k] == '1';
                    d[j][i][k] = d[i][j][k];
                }
            }
        }

        bool found = false;
        for (int b : ra(1, n)) {
            auto sol = try_construct(0, b);
            if (verify(sol)) {
                cout << "Yes\n";
                for (auto [x, y] : sol) {
                    cout << x+1 << ' ' << y+1 << '\n';
                }
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "No\n";
        }
    }
}