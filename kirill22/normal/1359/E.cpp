#include<bits/stdc++.h>

using namespace std;

#define int long long
#define fi first
#define se second
#define pii pair<int, int>
#define all(a) a.begin(), a.end()

const int mod = 998244353;

int binpow(int x, int n) {
    if (n == 0) return 1 % mod;
    int res = 1;
    if (n % 2 == 1) res *= x;
    return (binpow((x * x) % mod, n / 2) * res) % mod;
}

void solve() {
    int n, k;
    cin >> n >> k;
    if (k == 1) {
        cout << n;
        return;
    }
    if (n < k) {
        cout << 0;
        return;
    }
    int ans = 0;
    int tmp = 1, pr = n - 1;
    for (int i = 1; i <= n - 1; i++) tmp = (tmp * i) % mod;
    for (int i = 1; i <= k - 1; i++) tmp = (tmp * binpow(i, mod - 2)) % mod;
    for (int i = 1; i <= n - k; i++) tmp = (tmp * binpow(i, mod - 2)) % mod;
    ans += tmp;
    for (int i = 2; i <= n; i++) {
        int cnt = n / i;
        if (cnt < k) continue;
        cnt--;
        while (pr > cnt) {
            tmp = (tmp * binpow(pr, mod - 2)) % mod;
            tmp = (tmp * (pr - k + 1)) % mod;
            pr--;
        }
        //cout << tmp << endl;
        ans = (tmp + ans) % mod;
    }
    cout << ans;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}