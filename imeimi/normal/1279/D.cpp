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
typedef long long llong;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<llong, llong> pll;
typedef pair<ld, ld> pdd;

const int mod = 998244353;

llong pw(llong x, llong p) {
    llong r = 1;
    while (p) {
        if (p & 1) r = r * x % mod;
        x = x * x % mod;
        p >>= 1;
    }
    return r;
}

int n;
int cnt[1000001];
vector<int> A[1000001];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(30); cout << fixed;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int k;
        cin >> k;
        A[i].resize(k);
        while (k--) {
            cin >> A[i][k];
            ++cnt[A[i][k]];
        }
    }
    llong ans = 0;
    for (int i = 1; i <= n; ++i) {
        llong p = 0;
        for (int j : A[i]) {
            p += cnt[j];
        }
        p = p % mod * pw(A[i].size(), mod - 2) % mod;
        ans += p;
;    }
    ans = ans % mod * pw(n, mod - 2 << 1) % mod;
    printf("%lld\n", ans);
    return 0;
}