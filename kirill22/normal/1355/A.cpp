#include <bits/stdc++.h>

using namespace std;

#define int long long
#define fi first
#define se second
#define ld long double

int mn(int x) {
    int mn = 9;
    while (x) {
        mn = min(mn, x % 10);
        x /= 10;
    }
    return mn;
}

int mx(int x) {
    int mn = 0;
    while (x) {
        mn = max(mn, x % 10);
        x /= 10;
    }
    return mn;
}

void solve() {
    int a, k;
    cin >> a >> k;
    k--;
    while (k--) {
        int p = mn(a), p2 = mx(a);
        if (p == 0) break;
        a += p * p2;
    }
    cout << a << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q; cin >> q; while (q--) solve();
}