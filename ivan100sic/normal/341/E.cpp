// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

int n;
int a[1005];

vector<pair<int, int>> solve3(int a1, int a2, int a3) {
    int sum = a1 + a2 + a3;
    struct info {
        int x, y, p;
    };
    vector<info> q = {{a1, a2, -1}};
    int qs = 0;
    while (qs != ssize(q)) {
        auto [x, y, _p] = q[qs++];
        int a[3] = {x, y, sum-x-y};
        for (int i : ra(0, 3)) {
            for (int j : ra(0, 3)) {
                if (i != j && tie(a[i], i) < tie(a[j], j)) {
                    int b[3] = {a[0], a[1], a[2]};
                    b[j] -= b[i];
                    b[i] += b[i];
                    if (R::count(b, 0)) {
                        // solution found
                        vector<pair<int, int>> sol = {{i, j}};
                        int p = qs-1;
                        while (p != -1) {
                            int z = q[p].p;
                            int ii = z & 3, jj = (z >> 2) & 3, pp = z >> 4;
                            p = pp;
                            if (p == -1) break;
                            sol.emplace_back(ii, jj);
                        }
                        R::reverse(sol);
                        return sol;
                    }
                    q.push_back({b[0], b[1], i + 4*j + 16*(qs-1)});
                }
            }
        }
    }

    cout << "failed\n";
    return {};
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    cin >> n;
    for (int i : ra(1, n+1)) cin >> a[i];

    if (count(a+1, a+n+1, 0) > n-2) {
        cout << "-1\n";
        return 0;
    }

    vector<set<int>> tzm(20);
    int nz = 0;
    auto tzm_add = [&](int i) {
        if (a[i] != 0) {
            nz++;
            tzm[countr_zero(0u + a[i])].insert(i);
        }
    };

    auto tzm_rem = [&](int i) {
        if (a[i] != 0) {
            nz--;
            tzm[countr_zero(0u + a[i])].erase(i);
        }
    };

    vector<pair<int, int>> sol;
    auto mv = [&](int i, int j) {
        if (a[i] > a[j]) swap(i, j); // swap only if actually bad
        sol.emplace_back(i, j);
        a[j] -= a[i];
        a[i] += a[i];
    };

    for (int i : ra(1, n+1)) tzm_add(i);

    while (nz > 2) {
        bool f = 0;
        for (int w : ra(0, 20)) {
            while (tzm[w].size() >= 2) {
                int i = *tzm[w].begin();
                int j = *next(tzm[w].begin());

                tzm_rem(i);
                tzm_rem(j);
                mv(i, j);
                tzm_add(i);
                tzm_add(j);
                f = 1;
            }
        }

        if (!f) break;
    }

    while (count(a+1, a+n+1, 0) != n-2) {
        vector<int> q;
        for (int i : ra(1, n+1)) {
            if (q.size() != 3 && a[i]) {
                q.push_back(i);
            }
        }

        auto subsol = solve3(a[q[0]], a[q[1]], a[q[2]]);
        for (auto [i, j] : subsol) {
            mv(q[i], q[j]);
        }
    }

    cout << sol.size() << '\n';
    for (auto [i, j] : sol) cout << i << ' ' << j << '\n';    
}