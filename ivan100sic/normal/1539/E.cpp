// Retired?
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

const int ERASE = 1;
const int INSERT = 2;
const int SET = 3;

struct ds_rb {
    // (x, c)
    // (c, y)
    set<int> sx, sy;
    int c;

    struct rb {
        int op;
        set<int>* t;
        int v;
    };

    vector<vector<rb>> steps;

    void unroll(const rb& r) {
        if (r.op == ERASE) {
            r.t->erase(r.v);
        } else if (r.op == INSERT) {
            r.t->insert(r.v);
        } else {
            c = r.v;
        }
    }

    void unroll(int i) {
        for (int j = (int)steps[i].size() - 1; j >= 0; j--) {
            unroll(steps[i][j]);
        }
    }

    int hasx(int y) {
        // neko sa sx?
        if (y == c && sx.size()) {
            return *sx.begin();
        }

        // neko sa sy?
        if (sy.count(y)) {
            return c;
        }

        return -1;
    }

    int hasy(int x) {
        if (x == c && sy.size()) {
            return *sy.begin();
        }

        if (sx.count(x)) {
            return c;
        }

        return -1;
    }

    void do_step(int k, int l, int r, int u, int v) {
        vector<rb> step;
        bool sxs = sx.size();
        bool sys = sy.size();

        if (sxs && !sy.count(c)) {
            sy.insert(c);
            step.push_back({ERASE, &sy, c});
        }

        if (sys && !sx.count(c)) {
            sx.insert(c);
            step.push_back({ERASE, &sx, c});
        }

        step.push_back({SET, nullptr, c});
        c = k;

        // remove x
        while (sx.size() && (*sx.begin() < l || c < u || c > v)) {
            step.push_back({INSERT, &sx, *sx.begin()});
            sx.erase(sx.begin());
        }

        while (sx.size() && (*prev(sx.end()) > r || c < u || c > v)) {
            step.push_back({INSERT, &sx, *prev(sx.end())});
            sx.erase(prev(sx.end()));
        }

        // remove y
        while (sy.size() && (*sy.begin() < u || c < l || c > r)) {
            step.push_back({INSERT, &sy, *sy.begin()});
            sy.erase(sy.begin());
        }

        while (sy.size() && (*prev(sy.end()) > v || c < l || c > r)) {
            step.push_back({INSERT, &sy, *prev(sy.end())});
            sy.erase(prev(sy.end()));
        }

        steps.push_back(step);
    }
};

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int n, m;
    cin >> n >> m;

    ds_rb ds;
    ds.c = 0;
    ds.sx.insert(0);
    ds.sy.insert(0);

    for (int i=0; i<n; i++) {
        int k, l, r, u, v;
        cin >> k >> l >> r >> u >> v;
        ds.do_step(k, l, r, u, v);
    }

    int x = -1, y = -1;
    if (ds.sx.size()) {
        x = *ds.sx.begin();
        y = ds.c;
    } else if (ds.sy.size()) {
        x = ds.c;
        y = *ds.sy.begin();
    } else {
        cout << "No\n";
        return 0;
    }

    cout << "Yes\n";
    vector<int> ans(n);
    for (int i=n-1; i>=0; i--) {
        int cafter = ds.c, ok = 0;
        ds.unroll(i);
        if (x == cafter) {
            int hx = ds.hasx(y);
            if (hx != -1) {
                x = hx;
                ans[i] = 0;
                ok = 1;
            }
        }

        if (y == cafter && !ok) {
            int hy = ds.hasy(x);
            if (hy != -1) {
                y = hy;
                ans[i] = 1;
                ok = 1;
            }
        }

        if (!ok) {
            cout << "Assertion failed: " << i << '\n';
            return 0;
        }
    }

    for (int x : ans) {
        cout << x << ' ';
    }
    cout << '\n';
}