#include <bits/stdc++.h>

using namespace std;

int f(int n, int k) {
    if (k % 2 == 0) {
        if (n <= 2) return n;
        return 1 - n % 2;
    } else {
        if (n < 4) return n % 2;
        if (n == 4) return 2;
        if (n % 2 == 1) return 0;
        if (f(n / 2, k) == 1) return 2;
        return 1;
    }
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, k;
    cin >> n >> k;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int t; cin >> t;
        ans ^= f(t, k);
    }
    if (!ans) cout << "Nicky\n";
    else cout << "Kevin\n";
}