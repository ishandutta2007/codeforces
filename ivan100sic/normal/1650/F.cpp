// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

struct option {
    int t, p, id;
};

pair<vector<int>, int> dp_solve(span<option> a, int cap) {
    const int n = a.size();
    vector d(n+1, vector(101, 1123123123));
    vector p(n+1, vector(101, -1));
    const int FLAG = 8192;
    d[0][0] = 0;
    for (int i : ra(0, n)) {
        for (int j : ra(0, 101)) {
            for (int take : {0, 1}) {
                int i2 = i+1;
                int j2 = min(100, j + take*a[i].p);
                int d2 = d[i][j] + take*a[i].t;
                if (d2 < d[i2][j2]) {
                    d[i2][j2] = d2;
                    p[i2][j2] = j | take*FLAG;
                }
            }
        }
    }

    if (d[n][100] > cap) {
        return {{}, 0};
    }

    vector<int> sol;
    int j = 100, th = 0;
    for (int i=n; i>=1; i--) {
        if (p[i][j] & FLAG) {
            sol.push_back(a[i-1].id);
            th += a[i-1].t;
            j = p[i][j] - FLAG;
        } else {
            j = p[i][j];
        }
    }

    return {sol, th};
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        for (int& x : a) cin >> x;

        vector<vector<option>> e(n);
        for (int i : ra(0, m)) {
            int ei, t, p;
            cin >> ei >> t >> p;
            e[ei-1].push_back({t, p, i+1});
        }

        bool bad = 0;
        vector<int> sol;
        int used = 0;
        for (int i : ra(0, n)) {
            auto [v, th] = dp_solve(e[i], a[i] - used);
            if (v.empty()) {
                bad = 1;
                break;
            } else {
                used += th;
                sol.insert(sol.end(), begin(v), end(v));
            }
        }

        if (bad) {
            cout << "-1\n";
        } else {
            cout << size(sol) << '\n';
            for (int x : sol) {
                cout << x << ' ';
            }
            cout << '\n';
        }
    }
}