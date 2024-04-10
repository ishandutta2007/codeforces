// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

struct mexer {
    set<int> s;
    int x = 0;
    void operator+= (int x) { s.insert(x); }
    int operator() () {
        while (s.count(x)) x++;
        return x;
    }
};

int n;
int a[105];
int mx[105][105];
int dp[105][105];

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i : ra(0, n)) cin >> a[i];
        for (int i : ra(0, n)) {
            mexer mxr;
            for (int j : ra(i, n)) {
                mxr += a[j];
                mx[i][j+1] = mxr();
            }
        }

        ll z = 0;
        for (int l : R::reverse_view(ra(0, n))) {
            for (int r : ra(l+1, n+1)) {
                dp[l][r] = mx[l][r] + 1;
                for (int k : ra(l+1, r)) {
                    dp[l][r] = max(dp[l][r], dp[l][k] + dp[k][r]);
                }
                z += dp[l][r];
            }
        }

        cout << z << '\n';
    }
}