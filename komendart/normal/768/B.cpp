#include <bits/stdc++.h>

using namespace std;

#define int long long

int f(int x) {
    if (x <= 1) return 1;
    return 1 + 2 * f(x / 2);
}

int solve(int n, int l, int r) {
    int sz = f(n);
    l = max(1LL, l);
    r = min(r, sz);
    if (l > r || l > sz) {
        return 0;
    }
    if (n <= 1) {
        return n;
    }
    sz = f(n / 2);
    int ans = solve(n / 2, l, r) +
              solve(n % 2, l - sz, r - sz) +
              solve(n / 2, l - sz - 1, r - sz - 1);
    return ans;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n, l, r;
    cin >> n >> l >> r;
    cout << solve(n, l, r);
}