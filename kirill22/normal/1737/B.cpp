#include "bits/stdc++.h"

using namespace std;

long long S(long long x) {
    long long l = 1, r = (long long) 1e9 + 1;
    while (l + 1 < r) {
        long long m = (l + r) / 2;
        if (m * m <= x) {
            l = m;
        } else {
            r = m;
        }
    }
    return l;
}

void solve() {
    long long l, r;
    cin >> l >> r;
    long long x = S(l);
    long long y = S(r);
    long long ans = 0;
    for (auto z : {x * x, x * x + x, x * x + x + x}) {
        if (l <= z && z <= r) {
            ans++;
        }
    }
    if (x != y) {
        x = y;
        for (auto z : {x * x, x * x + x, x * x + x + x}) {
            if (l <= z && z <= r) {
                ans++;
            }
        }
        x = sqrtl(l);
        ans += (y - x - 1) * 3ll;
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}