#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define forn(i, a, n) for (int i = a; i < n; ++i)
#define ford(i, a, n) for (int i = n - 1; i >= a; --i)
#define fore(i, a, n) for (int i = a; i <= n; ++i)
#define all(a) (a).begin(), (a).end()
#define fs first
#define sn second
#define trace(a)\
    for (auto i : a) cerr << i << ' ';\
    cerr << '\n'
#define eb emplace_back

#ifndef M_PI
const ld M_PI = acos(-1.0);
#endif

const ld eps = 1e-9;
const int INF = 2000000000;
const ll LINF = 1ll * INF * INF;
const ll MOD = 1000000007;
const ll INV = (ll)MOD * MOD  - 2;

struct Number {
    ll x, y;

    Number () : x(0), y(0) {};

    Number (ll x, ll y) : x(x), y(y) {};

    void operator+= (Number a) {
        x += a.x;
        if (x >= MOD) x -= MOD;
        y += a.y;
        if (y >= MOD) y -= MOD;
    }

    Number operator+ (Number a) {
        Number ans = *this;
        ans += a;
        return ans;
    }

    void operator-= (Number a) {
        x -= a.x;
        if (x < 0) x += MOD;
        y -= a.y;
        if (y < 0) y += MOD;
    }
    
    Number operator- (Number a) {
        Number ans = *this;
        ans -= a;
        return ans;
    }

    Number operator* (Number a) {
        return Number ((x * a.x + y * a.y * 5) % MOD, (x * a.y + y * a.x) % MOD);
    }

    void operator*= (Number a) {
        *this = *this * a;
    }

    Number operator^ (ll w) {
        Number a(1, 0), b = *this;
        while (w) {
            if (w % 2) a *= b;
            b *= b;
            w /= 2;
        }
        return a;
    }

    Number inv() {
        return *this ^ INV;
    }
};

Number PHI1 = Number(2, 0).inv() * Number (1, 1);
Number PHI2 = PHI1.inv() * Number(MOD - 1, 0);
Number INV_ROOT = Number(0, 1).inv();

int n;

const int N = 1 << 17;

Number t1[2 * N], t2[2 * N], m1[2 * N], m2[2 * N];

void build(Number t[], Number m[]) {
    ford(i, 1, N) t[i] = t[2 * i] + t[2 * i + 1];
    forn(i, 0, 2 * N) m[i] = Number(1, 0);
}

Number mult(Number t[], Number m[], Number x, int l, int r, int lb, int rb, int p) {
    if (p < N) {
        m[2 * p] *= m[p];
        m[2 * p + 1] *= m[p];
    }
    t[p] *= m[p];
    m[p] = Number(1, 0);
    l = max(l, lb);
    r = min(r, rb);
    if (l >= r) return Number(0, 0);
    if (l == lb && r == rb) {
        //cerr << p << '\n';
        //cerr << lb << ' ' << rb << '\n';
        Number old = m[p];
        m[p] *= x;
        return (m[p] - old) * t[p];
    }
    Number ans(0, 0);
    int mb = (lb + rb) / 2;
    if (p < N) {
        ans += mult(t, m, x, l, r, lb, mb, 2 * p);
        ans += mult(t, m, x, l, r, mb, rb, 2 * p + 1);
    }
    t[p] += ans;
    return ans;
}

Number sum(Number t[], Number m[], int l, int r, int lb, int rb, int p) {
    if (p < N) {
        //if (m[p].x != 1 || m[p].y != 0) cerr << p << '\n';
        m[2 * p] *= m[p];
        m[2 * p + 1] *= m[p];    
    } 
    t[p] *= m[p];
    m[p] = Number(1, 0);
    l = max(l, lb);
    r = min(r, rb);
    if (l >= r) return Number(0, 0);
    if (l == lb && r == rb) {
        return t[p];
    }
    int mb = (lb + rb) / 2;
    if (p < N)
        return sum(t, m, l, r, lb, mb, 2 * p) + sum(t, m, l, r, mb, rb, 2 * p + 1);
    else
        return Number(0, 0);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int m;
    cin >> n >> m;
    vector<int> a(n);
    forn(i, 0, n) cin >> a[i];
    forn(i, 0, n) t1[N + i] = PHI1 ^ a[i];
    forn(i, 0, n) t2[N + i] = PHI2 ^ a[i];
    build(t1, m1);
    build(t2, m2);
    forn(i, 0, m) {
        int t;
        cin >> t;
        if (t == 1) {
            int l, r, x;
            cin >> l >> r >> x;
            --l;
            mult(t1, m1, PHI1 ^ x, l, r, 0, N, 1);
            mult(t2, m2, PHI2 ^ x, l, r, 0, N, 1);
        } else {
            int l, r;
            cin >> l >> r;
            --l;
            Number c1 = sum(t1, m1, l, r, 0, N, 1);
            Number c2 = sum(t2, m2, l, r, 0, N, 1);
            c1 -= c2;
            c1 *= INV_ROOT;
            cout << c1.x << '\n';
        }
    }
}