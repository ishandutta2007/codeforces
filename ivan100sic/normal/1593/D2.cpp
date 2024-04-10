// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

vector<int> divisors(int n) {
    set<int> s;
    for (int x=1; x*x<=n; x++) {
        if (n % x == 0) {
            s.insert(x);
            s.insert(n / x);
        }
    }

    return vector<int>(begin(s), end(s));
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);

        for (int& x : a) cin >> x;

        map<int, int> mp;
        for (int x : a) mp[x]++;

        int sol = 0;

        for (auto [k, v] : mp) {
            if (v >= n / 2) {
                sol = -1;
                break;
            }
        }

        if (sol == -1) {
            cout << sol << '\n';
            continue;
        }

        for (int i : ra(0, n)) {
            for (int j : ra(i+1, n)) {
                if (a[i] == a[j]) continue;

                for (int d : divisors(abs(a[i] - a[j]))) {
                    int c = 0;
                    for (int k : ra(0, n)) {
                        if ((a[k] - a[i]) % d == 0) {
                            c++;
                        }
                    }

                    if (c >= n / 2) {
                        sol = max(sol, d);
                    }
                }
            }
        }

        cout << sol << '\n';
    }
    
}