#include <bits/stdc++.h>

using namespace std;

typedef long long int64;

const int K = 100;
const int64 mod = 998244353;

struct mat {
    int64 x[K][K];
    mat operator*(const mat &b) {
        mat res;
        memset(res.x, 0, sizeof(res.x));
        for (int k = 0; k < K; k += 1)
            for (int i = 0; i < K; i += 1)
                for (int j = 0; j < K; j += 1) {
                    res.x[i][j] += x[i][k] * b.x[k][j] % (mod - 1);
                    res.x[i][j] %= (mod - 1);
                }
        return res;
    }
};

mat a;

mat power(int64 r) {
    mat res;
    memset(res.x, 0, sizeof(res.x));
    for (int i = 0; i < K; i += 1) res.x[i][i] = 1;
    for (; r; r >>= 1, a = a * a)
        if (r & 1) res = res * a;
    return res;
}

int logorithm(int a, int b, int p);

int pow_mod(int a, long long b, int p);

int phi(int n);

int main() {
    ios::sync_with_stdio(false);
    int k;
    cin >> k;
    for (int i = 0; i < k; i += 1) cin >> a.x[0][i];
    for (int i = 1; i < k; i += 1) a.x[i][i - 1] = 1;
    int n, m;
    cin >> n >> m;
    if (m == 1) {
        cout << 1;
        return 0;
    }
    mat res = power(n - k);
    int64 r = res.x[0][0];
    int64 mi = logorithm(3, m, mod);
    int64 g = __gcd(r, mi);
    r /= g, mi /= g;
    if (__gcd(r, mod - 1) > 1) {
        cout << -1;
        return 0;
    }
    cout << pow_mod(3, mi * pow_mod(r, phi(mod - 1) - 1, mod - 1) % (mod - 1),
                    mod);
}

map<int, int> Mp;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int phi(int n) {
    int i, m = n;
    for (i = 2; n / i >= i; i++)
        if (n % i == 0) {
            m = m / i * (i - 1);
            while (n % i == 0) n /= i;
        }
    if (n > 1) m = m / n * (n - 1);
    return m;
}

int pow_mod(int a, long long b, int p) {
    int r = 1;
    if (p == 1) return 0;
    for (; b; b >>= 1, a = (long long)a * a % p)
        if (b & 1) r = (long long)r * a % p;
    return r;
}

int logorithm(int a, int b, int p) {
    if (b >= p) return -1;
    Mp.clear();
    int r = 0, d, i, j, t1, t2, m = (int)ceil(sqrt(p) + 1e-9), m1;
    if (p == 1) return 0;
    for (i = 0, t1 = 1; i < 32; i++) {
        if (t1 == b) return i;
        t1 = (long long)t1 * a % p;
    }
    for (t1 = d = 1; gcd((long long)t1 * a % p, p) != d; r++) {
        t1 = (long long)t1 * a % p;
        d = gcd(t1, p);
    }
    if (b % d != 0) return -1;
    if (t1 == b) return r;
    Mp[t1] = 0;
    int pre = t1;
    for (i = 1; i < m; i++) {
        int tmp = 1LL * pre * a % p;
        if (!Mp.count(tmp)) Mp[tmp] = i;
        pre = tmp;
        if (tmp == b) return r + i;
    }
    m1 = phi(p / d);
    m1 = pow_mod(a, m1 - m % m1, p);
    for (i = 1; i < m; i++) {
        b = (long long)b * m1 % p;
        map<int, int>::iterator it = Mp.find(b);
        if (it != Mp.end()) return i * m + it->second + r;
    }
    return -1;
}