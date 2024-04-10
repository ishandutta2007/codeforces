#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, l, r;
    cin >> n >> l >> r;
    int ans = 0;
    int tmp = 1;
    for (int i = 0; i < l; i++) {
        ans += tmp;
        tmp *= 2;
    }
    cout << ans + n - l << " ";
    ans = 0;
    tmp = 1;
    for (int i = 0; i < r; i++) {
        ans += tmp;
        tmp *= 2;
    }
    cout << ans + (n - r) * tmp / 2;
}