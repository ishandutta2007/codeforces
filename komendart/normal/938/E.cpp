#include <bits/stdc++.h>

using namespace std;

#define int long long
#define sz(x) ((int) (x).size())

const int mod = 1e9 + 7;
const int maxn = 1e6 + 5;

int binpow(int x, int p) {
    if (p == 0) return 1;
    if (p & 1) return x * binpow(x, p - 1) % mod;
    return binpow(x * x % mod, p >> 1);
}

int inv(int x) {
    return binpow(x, mod - 2);
}

int fac[maxn];
int invfac[maxn];

/*int cnk(int n, int k) {
    if (k < 0 || k > n) return 0;
    return fac[n] * invfac[k] % mod * invfac[n - k] % mod;
}

void naive(vector<int> a) {
    vector<int> p(sz(a));
    for (int i = 0; i < sz(a); ++i) p[i] = i;
    sort(a.begin(), a.end());
    for (auto i: a) cerr << i << ' ';
    cerr << endl;
    int ans = 0;
    do {
        int mx = 0;
        for (auto i: p) {
            if (a[i] > mx) ans += mx, mx = a[i];
        }
    } while (next_permutation(p.begin(), p.end()));
    cout << ans % mod << endl;
}*/

signed main() {
    //freopen("t.in", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0);

    fac[0] = 1;
    for (int i = 1; i < maxn; ++i) {
        fac[i] = fac[i - 1] * i % mod;
    }
    invfac[maxn - 1] = inv(fac[maxn - 1]);
    for (int i = maxn - 2; i >= 0; --i) {
        invfac[i] = invfac[i + 1] * (i + 1) % mod;
    }

    int n;
    //srand(time(0));
    cin >> n;
    //n = 10;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        //a[i] = 1 + rand() % 4;
    }
    sort(a.rbegin(), a.rend());
    vector< pair<int, int> > g;
    for (int i = 0; i < n; ++i) {
        if (i == 0 || a[i] != a[i - 1]) {
            g.emplace_back(a[i], 1);
        } else {
            ++g.back().second;
        }
    }
    int sum = 0;
    int ans = 0;
    for (auto it: g) {
        int cnt = it.second, val = it.first;
        sum += cnt;
        //cerr << cnt << ' ' << val << endl;
        if (val == g[0].first) continue;
        int x = val * cnt % mod * fac[sum - 1] % mod;
        int y = fac[sum] * invfac[sum - cnt] % mod * ans % mod;
        ans = (x + y) % mod;
    }
    cout << ans << '\n';

}