#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

const int mul = 233;
const int mod = 1e9 + 7;
const int mod1 = 1e9 + 7;
const int mod2 = 1e9 + 9;
const int mxn = 2e6 + 5;

int qp(int x, int n = mod - 2) {
    int ans = 1;
    for (; n; n >>= 1, x = 1LL * x * x % mod)
        if (n & 1) ans = 1LL * ans * x % mod;
    return ans;
}

int pw1[mxn], pw2[mxn];

struct Hash {
    int a, b, len;

    Hash(): a(), b(), len() { }
    Hash(char _c): a(_c), b(_c), len(1) { }
    Hash(int _a, int _b, int _len): a(_a), b(_b), len(_len) { }

    bool operator == (const Hash &o) const {
        return a == o.a && b == o.b && len == o.len;
    }
};

Hash operator + (const Hash &a, const Hash &b) {
    return Hash(
        (1LL * a.a * pw1[b.len] + b.a) % mod1,
        (1LL * a.b * pw2[b.len] + b.b) % mod2,
        a.len + b.len
    );
}

Hash get_hash(Hash *pre, int l, int r) {
    return Hash(
        (pre[r].a + mod1 - 1LL * pre[l].a * pw1[r - l] % mod1) % mod1,
        (pre[r].b + mod2 - 1LL * pre[l].b * pw2[r - l] % mod2) % mod2,
        r - l
    );
}

int n, n0, q;
char s[25][mxn];
Hash pre[mxn];
int l[25];
char t[mxn];
int k;
char qs[mxn];
Hash qpre[mxn], qsuf[mxn];
int p2[mxn];
vector <int> vec[26];
vector <int> sum[26];

int get_sum(int x, int p) {
    int ps = upper_bound(vec[x].begin(), vec[x].end(), p) - vec[x].begin();
    return sum[x][ps - 1];
}

int main() {
    rep(i, mxn) {
        pw1[i] = i ? 1LL * mul * pw1[i - 1] % mod1 : 1;
        pw2[i] = i ? 1LL * mul * pw2[i - 1] % mod2 : 1;
        p2[i] = i ? 2LL * p2[i - 1] % mod : 1;
    }
    scanf("%d %d", &n, &q);
    scanf("%s", s[0]);
    scanf("%s", t);
    l[0] = strlen(s[0]);
    n0 = 0;
    while (n0 <= n && l[n0] * 2 + 1 < mxn) {
        rep(i, l[n0]) s[n0 + 1][l[n0 + 1] ++] = s[n0][i];
        s[n0 + 1][l[n0 + 1] ++] = t[n0];
        rep(i, l[n0]) s[n0 + 1][l[n0 + 1] ++] = s[n0][i];
        ++ n0;
    }
    {
        int i = n0 - 1;
        pre[0] = Hash();
        rep(j, l[i])
            pre[j + 1] = pre[j] + Hash(s[i][j]);
    }
    rep(c, 26) vec[c].pb(0);
    for (int i = 1; i <= n; ++ i) vec[t[i - 1] - 'a'].pb(i);
    rep(c, 26) {
        sum[c].resize(vec[c].size() + 1);
        rep(i, vec[c].size()) if (i)
            sum[c][i] = (sum[c][i - 1] + qp(p2[vec[c][i]])) % mod;
    }
    while (q --) {
        scanf("%d %s", &k, qs);
        int len = strlen(qs);
//      int n0 = 0;
//      while (l[n0] < len) ++ n0;
//      ++ n0;
        qpre[0] = Hash();
        rep(i, len)
            qpre[i + 1] = qpre[i] + Hash(qs[i]);
        qsuf[len] = Hash();
        for (int i = len - 1; ~i; -- i)
            qsuf[i] = Hash(qs[i]) + qsuf[i + 1];
        int ans = 0;
        rep(p, l[0] - len + 1)
            if (get_hash(pre, p, p + len) == qpre[len])
                (ans += p2[k - 0]) %= mod;
        rep(i, min(k + 1, n0)) if (i) rep(p, len)
            if (p <= l[i - 1] && len - p - 1 <= l[i - 1])
                if (get_hash(pre, l[i - 1] - p, l[i - 1]) == qpre[p] && get_hash(pre, 0, len - p - 1) == qsuf[p + 1] && t[i - 1] == qs[p])
                    (ans += p2[k - i]) %= mod;
        if (k >= n0) {
            int i = n0;
            rep(p, len)
                if (p <= l[i - 1] && len - p - 1 <= l[i - 1])
                    if (get_hash(pre, l[i - 1] - p, l[i - 1]) == qpre[p] && get_hash(pre, 0, len - p - 1) == qsuf[p + 1])
                        (ans += 1LL * p2[k] * (get_sum(qs[p] - 'a', k) + mod - get_sum(qs[p] - 'a', n0 - 1)) % mod) %= mod;
        }
        printf("%d\n", ans);
    }
    return 0;
}