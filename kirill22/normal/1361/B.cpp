#include<bits/stdc++.h>

using namespace std;

#define int long long
#define pii pair<int, int>
#define pb push_back
#define fi first
#define se second

int mod = 1e9 + 7;

int binpow(int x, int n) {
    if (n == 0) return 1 % mod;
    int res = 1;
    if (n % 2 == 1) res *= x;
    return (binpow((x * x) % mod, n / 2) * res) % mod;
}

void solve() {
    int n, p;
    cin >> n >> p;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    if (p == 1) {
        cout << n % 2 << endl;
        return;
    }
    while (true) {
        int n = a.size();
        int res = a[n - 1] - a[n - 2], lst = a[n - 2];
        int x = 1;
        for (int i = 0; i < res; i++) {
            if (x * p > 1e10) {
                x *= p; break;
            }
            x *= p;
        }
        if (x > n - 1) break;
        bool f = true;
        int l = -1;
        for (int j = n - 2; j >= 0; j--) {
            res = lst - a[j];
            lst = a[j];
            for (int i = 0; i < res; i++) {
                if (x * p > 1e10) {
                    x *= p; break;
                }
                x *= p;
            }
            if (x > j + 1) {
                f = false;
                break;
            }
            x--;
            if (x == 0) {
                l = j;
                break;
            }
        }
        if (!f) break;
        for (int i = l; i < n; i++) a.pop_back();
    }
    int ans = 0;
    if (a.size() > 0) {
        ans = binpow(p, a.back());
        for (int i = 0; i < (int) a.size() - 1; i++) {
            ans = (ans - binpow(p, a[i]) + mod) % mod;
        }
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> q;
    while (q--) {
        solve();
    }
}