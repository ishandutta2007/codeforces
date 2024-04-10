// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

struct scc {
    vector<vector<int>> e;
    vector<int> i, l, s;
    string p;
    int t;

    scc(int n) : e(n) {}

    void init() {
        i = l = vector<int>(e.size());
        p = string(e.size(), 0);
        t = 0;
    }

    void add_edge(int x, int y) {
        e[x].push_back(y);
    }

    template<class B, class A>
    void dfs(int x, B b, A a) {
        i[x] = l[x] = ++t;
        s.push_back(x);
        p[x] = 1;
        for (int y : e[x]) {
            if (!i[y]) {
                dfs(y, b, a);
                l[x] = min(l[x], l[y]);
            } else if (p[y]) {
                l[x] = min(l[x], i[y]);
            }
        }

        if (i[x] == l[x]) {
            b();
            while (1) {
                int y = s.back();
                s.pop_back();
                p[y] = 0;
                a(y);
                if (y == x) break;
            }
        }
    }

    template<class B, class A>
    void run(B b, A a) {
        for (int x=0; x<(int)e.size(); x++) {
            if (!i[x]) {
                dfs(x, b, a);
            }
        }
    }

    vector<vector<int>> components() {
        init();
        vector<vector<int>> z;
        run([&]() { z.emplace_back(); }, [&](int x) { z.back().push_back(x); });
        return z;
    }

    vector<int> colors() {
        init();
        vector<int> c = i;
        int k = -1;
        run([&]() { k++; }, [&](int x) { c[x] = k; });
        return c;
    }
};

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int& x : a) cin >> x;
        for (int& y : b) cin >> y;

        vector<int> iot(n);
        iota(begin(iot), end(iot), 0);

        auto cmp = [&](auto& a) {
            return [&](int i, int j) { return a[i] < a[j]; };
        };

        scc eng(n);

        R::sort(iot, cmp(a));
        for (int i : ra(1, n)) eng.add_edge(iot[i-1], iot[i]);
        R::sort(iot, cmp(b));
        for (int i : ra(1, n)) eng.add_edge(iot[i-1], iot[i]);

        string sol(n, '0');
        auto comps = eng.components();
        for (int x : comps[0]) {
            sol[x] = '1';
        }

        cout << sol << '\n';
    }
}