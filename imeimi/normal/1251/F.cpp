#include <bits/stdc++.h>
#define fs first
#define se second
#define y0 qwertyuiop
#define y1 asdfghjkl

#ifdef imeimi
#define debug(...) printf(__VA_ARGS__)
#else
#define debug(...)
#endif

using namespace std;
typedef long long llong;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<llong, llong> pll;
typedef pair<ld, ld> pdd;

const int mod = 998244353;

void add(int &x, int y) {
    x = (x + y) % mod;
}

int mul(int x, int y) {
    return (llong)x * y % mod;
}

int pw(int x, int p) {
    int r = 1;
    while (p) {
        if (p & 1) r = mul(r, x);
        x = mul(x, x);
        p >>= 1;
    }
    return r;
}

void fft(vector<int> &a, bool rev) {
    int n = a.size();
    vector<int> roots(n >> 1, 1);
    for (int i = 1, j = 0; i < n; ++i) {
        int bit = n >> 1;
        while (bit <= j) {
            j -= bit;
            bit >>= 1;
        }
        j += bit;
        if (i < j) swap(a[i], a[j]);
    }
    int ang = pw(3, (mod - 1) / n);
    if (rev) ang = pw(ang, mod - 2);
    for (int i = 1; i + i < n; ++i) {
        roots[i] = mul(roots[i - 1], ang);
    }
    for (int i = 1, d = n >> 1; i < n; i <<= 1, d >>= 1) {
        for (int j = 0; j < n; j += i + i) {
            for (int k = 0; k < i; ++k) {
                int u = a[j + k];
                int v = mul(a[j + k + i], roots[d * k]);
                a[j + k] = u;
                add(a[j + k], v);
                a[j + k + i] = u;
                add(a[j + k + i], mod - v);
            }
        }
    }
    if (rev) {
        int rn = pw(n, mod - 2);
        for (int i = 0; i < n; ++i) a[i] = mul(a[i], rn);
    }
}

int n, k, q;
int Q[300001];
int ans[300001];

void solve(int cnt1, int cnt2, int B) {
    int sz = 4;
    while (sz <= n) sz <<= 1;
    vector<int> x(sz, 0), y(sz, 0);
    x[0] = 1; x[1] = 2;
    y[0] = 1; y[1] = 2; y[2] = 1;
    fft(x, 0);
    fft(y, 0);
    for (int i = 0; i < sz; ++i) {
        x[i] = mul(pw(x[i], cnt1), pw(y[i], cnt2));
    }
    fft(x, 1);
    for (int i = 1; i <= q; ++i) {
        int q = Q[i] >> 1;
        q -= B + 1;
        if (0 <= q && q < sz) add(ans[i], x[q]);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(30); cout << fixed;
    vector<int> A, B;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        A.push_back(x);
    }
    for (int i = 1; i <= k; ++i) {
        int x;
        cin >> x;
        B.push_back(x);
    }
    cin >> q;
    for (int i = 1; i <= q; ++i) cin >> Q[i];
    sort(A.begin(), A.end());
    A.push_back(-1);
    for (int i = 0; i < k; ++i) {
        int pr = -1;
        int cnt = 0, cnt1 = 0, cnt2 = 0;
        for (int j : A) {
            if (pr != j) {
                if (cnt == 1) ++cnt1;
                else if (cnt > 1) ++cnt2;
                pr = j;
                cnt = 1;
            }
            else ++cnt;
            if (B[i] <= j) break;
        }
        solve(cnt1, cnt2, B[i]);
    }
    for (int i = 1; i <= q; ++i) printf("%d\n", ans[i]);
    return 0;
}