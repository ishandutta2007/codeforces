#include <bits/stdc++.h>
#define fs first
#define se second
#define y0 qwertyuiop
#define y1 asdfghjkl

#ifdef imeimi
#define debug(...) printf(__VA_ARGS__)
#else
#define debug(...)
#endif

using namespace std;
typedef long long ll;
typedef long double lf;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<lf, lf> pff;

const int mod = 1e9 + 7, N = 1e6;
int f[N + 5];
int r[N + 5];

int mul(int x, int y) {
    return 1ll * x * y % mod;
}

int pw(int x, int p) {
    int r = 1;
    while (p) {
        if (p & 1) r = mul(r, x);
        x = mul(x, x);
        p >>= 1;
    }
    return r;
}

int nCr(int n, int k) {
    return mul(f[n], mul(r[k], r[n - k]));
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(30); cout << fixed;
    f[0] = r[0] = 1;
    for (int i = 1; i <= N; ++i) f[i] = mul(f[i - 1], i), r[i] = pw(f[i], mod - 2);
    int T;
    cin >> T;
    while (T--) {
        int n, m, k;
        cin >> n >> m >> k;
        if (n == m) {
            printf("%d\n", mul(n, k));
            continue;
        }
        m = n - m;
        int ans = 0;
        for (int i = 1; i <= n - m; ++i) {
            ans = (ans + mul(mul(mul(i, k), nCr(n - i - 1, m - 1)), pw(r[2], n - i))) % mod;
        }
        printf("%d\n", ans);
    }
    return 0;
}