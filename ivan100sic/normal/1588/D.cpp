// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

struct descr {
    ull a[2];

    descr() {
        R::fill(a, 0);
    }

    void add(int p, int v) {
        if (p < 8) a[0] += ull(v) << 8*p;
        else a[1] += ull(v) << 8*(p-8);
    }

    int operator[] (int p) const {
        if (p < 8) return (a[0] >> 8*p) & 0xff;
        else return (a[1] >> 8*(p-8)) & 0xff;
    }

    auto operator<=> (const descr& b) const = default;
};

int let(char x) {
    if (islower(x)) return x-'a';
    return 26 + x-'A';
}

char letinv(int x) {
    if (x < 26) return x+'a';
    return x-26+'A';
}

int sled[105][52][10], n;

map<descr, pair<int, int>> cache;

void find_next(const descr& d, int l, auto&& cb) {
    descr t;
    for (int i : ra(0, n)) {
        int x = sled[d[i]][l][i];
        if (x == -1) {
            return;
        }
        t.add(i, x);
    }
    cb(t);
}

int solve(descr d) {
    auto& sol = cache[d];
    if (sol.second) {
        return sol.first;
    }

    sol.second = -1;
    for (int l : ra(0, 52)) {
        descr t;
        find_next(d, l, [&](descr t) {
            int s2 = 1 + solve(t);
            if (s2 > sol.first) {
                sol = {s2, l + 1000};
            }
        });
    }

    return sol.first;
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        memset(sled, 255, sizeof(sled));
        cache = {};
        cin >> n;
        vector<string> a(n);
        for (auto& s : a) cin >> s;

        for (int i : ra(0, n)) {
            for (int j : ra(0, ssize(a[i]))) {
                int k = let(a[i][j]);
                sled[j][k][i] = j+1;
            }
            
            for (int j = ssize(a[i]) - 1; j >= 0; j--) {
                for (int k : ra(0, 52)) {
                    if (sled[j][k][i] == -1) {
                        sled[j][k][i] = sled[j+1][k][i];
                    }
                }
            }
        }

        cout << solve({}) << '\n';
        for (descr d = {};;) {
            auto [s, l] = cache[d];
            if (l == -1) {
                cout << '\n';
                break;
            } else {
                l -= 1000;
                cout << letinv(l);
                find_next(d, l, [&](auto t) { d = t; });
            }
        }
    }
}