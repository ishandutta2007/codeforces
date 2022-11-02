#include "bits/stdc++.h"
#define ll long long
#define MOD 1000000007
ll power(ll x, ll y, ll md = MOD) {
    ll res = 1;
    x %= md;
    while (y) {
        if (y & 1) res = (res * x) % md;
        x *= x;
        if (x >= md) x %= md;
        y >>= 1;
    }
    return res;
}
using namespace std;
#define int long long
#define MAX 100005
vector<int> f(MAX);
vector<int> inv(MAX);
void init() {
    f[0] = 1;
    for (int i = 1; i < MAX; i++) f[i] = (f[i - 1] * i) % MOD;
    inv[MAX - 1] = power(f[MAX - 1], MOD - 2, MOD);
    for (int i = MAX - 2; i >= 0; i--) inv[i] = (inv[i + 1] * (i + 1)) % MOD;
    for (int i = 0; i < MAX; i++) assert(inv[i] == power(f[i], MOD - 2, MOD));
}
int ncr(int n, int r) {
    if (r > n || r < 0) return 0;
    int ans = f[n];
    ans *= (inv[r] * inv[n - r]) % MOD;
    ans %= MOD;
    return ans;
}
int solve(const vector<int> &v) {
    int n = v.size();
    int s = 0;
    for (auto x : v) s += x;
    if (!(s % n == 0)) return 0;
    int src = 0;
    int snk = 0;
    map<int, int> freqSrc, freqSnk;
    for (auto x : v) {
        if (s / n < x) {
            freqSrc[x]++;
            src++;
        }
        if (s / n > x) {
            freqSnk[x]++;
            snk++;
        }
    }
    if (src == 0 && snk == 0) return 1;
    if (src == 1 || snk == 1) {
        int ans = f[n];
        for (auto x : freqSnk) {
            ans = (ans * inv[x.second]) % MOD;
        }
        for (auto x : freqSrc) {
            ans = (ans * inv[x.second]) % MOD;
        }
        ans *= inv[n - src - snk];
        ans %= MOD;
        return ans;
    }
    int ans = (2 * f[src] * f[snk]) % MOD;
    for (auto x : freqSnk) {
        ans = (ans * inv[x.second]) % MOD;
    }
    for (auto x : freqSrc) {
        ans = (ans * inv[x.second]) % MOD;
    }
    int tot = src + snk;
    int left = n - tot;
    ans = (ans * ncr(left + tot, tot)) % MOD;
    return ans;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    init();
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &x : v) cin >> x;
    cout << solve(v);
}