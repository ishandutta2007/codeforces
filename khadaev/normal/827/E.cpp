
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define forn(i, a, n) for (int i = (int)(a); i < (int)(n); ++i)
#define ford(i, a, n) for (int i = (int)(n - 1); i >= (int)(a); --i)
#define fore(i, a, n) for (int i = (int)(a); i <= (int)(n); ++i)
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

template<typename T>
inline void setmax(T& a, T b) {
    if (a < b) a = b;
}

template<typename T>
inline void setmin(T& a, T b) {
    if (a > b) a = b;
}

const ld eps = 1e-9;
const int INF = 2000000000;
const ll LINF = 1ll * INF * INF;
const ll MOD = 1000000007;

using base = complex<double>;
const int MAXN = 1 << 20;
base _a[MAXN], _b[MAXN], _c[MAXN];
namespace fft {
    int rev[MAXN];
    base wlen_pw[MAXN];
    
    void fft (base a[], int n, bool invert) {
        for (int i = 0; i < n; ++i)
            if (i < rev[i])
                swap(a[i], a[rev[i]]);
    
        for (int len = 2; len <= n; len <<= 1) {
            double ang = 2 * M_PI / len * (invert ? -1 : 1);
            int len2 = len >> 1;
    
            base wlen(cos(ang), sin(ang));
            wlen_pw[0] = base(1, 0);
            for (int i = 1; i < len2; ++i)
                wlen_pw[i] = wlen_pw[i - 1] * wlen;
    
            for (int i = 0; i < n; i += len) {
                base t,
                    *pu = a + i,
                    *pv = a + i + len2, 
                    *pu_end = a + i + len2,
                    *pw = wlen_pw;
                for (; pu != pu_end; ++pu, ++pv, ++pw) {
                    t = *pv * *pw;
                    *pv = *pu - t;
                    *pu += t;
                }
            }
        }
    
        if (invert)
            for (int i = 0; i < n; ++i)
                a[i] /= n;
    }
    
    void calc_rev (int n) {
        int lg = 1;
        while ((1 << lg) < n) ++lg;
        for (int i = 0; i < n; ++i) {
            rev[i] = 0;
            for (int j = 0; j < lg; ++j)
                if (i & (1 << j))
                    rev[i] |= 1 << (lg - 1 - j);
        }
    }

    vector<int> multiply(vector<int> a, vector<int> b) {
        int n = 1;
        while (n < max(a.size(), b.size()))
            n *= 2;
        n *= 2;
        calc_rev(n);
        for (int i = 0; i < n; ++i)
            _a[i] = 0, _b[i] = 0;
        for (int i = 0; i < (int)a.size(); ++i)
            _a[i] = a[i];
        for (int i = 0; i < (int)b.size(); ++i)
            _b[i] = b[i];
        fft(_a, n, false);
        fft(_b, n, false);
        for (int i = 0; i < n; ++i)
            _c[i] = _a[i] * _b[i];
        fft(_c, n, true);
        vector<int> ans(n);
        for (int i = 0; i < n; ++i)
            ans[i] = int(_c[i].real() + 0.5);
        return ans;
    }
}
using fft::multiply;

vector<char> solve(int n, const string& s, char c1, char c2) {
    vector<int> a(n), b(n);
    vector<char> ans(n + 1);
    forn(i, 0, n)
        a[i] = (s[i] == c1 ? 1 : 0);
    forn(i, 0, n)
        b[n - 1 - i] = (s[i] == c2 ? 1 : 0);
    auto c = multiply(a, b);
    c.resize(2 * n - 1);
    vector<char> ok(n + 1, 1);
    forn(i, 0, n) if (c[i]) ok[n - 1 - i] = 0;
    return ok;
}

void solve() {
    int n;
    scanf("%d", &n);
    string s;
    getline(cin, s);
    getline(cin, s);
    vector<char> okV = solve(n, s, 'V', 'K'), okK = solve(n, s, 'K', 'V');
    vector<char> ok(n + 1);
    fore(i, 0, n) ok[i] = okV[i] && okK[i];
    fore(i, 1, n) {
        for (int j = i; j <= n; j += i)
            ok[i] &= ok[j];
    }
    int ans = 0;
    fore(i, 1, n)
        if (ok[i])
            ++ans;
    printf("%d\n", ans);
    fore(i, 1, n)
        if (ok[i])
            printf("%d ", i);
    printf("\n");
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) solve();
}