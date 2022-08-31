#include <bits/stdc++.h>
using namespace std;
constexpr int MOD = 998244353, MAX_N = 3E5, ROOT = 3;
int sum(int a, int b) {return (a += b) >= MOD ? a -= MOD : a;}
int dif(int a, int b) {return (a -= b) < 0 ? a += MOD : a;}
void inc(int &a, int b) {(a += b) >= MOD ? a -= MOD : 0;}
int n, k, q;
int c[MAX_N + 1];
int fac[MAX_N + 1], facinv[MAX_N + 1];
int ans[2 * MAX_N + 2];
vector<int> rev, roots{0, 1};
int power(int a, int b) {
    int ans = 1;
    while (b > 0) {
        if (b & 1)
            ans = 1LL * ans * a % MOD;
        a = 1LL * a * a % MOD;
        b >>= 1;
    }
    return ans;
}
void dft(vector<int> &a) {
    int n = a.size();
    if (int(rev.size()) != n) {
        int k = __builtin_ctz(n) - 1;
        rev.resize(n);
        for (int i = 0; i < n; ++i) rev[i] = rev[i >> 1] >> 1 | (i & 1) << k;
    }
    for (int i = 0; i < n; ++i)
        if (rev[i] < i)
            swap(a[i], a[rev[i]]);
    if (int(roots.size()) < n) {
        int k = __builtin_ctz(roots.size());
        roots.resize(n);
        while ((1 << k) < n) {
            int e = power(ROOT, (MOD - 1) >> (k + 1));
            for (int i = 1 << (k - 1); i < (1 << k); ++i) {
                roots[2 * i] = roots[i];
                roots[2 * i + 1] = 1LL * roots[i] * e % MOD;
            }
            ++k;
        }
    }
    for (int k = 1; k < n; k *= 2)
        for (int i = 0; i < n; i += 2 * k)
            for (int j = 0; j < k; ++j) {
                int u = a[i + j];
                int v = 1LL * a[i + j + k] * roots[k + j] % MOD;
                a[i + j] = sum(u, v);
                a[i + j + k] = dif(u, v);
            }
}
void idft(vector<int> &a) {
    int n = a.size();
    reverse(a.begin() + 1, a.end());
    dft(a);
    int inv = power(n, MOD - 2);
    for (int i = 0; i < n; ++i) a[i] = 1LL * a[i] * inv % MOD;
}
vector<int> operator*(vector<int> a, vector<int> b) {
    int sz = 1, tot = a.size() + b.size() - 1;
    while (sz < tot) sz <<= 1;
    a.resize(sz);
    b.resize(sz);
    dft(a);
    dft(b);
    for (int i = 0; i < sz; ++i) a[i] = 1LL * a[i] * b[i] % MOD;
    idft(a);
    a.resize(tot);
    return a;
}
int binom(int n, int m) {return 1LL * fac[n] * facinv[m] % MOD * facinv[n - m] % MOD;}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    fac[0] = 1;
    for (int i = 1; i <= n; ++i)
        fac[i] = 1LL * fac[i - 1] * i % MOD;
    facinv[n] = power(fac[n], MOD - 2);
    for (int i = n; i >= 1; --i)
        facinv[i - 1] = 1LL * facinv[i] * i % MOD;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        ++c[x];
    }
    for (int i = 0; i < k; ++i) {
        int x;
        cin >> x;
        int c1 = 0, c2 = 0;
        for (int j = 1; j < x; ++j)
            if (c[j] == 1)
                ++c1;
            else if (c[j] >= 2)
                ++c2;
        vector<int> a(2 * c2 + 1), b(c1 + 1);
        for (int i = 0; i <= 2 * c2; ++i)
            a[i] = binom(2 * c2, i);
        for (int i = 0, j = 1; i <= c1; ++i) {
            b[i] = 1LL * binom(c1, i) * j % MOD;
            inc(j, j);
        }
        a = a * b;
        for (int i = 0; i < a.size(); ++i)
            inc(ans[i + x + 1], a[i]);
    }
    cin >> q;
    while (q--) {
        int x;
        cin >> x;
        cout << ans[x / 2] << "\n";
    }
    return 0;
}