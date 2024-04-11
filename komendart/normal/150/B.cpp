#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MOD = 1e9 + 7;

int power(int x, int p) {
    if (p == 0) return 1 % MOD;
    if (p & 1) return x * power(x, p - 1) % MOD;
    return power(x * x % MOD, p >> 1);
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    if (k == 1 || k > n) {
        cout << power(m, n) << '\n';
    } else if (k == n) {
        cout << power(m, (n + 1) / 2);
    } else if (k % 2 == 0) {
        cout << power(m, 1) << '\n';
    } else {
        cout << power(m, 2) << '\n';
    }

}