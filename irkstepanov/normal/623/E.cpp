#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef double ld;
typedef complex<ld> comp;

const ld pi = 4 * atan(1.0);

vector<int> rev;
vector<comp> pw2;
vector<comp> pw;

bool bit(int mask, int pos) {
    return (mask >> pos) & 1;
}

void fft(vector<comp>& a, int k, bool flag) {
    int n = (1 << k);
    assert(sz(a) == n);
    if (sz(rev) != n) {
        rev.resize(n);
        int oldest = -1;
        rev[0] = 0;
        for (int i = 1; i < n; ++i) {
            if (!(i & (i - 1))) {
                ++oldest;
            }
            rev[i] = rev[i ^ (1 << oldest)] + (1 << (k - oldest - 1));
        }
        pw2.resize(k + 1);
        for (int r = 0; r <= k; ++r) {
            ld angle = 2 * pi / (1 << r);
            pw2[r] = {cos(angle), sin(angle)};
        }
        pw.assign(n, 1);
        for (int j = 0; j < n; ++j) {
            for (int i = 0; i < k; ++i) {
                if (bit(j, i)) {
                    pw[j] *= pw2[k - i];
                }
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        if (rev[i] < i) {
            swap(a[i], a[rev[i]]);
        }
    }
    for (int r = 0; r < k; ++r) {
        for (int j = 0; j < (1 << r); ++j) {
            comp p = pw[j * (1 << (k - r - 1))];
            if (flag) {
                p = comp(1) / p;
            }
            for (int i = j; i < n; i += (1 << (r + 1))) {
                comp x = a[i], y = a[i + (1 << r)] * p;
                a[i] = x + y;
                a[i + (1 << r)] = x - y;
            }
        }
    }
    if (flag) {
        for (int i = 0; i < n; ++i) {
            a[i] /= n;
        }
    }
}

void help(int k, vector<int>& a, vector<int>& b, vector<int>& c, vector<int>& d, vector<ll>& p0, vector<ll>& p1, vector<ll>& p2) {
    // p0 = ac
    // p1 = ad + bc
    // p2 = bd
    int n = (1 << k);
    vector<comp> p(n), q(n);
    for (int i = 0; i < n; ++i) {
        p[i] = comp(a[i], b[i]);
        q[i] = comp(c[i], d[i]);
    }
    fft(p, k, false);
    fft(q, k, false);
    vector<comp> x(n);
    for (int i = 0; i < n; ++i) {
        x[i] = p[i] * q[i];
    }
    fft(x, k, true);
    p0.resize(n), p1.resize(n), p2.resize(n);
    vector<ll> f(n);
    for (int i = 0; i < n; ++i) {
        f[i] = round(x[i].real());
        p1[i] = round(x[i].imag());
    }
    reverse(q.begin() + 1, q.end());
    for (int i = 0; i < n; ++i) {
        q[i] = conj(q[i]);
    }
    vector<comp> y(n);
    for (int i = 0; i < n; ++i) {
        y[i] = p[i] * q[i];
    }
    fft(y, k, true);
    vector<ll> g(n);
    for (int i = 0; i < n; ++i) {
        g[i] = round(y[i].real());
    }
    for (int i = 0; i < n; ++i) {
        p0[i] = (f[i] + g[i]) / 2;
        p2[i] = (g[i] - f[i]) / 2;
    }
}

/*vector<ll> mul(int k, vector<int> a, vector<int> b) {
    int n = (1 << k);
    vector<comp> x(n), y(n);
    for (int i = 0; i < n; ++i) {
        x[i] = a[i];
        y[i] = b[i];
    }
    fft(x, k, false);
    fft(y, k, false);
    for (int i = 0; i < n; ++i) {
        x[i] *= y[i];
    }
    fft(x, k, true);
    vector<ll> ans(n);
    for (int i = 0; i < n; ++i) {
        ans[i] = round(x[i].real());
    }
    return ans;
}*/

const int mod = 1e9 + 7;

void add(int& a, int b) {
    a += b;
    if (a >= mod) {
        a -= mod;
    }
}

void mul(int& a, int b) {
    ll c = ll(a) * b;
    if (c >= mod) {
        c %= mod;
    }
    a = c;
}

void sub(int& a, int b) {
    a -= b;
    if (a < 0) {
        a += mod;
    }
}

void normalize(ll& a) {
    a %= mod;
    if (a < 0) {
        a += mod;
    }
}

int binpow(int a, int n) {
    int ans = 1;
    while (n) {
        if (n & 1) {
            mul(ans, a);
        }
        n >>= 1;
        mul(a, a);
    }
    return ans;
}

const int buben = 31622;

vector<int> mul(int k, vector<int> p, vector<int> q) {
    int n = (1 << k);
    vector<int> a(n), b(n), c(n), d(n);
    for (int i = 0; i < n; ++i) {
        a[i] = p[i] % buben;
        b[i] = p[i] / buben;
        c[i] = q[i] % buben;
        d[i] = q[i] / buben;
    }
    vector<ll> p0, p1, p2;
    help(k, a, b, c, d, p0, p1, p2);
    vector<int> res(n);
    for (int i = 0; i < n; ++i) {
        normalize(p0[i]);
        normalize(p1[i]);
        normalize(p2[i]);
        ll val = p0[i];
        val += p1[i] * buben;
        normalize(val);
        val += p2[i] * buben * buben;
        normalize(val);
        res[i] = val;
    }
    return res;
}

const int nmax = 35000;

int fact[nmax];
int rfact[nmax];
int deg2[nmax];

vector<int> solve(int r, int k, vector<int>& p, int n) {
    if (n == 1) {
        return p;
    }
    if (n % 2 == 1) {
        vector<int> q = p;
        int deg = 1;
        for (int i = 0; i < (1 << r); ++i) {
            mul(q[i], deg);
            mul(deg, deg2[n - 1]);
        }
        vector<int> x = solve(r, k, p, n - 1);
        vector<int> y = mul(r, x, q);
        for (int i = k + 1; i < (1 << r); ++i) {
            y[i] = 0;
        }
        return y;
    } else {
        vector<int> q = p;
        int deg = 1;
        for (int i = 0; i < (1 << r); ++i) {
            mul(q[i], deg);
            mul(deg, deg2[n / 2]);
        }
        vector<int> x = mul(r, p, q);
        for (int i = k + 1; i < (1 << r); ++i) {
            x[i] = 0;
        }
        return solve(r, k, x, n / 2);
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //ifstream cin("input.txt");

    fact[0] = 1;
    for (int i = 1; i < nmax; ++i) {
        fact[i] = fact[i - 1];
        mul(fact[i], i);
    }
    for (int i = 0; i < nmax; ++i) {
        rfact[i] = binpow(fact[i], mod - 2);
    }
    deg2[0] = 1;
    for (int i = 1; i < nmax; ++i) {
        deg2[i] = deg2[i - 1];
        mul(deg2[i], 2);
    }

    ll n;
    int k;
    cin >> n >> k;

    if (n > k) {
        cout << "0\n";
        return 0;
    }

    int r = 0;
    while ((1 << r) <= k * 2 + 5) {
        ++r;
    }

    vector<int> p(1 << r, 0);
    for (int i = 1; i <= k; ++i) {
        p[i] = rfact[i];
    }

    vector<int> prod = solve(r, k, p, n);
    vector<int> dpn(1 << r);
    for (int s = 0; s <= k; ++s) {
        int val = fact[k];
        mul(val, rfact[k - s]);
        dpn[k - s] = val;
    }

    vector<int> dp0 = mul(r, prod, dpn);
    for (int i = k + 1; i < (1 << r); ++i) {
        dp0[i] = 0;
    }
    cout << dp0[k] << "\n";

}