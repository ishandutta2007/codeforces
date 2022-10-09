// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<pair<int, int>> a(n);
        for (int i : ra(0, n)) {
            cin >> a[i].first;
            a[i].second = i;
        }

        vector<int> sol(n);

        R::sort(a);

        if (a[0].first == a[n-1].first) {
            R::fill(sol, 1);
            sol[0] = -(n-1);
        } else {
            int j0 = -1, j1 = -1;
            if (n % 2) {
                int idx = 0;
                for (int i : ra(0, n-1)) {
                    int d = a[i+1].first - a[i].first;
                    if (d != 0) {
                        idx = i;
                        break;
                    }
                }

                auto [v0, i0] = a[idx];
                auto [v1, i1] = a[idx+1];
                a.erase(a.begin() + idx, a.begin() + idx + 2);

                a.emplace_back(v1-v0, -1);
                tie(j0, j1) = tie(i0, i1); 
            }

            auto setsol = [&](int i, int v) {
                if (i == -1) {
                    sol[j0] = -v;
                    sol[j1] = v;
                } else {
                    sol[i] = v;
                }
            };

            for (int i : ra(0, n/2)) {
                int u = a[2*i].first;
                int v = -a[2*i+1].first;
                int g = gcd(u, v);
                u /= g;
                v /= g;
                setsol(a[2*i+1].second, u);
                setsol(a[2*i].second, v);
            }
        }

        for (int x : sol) {
            cout << x << ' ';
        }
        cout << '\n';
    }
    
}