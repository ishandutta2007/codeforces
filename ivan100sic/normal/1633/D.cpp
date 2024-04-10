// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

int d[1005];

void init_d() {
    queue<int> q;
    q.push(1);
    R::fill(d, -1);
    d[1] = 0;
    while (q.size()) {
        int a = q.front();
        q.pop();
        for (int x=1; x<=a; x++) {
            int b = a + a/x;
            if (b <= 1000 && d[b] == -1) {
                d[b] = d[a] + 1;
                q.push(b);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    init_d();

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> b(n), c(n);
        for (int& x : b) cin >> x;
        for (int& y : c) cin >> y;

        const int h = min(12*n + 5, k+1);
        vector<int> dp(h, -1e9), nu;
        dp[0] = 0;
        
        for (int i : ra(0, n)) {
            nu = dp;
            for (int j=0; j<h; j++) {
                int t = j + d[b[i]];
                if (t < h) {
                    nu[t] = max(nu[t], dp[j] + c[i]);
                }
            }
            swap(dp, nu);
        }

        cout << *R::max_element(dp) << '\n';
    }
}