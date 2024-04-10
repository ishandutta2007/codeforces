#include <bits/stdc++.h>

using namespace std;

typedef long long int64;

const double PI = 4 * atan(1);
const int K = 305;
const int N = int(4e5);
const int M = int(1e9) + 7;
const int Z = 1 << 20;

int n, q, ps;
int a[N];
int ic[K];

int64 iv[K], tf[K], bm[K];

struct dat {
    int64 a = 1, b;
    dat operator+(const dat &o) const { return {a * o.a % M, b | o.b}; }
} st[Z], lz[Z];

void bld(int i = 1, int l = 0, int r = n - 1) {
    if (l == r) {
        st[i] = {a[l], bm[a[l]]};
        return;
    }
    int m = (l + r) / 2;
    bld(2 * i, l, m);
    bld(2 * i + 1, m + 1, r);
    st[i] = st[2 * i] + st[2 * i + 1];
}

int64 pm(int64 b, int p) {
    int64 r = 1;
    while (p) {
        if (p & 1) r = r * b % M;
        p /= 2;
        b = b * b % M;
    }
    return r;
}

void app(int i, dat a, int l, int r) {
    lz[i] = lz[i] + a;
    a.a = pm(a.a, r - l + 1);
    st[i] = st[i] + a;
}

void psh(int i, int l, int m, int r) {
    app(2 * i, lz[i], l, m);
    app(2 * i + 1, lz[i], m + 1, r);
    lz[i] = {1, 0};
}

void upd(int l1, int r1, dat x, int i = 1, int l2 = 0, int r2 = n - 1) {
    if (l1 <= l2 && r2 <= r1) {
        app(i, x, l2, r2);
        return;
    }
    int m2 = (l2 + r2) / 2;
    psh(i, l2, m2, r2);
    if (l1 <= m2) upd(l1, r1, x, 2 * i, l2, m2);
    if (m2 < r1) upd(l1, r1, x, 2 * i + 1, m2 + 1, r2);
    st[i] = st[2 * i] + st[2 * i + 1];
}

dat qry(int l1, int r1, int i = 1, int l2 = 0, int r2 = n - 1) {
    if (l1 <= l2 && r2 <= r1) return st[i];
    int m2 = (l2 + r2) / 2;
    psh(i, l2, m2, r2);
    return (l1 <= m2 ? qry(l1, r1, 2 * i, l2, m2) : dat{1, 0}) +
           (m2 < r1 ? qry(l1, r1, 2 * i + 1, m2 + 1, r2) : dat{1, 0});
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    iv[1] = 1;
    for (int i = 2; i <= 300; ++i) {
        iv[i] = M - M / i * iv[M % i] % M;
    }
    for (int i = 2; i <= 300; ++i) {
        if (ic[i]) continue;
        tf[ps] = iv[i] * (i - 1) % M;
        ic[i] = ps++;
        for (int j = i * i; j <= 300; j += i) ic[j] = -1;
    }
    for (int i = 1; i <= 300; ++i) {
        int i2 = i;
        for (int j = 2; j * j <= i2; ++j) {
            if (i2 % j == 0) {
                bm[i] |= 1ll << ic[j];
            }
            while (i2 % j == 0) i2 /= j;
        }
        if (i2 > 1) bm[i] |= 1ll << ic[i2];
    }
    cin >> n >> q;
    for (int i = 0; i < n; ++i) cin >> a[i];
    bld();
    while (q--) {
        string s;
        cin >> s;
        if (s[0] == 'M') {
            int l, r, x;
            cin >> l >> r >> x, --l, --r;
            upd(l, r, {x, bm[x]});
        } else {
            int l, r;
            cin >> l >> r, --l, --r;
            dat d = qry(l, r);
            for (int i = 0; i < ps; ++i)
                if (d.b >> i & 1) d.a = d.a * tf[i] % M;
            cout << d.a << "\n";
        }
    }
    return 0;
}