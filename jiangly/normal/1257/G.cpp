#include <bits/stdc++.h>
using namespace std;
constexpr int N = 3E6;
int cnt[N + 1];
constexpr int MOD = 998244353, ROOT = 3;
int sum(int a, int b) {return (a += b) >= MOD ? a -= MOD : a;}
int dif(int a, int b) {return (a -= b) < 0 ? a += MOD : a;}
void inc(int &a, int b) {(a += b) >= MOD ? a -= MOD : 0;}
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
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        ++cnt[x];
    }
    vector<int> a;
    for (int i = 2; i <= N; ++i)
        if (cnt[i] > 0)
            a.push_back(cnt[i]);
    function<vector<int>(int, int)> solve = [&](int l, int r) {
        if (r - l == 1)
            return vector<int>(a[l] + 1, 1);
        int mid = (l + r) / 2;
        return solve(l, mid) * solve(mid, r);
    };
    cout << solve(0, (int)a.size())[n / 2] << endl;
    return 0;
}