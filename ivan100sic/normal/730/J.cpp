// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

struct bottle {
    int a, b;
} a[105];

int n;
int dp[105][10005];

void mx(int& x, int y) {
    x = max(x, y);
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    cin >> n;
    for (int i : ra(0, n)) {
        cin >> a[i].a;
    }
    for (int i : ra(0, n)) {
        cin >> a[i].b;
    }

    R::sort(R::reverse_view(R::subrange(a, a+n)), {}, &bottle::b);
    int z = 0;
    for (int i : ra(0, n)) {
        z += a[i].a;
    }

    int zt = z, k = n;
    for (int i=0; i<n; i++) {
        if (zt == 0) {
            k = i;
            break;
        }
        zt -= min(zt, a[i].b);
    }

    // k bottles, tot. cap >= z, max. total content
    memset(dp, 192, sizeof(dp));
    dp[0][0] = 0;

    for (int i=0; i<n; i++) {
        for (int j=k-1; j>=0; j--) {
            for (int c=0; c<=100*i; c++) {
                mx(dp[j+1][c+a[i].b], dp[j][c] + a[i].a);
            }
        }
    }

    int sol = 0;
    for (int c : ra(z, 10005)) {
        sol = max(sol, dp[k][c]);
    }

    cout << k << ' ' << z - sol << '\n';
}