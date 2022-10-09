// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

int n;
int x[100005], y[100005], t[100005];

int sq(int x) {
    return x*x;
}

int d2(int i, int j) {
    return sq(x[i] - x[j]) + sq(y[i] - y[j]);
}

struct minpair {
    int i, j;

    int d() const {
        return d2(i, j);
    }

    auto operator<=> (const minpair& b) const {
        return d() <=> b.d();
    }
};

minpair solve(vector<int> sx) {
    if (sx.size() == 1) {
        return {0, n};
    }

    if (sx.size() == 2) {
        return {sx[0], sx[1]};
    }

    int h = sx.size() / 2;
    vector<int> xl(begin(sx), begin(sx) + h);
    vector<int> xr(begin(sx) + h, end(sx));

    auto ss = min(solve(xl), solve(xr));
    int xg = x[sx[h]];
    
    vector<int> w;
    for (int i : sx) {
        if (sq(x[i] - xg) <= ss.d()) {
            w.push_back(i);
        }
    }

    R::sort(w, {}, [](int i) { return y[i]; });

    for (int i : ra(0, ssize(w))) {
        for (int j : ra(i+1, min((int)size(w), i+8))) {
            ss = min(ss, minpair{w[i], w[j]});
        }
    }

    return ss;
}

int main() {
#ifdef LOCAL
    ios::sync_with_stdio(!cin.tie(0));
#else
    ifstream cin("input.txt");
    ofstream cout("output.txt");
#endif

    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> x[i] >> y[i];
        if (x[i] < 0 && y[i] < 0) {
            t[i] = 4;
        } else if (x[i] < 0) {
            t[i] = 2;
        } else if (y[i] < 0) {
            t[i] = 3;
        } else {
            t[i] = 1;
        }
        x[i] = abs(x[i]);
        y[i] = abs(y[i]);
    }
    x[n] = y[n] = 30000;

    vector<int> sx(n);
    iota(begin(sx), end(sx), 0);

    R::sort(sx, {}, [](int i) { return x[i]; });
    auto [i, j] = solve(sx);

    cout << i+1 << ' ' << t[i] << ' ' << j+1 << ' ' << 5-t[j] << '\n';
}