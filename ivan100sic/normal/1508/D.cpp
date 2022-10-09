// Retired?
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

struct pt {
    ll x, y;
};

ll det(pt a, pt b, pt c) {
    return a.x*b.y + b.x*c.y + c.x*a.y - a.y*b.x - b.y*c.x - c.y*a.x;
}

namespace test {
    ll sgn(ll x) {
        return x ? (x > 0 ? 1 : -1) : 0;
    }

    bool seku(pt a, pt b, pt c, pt d) {
        return sgn(det(a, b, c)) * sgn(det(a, b, d)) == -1 &&
            sgn(det(c, d, a)) * sgn(det(c, d, b)) == -1;
    }

    int n;
    pt a[10];
    int b[10];
    bool u[10][10];
    int found = 0;
    vector<pair<int, int>> lines, best_lines;

    ll calls = 0;

    void dfs() {
        calls++;
        bool done = true;
        for (int i=0; i<n; i++) {
            if (b[i] != i) {
                done = false;
            }
        }

        if (done) {
            if (!found || lines.size() < best_lines.size()) {
                best_lines = lines;
                found = 1;
            }
            return;
        }

        for (int i=0; i<n; i++) {
            for (int j=i+1; j<n; j++) {
                if (u[i][j]) continue;

                bool ok = true;
                for (auto [p, q] : lines) {
                    if (seku(a[i], a[j], a[p], a[q])) {
                        ok = false;
                        break;
                    }
                }

                if (!ok) continue;
                lines.push_back({i, j});
                u[i][j] = 1;
                swap(b[i], b[j]);
                
                dfs();

                u[i][j] = 0;
                swap(b[i], b[j]);
                lines.pop_back();
            }
        }
    }

    void validate() {
        for (int i=0; i<n; i++) {
            for (int j=i+1; j<n; j++) {
                for (int k=j+1; k<n; k++) {
                    if (det(a[i], a[j], a[k]) == 0) {
                        cerr << "Invalid\n";
                        return;
                    }
                }
            }
        }
        cerr << "Valid\n";
    }

    void main() {
        cin >> n;
        for (int i=0; i<n; i++) {
            cin >> a[i].x >> a[i].y >> b[i];
        }

        validate();
        dfs();

        if (!found) {
            cout << "-1\n";
        } else {
            cout << best_lines.size() << '\n';
            for (auto [x, y] : best_lines) {
                cout << x << ' ' << y << '\n';
            }
        }

        cerr << "calls = " << calls << '\n';
    }
}

namespace seq {
    int n;
    int u[20];
    set<vector<int>> se;
    vector<int> lb;

    void dfs() {
        se.insert(lb);
        for (int i=0; i<2*n-3; i++) {
            if (u[i]) continue;
            int x, y;
            if (i < n-1) {
                x = 0;
                y = i + 1;
            } else {
                x = i - (n - 1) + 1;
                y = x + 1;
            }
            u[i] = 1;
            swap(lb[x], lb[y]);
            dfs();
            swap(lb[x], lb[y]);
            u[i] = 0;
        }
    }

    void seq() {
        cin >> n;
        lb.resize(n);
        iota(begin(lb), end(lb), 0);
        dfs();
        cerr << se.size() << '\n';
    }
}

namespace sol {
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



    bool cmp_lex(pt a, pt b) {
        return tie(a.x, a.y) < tie(b.x, b.y);
    }
    
    // p[0] != 0
    vector<pair<int, int>> sort_permutation(vector<int> p) {
        int n = p.size();
        vector<pair<int, int>> sol;

        union_find uf(n+1);
        for (int i=0; i<n; i++) {
            uf.join(i, p[i]);
        }

        for (int i=1; i<n-1; i++) {
            if (!uf(i, i+1)) {
                sol.emplace_back(i, i+1);
                uf.join(i, i+1);
                swap(p[i], p[i+1]);
            }
        }

        while (p[0]) {
            int x = 0;
            int y = p[0];
            sol.emplace_back(x, y);
            swap(p[x], p[y]);
        }

        return sol;
    }

    void little_test() {
        for (int n=2; n<=7; n++) {
            vector<int> p(n);
            iota(begin(p), end(p), 0);
            do {
                if (p[0] == 0) continue;
                auto s = sort_permutation(p);
                auto q = p;
                set<pair<int, int>> se;
                for (auto [x, y] : s) {
                    se.insert(x < y ? make_pair(x, y) : make_pair(y, x));
                }
                int ok = se.size() == s.size();
                for (auto [x, y] : s) {
                    if (x == y) ok = 0;
                    swap(q[x], q[y]);
                }

                ok &= is_sorted(begin(q), end(q));

                if (!ok) {
                    cerr << "Failed\n";
                    exit(1);
                }            
            } while (next_permutation(begin(p), end(p)));
        }
    }

    void main() {
        int n;
        cin >> n;
        vector<pt> a(n);
        vector<int> lbl(n), bad;
        for (int i=0; i<n; i++) {
            cin >> a[i].x >> a[i].y >> lbl[i];
            lbl[i]--;
            if (i != lbl[i]) {
                bad.push_back(i);
            }
        }

        if (bad.empty()) {
            cout << "0\n";
            return;
        }

        auto baseit = min_element(begin(bad), end(bad), [&](int i, int j) { return cmp_lex(a[i], a[j]); });
        iter_swap(baseit, bad.begin());
        sort(begin(bad) + 1, end(bad), [&](int i, int j) { return det(a[bad[0]], a[i], a[j]) < 0; });

        vector<int> bad_inv(n), perm;
        for (int i=0; i<(int)bad.size(); i++) {
            bad_inv[bad[i]] = i;
        }

        for (int x : bad) {
            perm.push_back(bad_inv[lbl[x]]);
        }

        auto sol = sort_permutation(perm);
        cout << sol.size() << '\n';
        for (auto [x, y] : sol) {
            cout << bad[x]+1 << ' ' << bad[y]+1 << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    sol::main();
}