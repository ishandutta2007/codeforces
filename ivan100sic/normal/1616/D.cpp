// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

template<class T = int>
struct maxval {
    T x;
    maxval(T x = numeric_limits<T>::min()) : x(x) {}
    T operator() () const { return x; }
    maxval operator+ (const maxval& b) const { return max(x, b.x); }
    maxval& operator+= (const maxval& b) { x = max(x, b.x); return *this; }
};

using mvi = maxval<int>;

mvi dp[50005][3];

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int& x : a) cin >> x;
        {
            int x;
            cin >> x;
            for (int& y : a) y -= x;
        }

        array<array<mvi, 3>, 50005> dp;
        dp[0][0] = 0;
        
        for (int i=0; i<n; i++) {
            for (int j : {0, 1, 2}) {
                // don't take
                dp[i+1][0] += dp[i][j];

                // take
                bool ok;
                if (j == 1) {
                    ok = i > 0 && a[i-1] + a[i] >= 0;
                } else if (j == 2) {
                    ok = i > 1 && a[i-2] + a[i-1] + a[i] >= 0 && a[i-1] + a[i] >= 0;
                } else {
                    ok = true;
                }

                if (ok) {
                    dp[i+1][min(2, j+1)] += dp[i][j]() + 1;
                }
            }
        }

        cout << (dp[n][0] + dp[n][1] + dp[n][2])() << "\n";
    }
}