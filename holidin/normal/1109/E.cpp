#include <bits/stdc++.h>
#pragma GCC optimize 03
#define fi first
#define se second
using namespace std;
const int N = 1.1e6 + 1;
long long mod;

long long m[N], d[N], a[N], vs, h[N];
vector <int> v[N], vp;

int gcd (int a, int b, int & x, int & y) {
	if (a == 0) {
		x = 0; y = 1;
		return b;
	}
	int x1, y1;
	int d = gcd (b%a, a, x1, y1);
	x = y1 - (b / a) * (long long) x1;
	y = x1;
	return d;
}

long long obr(int a, int m) {
    int x, y;
    int g = gcd(a, m, x, y);
    return (x % m + m) % m;
}

long long bp(long long x, int st) {
    if (st == 0)
        return 1;
    else if (st % 2 == 0)
            return bp((x * x) % mod, st / 2);
        else
            return (bp((x * x) % mod, st / 2) * x) % mod;
}

long long cnt(vector <int> v) {
    long long res = 1;
    for (int i = 0; i < vp.size(); ++i)
        res = (res * bp(vp[i], v[i])) % mod;
    return res;
}

void recalc(int u) {
    m[u] = (((m[2*u + 1] * h[2*u + 1] + m[2*u + 2] * h[2*u + 2]) % mod) * d[u]) % mod;
}

void als(int i, int j, vector <int> f) {
    i = i + vs - 2;
    v[i] = f;
    m[i] = j;
    h[i] = cnt(f);
    while (i > 0) {
        i = (i - 1) / 2;
        recalc(i);
    }
}

void push(int u) {
    d[2*u + 1] =  (d[2*u + 1] * d[u]) % mod;
    d[2*u + 2] =  (d[2*u + 2] * d[u]) % mod;
    m[2*u + 1] =  (m[2*u + 1] * d[u]) % mod;
    m[2*u + 2] =  (m[2*u + 2] * d[u]) % mod;
    for (int i = 0; i < vp.size(); ++i) {
        v[2*u + 1][i] += v[u][i];
        v[2*u + 2][i] += v[u][i];
        v[u][i] = 0;
    }
    h[2*u + 1] = (h[2*u + 1] * h[u]) % mod;
    h[2*u + 2] = (h[2*u + 2] * h[u]) % mod;
    h[u] = 1;
    d[u] = 1;
}

void add(int u, int vl, int vr, int l, int r, int x, vector <int> f, long long c) {
    if (l <= vl && vr <= r) {
        d[u] = (d[u] * (long long) x) % mod;
        m[u] = (m[u] * (long long) x) % mod;
        for (int i = 0; i < vp.size(); ++i)
            v[u][i] += f[i];
        h[u] = (h[u] * c) % mod;
    } else if (l >= vr || vl >= r)
                return;
            else {
                add(2*u + 1, vl, (vl + vr) / 2, l, r, x, f, c);
                add(2*u + 2, (vl + vr) / 2, vr, l, r, x, f, c);
                recalc(u);
            }
}

void del(int u, int vl, int vr, int l, int r, int x, vector <int> f) {
    if (l <= vl && vr <= r) {
        m[u] = (m[u] * obr(x, mod)) % mod;
        for (int i = 0; i < vp.size(); ++i)
            v[u][i] -= f[i];
        h[u] = cnt(v[u]);
    } else if (l >= vr || vl >= r)
                return;
            else {
                push(u);
                del(2*u + 1, vl, (vl + vr) / 2, l, r, x, f);
                del(2*u + 2, (vl + vr) / 2, vr, l, r, x, f);
                recalc(u);
            }
}

long long sum(int u, int vl, int vr, int l, int r) {
    if (l <= vl && vr <= r) {
        return (m[u] * h[u]) % mod;
    } else if (l >= vr || vl >= r)
                return 0;
            else
                return ((((sum(2*u + 1, vl, (vl + vr) / 2, l, r) + sum(2*u + 2, (vl + vr) / 2, vr, l, r)) * h[u]) % mod) * d[u]) % mod;
}


int main() {
    int i, j, n, k, l, r, x, type;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> mod;
    int pmod = mod;
    for (i = 2; i * i <= pmod; ++i)
    if (pmod % i == 0) {
        vp.push_back(i);
        while (pmod % i == 0)
            pmod /= i;
    }
    if (pmod > 1)
        vp.push_back(pmod);
    vs = 1;
    while (vs < n) vs *= 2;
    for (i = 0; i < 2 * vs; ++i) {
        d[i] = 1;
        h[i] = 1;
        v[i].resize(vp.size());
    }
    for (i = 1; i <= n; ++i) {
        cin >> a[i];
        vector <int> f(vp.size());
        for (j = 0; j < vp.size(); ++j)
            while (a[i] % vp[j] == 0) {
                a[i] /= vp[j];
                ++f[j];
            }
        als(i, a[i], f);
    }
    cin >> k;
    for (i = 1; i <= k; ++i) {
        cin >> type;
        if (type == 1) {
            cin >> l >> r >> x;
            vector <int> f(vp.size());
            for (j = 0; j < vp.size(); ++j)
                while (x % vp[j] == 0) {
                    x /= vp[j];
                    ++f[j];
                }
            long long c = cnt(f);
            add(0, 1, vs + 1, l, r + 1, x, f, c);
        }
        if (type == 2) {
            cin >> l >> x;
            vector <int> f(vp.size());
            for (j = 0; j < vp.size(); ++j)
                while (x % vp[j] == 0) {
                    x /= vp[j];
                    ++f[j];
                }
            del(0, 1, vs + 1, l, l + 1, x, f);
        }
        if (type == 3) {
            cin >> l >> r;
            cout << sum(0, 1, vs + 1, l, r + 1) << "\n";
        }
    }
}