// Retired?
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

int n, m, k;
bool adj[12][12];
int deg[12];

using variety = array<char, 12>;

template<class F>
struct variety_generator {
    variety a;
    F f;

    variety_generator(F f) : f(f) {
        dfs(0, 0);
    }

    void dfs(int i, int c) {
        if (i == n) {
            int m = 0;
            for (int j=0; j<n; j++) {
                m ^= 1 << a[j];
            }

            if (!m) f(a);
            return;
        }

        for (int x=0; x<=c; x++) {
            a[i] = x;
            dfs(i+1, x == c && c+1 < n/2 ? c + 1 : c);
        }
    }
};

struct variety_solver {
    variety a;
    int c[6][12], l[6];

    variety_solver(variety a) : a(a) {
        fill(l, l+6, 0);
        for (int i=0; i<n; i++) {
            int& x = l[a[i]];
            c[a[i]][x++] = i;
        }
    }

    bool dfs(int x, int y, int left) {
        if (!left) {
            return adj[x][y];
        }

        for (int col=0; col<6; col++) {
            if (int& k = l[col]; k) {
                for (int i=0; i<k; i++) {
                    for (int j=0; j<k; j++) {
                        if (j == i) continue;
                        int u = c[col][i], v = c[col][j];

                        if (x == -1 || (adj[x][u] && adj[y][v])) {

                            if (x == -1) {
                                bool ok = true;
                                // check if we're taking all leaves
                                for (int i=0; i<n; i++) {
                                    if (deg[i] == 1 && i != u && i != v) {
                                        ok = false;
                                        break;
                                    }
                                }

                                if (!ok) {
                                    continue;
                                }
                            }

                            int orig[12];
                            copy(c[col], c[col] + k, orig);
                            remove_if(c[col], c[col] + k, [&](int x) { return x == u || x == v; });
                            k -= 2;

                            if (dfs(u, v, left-1)) {
                                return true;
                            }

                            k += 2;
                            copy(orig, orig + k, c[col]);
                        }
                    }
                }
            }
        }
        return false;
    }

    operator bool() {
        return dfs(-1, -1, n / 2);
    }
};

ll falling[13];

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    cin >> n >> m >> k;
    for (int i=0; i<m; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        adj[x][y] = adj[y][x] = 1;
        deg[x]++;
        deg[y]++;
    }

    for (int i=0; i<n; i++) {
        if (deg[i] == 0) {
            cout << "0\n";
            return 0;
        }
    }
    
    falling[0] = 1;
    for (int i=1; i<13; i++) {
        falling[i] = falling[i-1] * (k - i + 1);
    }

    ll sol = 0;

    variety_generator gen([&](variety v) {
        // cerr << "solving variety :";
        // for (int i=0; i<n; i++) {
            // cerr << int(v[i]) << ' ';
        // }

        int colors = *max_element(v.data(), v.data() + n) + 1;
        if (variety_solver(v)) {
            sol += falling[colors];
            // cerr << "ok\n";
        } else {
            if (colors == 1) {
                cout << "0\n";
                exit(0);
            }
            // cerr << "failed\n";
        }
    });

    cout << sol << '\n';
}