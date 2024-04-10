// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

vector<int> divs[1000005];

const int init_divs = [] {
    for (int d : ra(1, 1000005)) {
        for (int i=d; i<=1000004; i+=d) {
            divs[i].push_back(d);
        }
    }

    return 0;
}();

const int inf = 123123123;

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;

        cin >> n >> s;
        s = string(".") + s;

        vector<int> lo(n+1, inf);

        for (int d : ra(1, n+1)) {
            for (int i=d; i<=n; i+=d) {
                if (s[i] == '1' && lo[d] == inf) {
                    lo[d] = i;
                    break;
                }
            }
        }

        ll sol = 0;
        for (int i : ra(1, n+1)) {
            if (s[i] == '0') {
                for (int d : divs[i]) {
                    if (lo[d] > i) {
                        sol += d;
                        break;
                    }
                }
            }
        }

        cout << sol << '\n';
    }
}