// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

struct euler_tour {
    struct edge { list<int>::iterator p, q; int u, v; };
    vector<list<int>> e;
    vector<edge> f;
    euler_tour(int n) : e(n) {}
    void add_edge(int x, int y) {
        int i = f.size();
        e[x].push_back(i);
        e[y].push_back(i);
        f.push_back({--e[x].end(), --e[y].end(), x, y});
    }

    list<int> dfs(int x) {
        list<int> q;
        while (e[x].size()) {
            auto& l = f[e[x].back()];
            q.push_back(x);
            x ^= l.u ^ l.v;
            e[l.u].erase(l.p);
            e[l.v].erase(l.q);
        }
        for (auto it = q.begin(); it != q.end(); ++it) q.splice(it, dfs(*it));
        return q;
    }

    vector<int> operator()(int x) {
        auto q = dfs(x);
        return vector<int>(begin(q), end(q));
    }
};

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int n;
    cin >> n;

    euler_tour et(2*n);
    vector<int> loop(2*n);

    for (int i : ra(0, n)) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        if (x != y) {
            et.add_edge(x, y);
            et.add_edge(x, y);
        } else {
            loop[x] += 2;
        }
    }

    vector<array<int, 2>> sol(n);
    vector<string> g1(n), g2(n);
    int base = 0;

    for (int i : ra(0, 2*n)) {
        auto v_in = et(i);
        vector<int> v;
        for (int x : v_in) {
            v.push_back(x);
            while (loop[x] > 0) v.push_back(x), loop[x]--;
        }

        // correction
        if (v.empty() && loop[i] > 0) {
            v = vector(loop[i], i);
        }

        // if (v.size()) cerr << "! " << i+1 << ": " << v.size() << '\n';

        if (v.size() == 0) {
            // continue
        } else if (v.size() == 2) {
            // no sol
            cout << "-1\n";
            return 0;
        } else {
            int h = ssize(v) / 2;
            for (int i : ra(0, h)) {
                sol[base+i][0] = v[i];
            }
            for (int i : ra(0, h)) {
                sol[base+h-1-i][1] = v[i+h];
            }

            if (h % 2) {
                for (int i : ra(0, h-1)) {
                    g1[base + i] = i % 2 ? "DD" : "UU";
                    g2[base + i+1] = i % 2 ? "DD" : "UU";
                }
                g1[base + h-1] = "LR";
                g2[base] = "LR";
            } else {
                for (int i : ra(0, h)) {
                    g1[base + i] = i % 2 ? "DD" : "UU";
                }

                g2[base] = "LR";
                for (int i : ra(1, h-1)) {
                    g2[base + i] = i % 2 ? "UU" : "DD";
                }
                g2[base + h - 1] = "LR";
            }

            base += h;
        }
    }

    cout << n << " 2\n\n";
    for (int i : ra(0, n)) {
        cout << sol[i][0]+1 << ' ' << sol[i][1]+1 << '\n';
    }
    cout << '\n';
    for (int i : ra(0, n)) {
        cout << g1[i] << '\n';
    }
    cout << '\n';
    for (int i : ra(0, n)) {
        cout << g2[i] << '\n';
    }
}