#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

const int mxn = 2e5 + 5, mxk = 5;
const int mod = 1e9 + 7;

inline int qpow(int x, int n) {
    int ans = 1;
    for (; n; n >>= 1, x = 1LL * x * x % mod)
        if (n & 1) ans = 1LL * ans * x % mod;
    return ans;
}

int n, q;
int a[mxn];

struct Query {
    int l, d, i;
};

std::vector <Query> qry[mxn];

struct BIT {
    int s[mxn];

    void update(int x, int v) {
        for (++ x; x < mxn; x += x & -x) s[x] = (s[x] + v) % mod;
    }

    int query(int x) {
        int ans = 0;
        for (++ x; x; x -= x & -x) ans = (ans + s[x]) % mod;
        return ans;
    }
} bit[mxk];

int calc(int l, int r, int k) {
    return (bit[k].query(r) + mod - bit[k].query(l - 1)) % mod;
}

int binom[mxk][mxk];
int pref[mxn][mxk];

struct __INIT__ {
    __INIT__() {
        rep(i, mxk) rep(j, i + 1) binom[i][j] = j ? binom[i - 1][j - 1] + binom[i - 1][j] : 1;
        rep(i, mxn) rep(j, mxk) pref[i + 1][j] = (pref[i][j] + qpow(i, j)) % mod;
    }
} __;

int calc_real(int l, int r, int d, int k) {
    int sum = calc(l, r, 1);
    // (start + (start + (r-l) d)) * (r-l+1) / 2 = sum
    int rest = (sum + mod - 1LL * ((1LL * (r - l + 1) * (r - l) / 2) % mod) * d % mod) % mod;
    int start = 1LL * rest * qpow(r - l + 1, mod - 2) % mod;
    // i in [0, r-l]: (start+id)^k
    // sum_i sum_j binom(k,j) start^j (id)^{k-j}
    // sum_j binom(k,j) start^j d^{k-j} sum_i i^{k-j}
    int ans = 0;
    rep(j, k + 1) ans = (ans + 1LL * binom[k][j] * qpow(start, j) % mod * qpow(d, k - j) % mod * pref[r - l + 1][k - j]) % mod;
    return ans;
}

bool ans[mxn];

int main() {
    scanf("%d %d", &n, &q);
    rep(i, n) scanf("%d", &a[i]);
    rep(i, q) {
        int l, r, d;
        scanf("%d %d %d", &l, &r, &d);
        -- l, -- r;
        qry[r].push_back({l, d, i});
    }
    std::map <int, int> last;
    rep(r, n) {
        if (last.find(a[r]) != last.end()) {
            rep(k, mxk) bit[k].update(last[a[r]], mod - qpow(a[r], k));
        }
        last[a[r]] = r;
        rep(k, mxk) bit[k].update(r, qpow(a[r], k));
        for (auto Q : qry[r]) {
            int l = Q.l, d = Q.d, i = Q.i;
            ans[i] = true;
//            rep(k, mxk) eprintf("[%d, %d] %d %d\n", l + 1, r + 1, calc(l, r, k), calc_real(l, r, d, k));
            rep(k, mxk) ans[i] &= calc(l, r, k) == calc_real(l, r, d, k);
        }
    }
    rep(i, q) puts(ans[i] ? "Yes" : "No");
    return 0;
}