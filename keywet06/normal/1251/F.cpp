#include <bits/stdc++.h>

using namespace std;

const int P = 998244353, N = 3E5, G = 3;

int Add(int a, int b) { return (a += b) >= P ? a -= P : a; }
int Sub(int a, int b) { return (a -= b) < 0 ? a += P : a; }
void Adds(int &a, int b) { (a += b) >= P ? a -= P : 0; }

int n, k, q;
int c[N + 1];
int Fac[N + 1], Facr[N + 1];
int Ans[2 * N + 2];

vector<int> rev, roots{0, 1};

int Pow(int a, int b) {
    int Ans = 1;
    while (b > 0) {
        if (b & 1) Ans = 1LL * Ans * a % P;
        a = 1LL * a * a % P;
        b >>= 1;
    }
    return Ans;
}

void DFT(vector<int> &a) {
    int n = a.size();
    if (int(rev.size()) != n) {
        int k = __builtin_ctz(n) - 1;
        rev.resize(n);
        for (int i = 0; i < n; ++i) rev[i] = rev[i >> 1] >> 1 | (i & 1) << k;
    }
    for (int i = 0; i < n; ++i) {
        if (rev[i] < i) swap(a[i], a[rev[i]]);
    }
    if (int(roots.size()) < n) {
        int k = __builtin_ctz(roots.size());
        roots.resize(n);
        while ((1 << k) < n) {
            int e = Pow(G, (P - 1) >> (k + 1));
            for (int i = 1 << (k - 1); i < (1 << k); ++i) {
                roots[2 * i] = roots[i];
                roots[2 * i + 1] = 1LL * roots[i] * e % P;
            }
            ++k;
        }
    }
    for (int k = 1; k < n; k *= 2) {
        for (int i = 0; i < n; i += 2 * k) {
            for (int j = 0; j < k; ++j) {
                int u = a[i + j];
                int v = 1LL * a[i + j + k] * roots[k + j] % P;
                a[i + j] = Add(u, v);
                a[i + j + k] = Sub(u, v);
            }
        }
    }
}

void IDFT(vector<int> &a) {
    int n = a.size();
    reverse(a.begin() + 1, a.end());
    DFT(a);
    int inv = Pow(n, P - 2);
    for (int i = 0; i < n; ++i) a[i] = 1LL * a[i] * inv % P;
}

vector<int> operator*(vector<int> a, vector<int> b) {
    int sz = 1, tot = a.size() + b.size() - 1;
    while (sz < tot) sz <<= 1;
    a.resize(sz);
    b.resize(sz);
    DFT(a);
    DFT(b);
    for (int i = 0; i < sz; ++i) a[i] = 1LL * a[i] * b[i] % P;
    IDFT(a);
    a.resize(tot);
    return a;
}

int C(int n, int m) { return 1LL * Fac[n] * Facr[m] % P * Facr[n - m] % P; }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    Fac[0] = 1;
    for (int i = 1; i <= n; ++i) Fac[i] = 1LL * Fac[i - 1] * i % P;
    Facr[n] = Pow(Fac[n], P - 2);
    for (int i = n; i >= 1; --i) Facr[i - 1] = 1LL * Facr[i] * i % P;
    for (int i = 0, x; i < n; ++i) cin >> x, ++c[x];
    for (int i = 0; i < k; ++i) {
        int x;
        cin >> x;
        int c1 = 0, c2 = 0;
        for (int j = 1; j < x; ++j) {
            if (c[j] == 1) {
                ++c1;
            } else if (c[j] >= 2) {
                ++c2;
            }
        }
        vector<int> a(2 * c2 + 1), b(c1 + 1);
        for (int i = 0; i <= 2 * c2; ++i) a[i] = C(2 * c2, i);
        for (int i = 0, j = 1; i <= c1; ++i) {
            b[i] = 1LL * C(c1, i) * j % P;
            Adds(j, j);
        }
        a = a * b;
        for (int i = 0; i < a.size(); ++i) Adds(Ans[i + x + 1], a[i]);
    }
    cin >> q;
    while (q--) {
        int x;
        cin >> x;
        cout << Ans[x / 2] << "\n";
    }
    return 0;
}