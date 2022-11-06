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

using base = complex<double>;
const int MAXN = 1 << 18;
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
    
    void calc_rev (int n, int log_n) {
        for (int i = 0; i < n; ++i) {
            rev[i] = 0;
            for (int j = 0; j < log_n; ++j)
                if (i & (1 << j))
                    rev[i] |= 1 << (log_n - 1 - j);
        }
    }
}

int n, lg;

base a[MAXN], b[MAXN], c[MAXN];

vector<int> solve(string s, string t, char x, int k) {
    memset(a, 0, sizeof a);
    memset(b, 0, sizeof b);
    memset(c, 0, sizeof c);
    int sum = 0;
    for (int i = 0; i < k && i < (int)s.size(); ++i)
        sum += (s[i] == x);
    forn(i, 0, (int)s.size()) {
        if (i + k < (int)s.size()) sum += (s[i + k] == x);
        if (i - k - 1 >= 0) sum -= (s[i - k - 1] == x);
        a[i] = base(sum != 0, 0);
    }
    forn(i, 0, (int)t.size())
        b[(int)t.size() - 1 - i] = base((t[i] == x), 0);
    fft::fft(a, n, false);
    fft::fft(b, n, false);
    forn(i, 0, n) c[i] = a[i] * b[i];
    fft::fft(c, n, true);
    vector<int> ans(s.size() - t.size() + 1);
    forn(i, 0, (int)ans.size())
        ans[i] = int(c[i + t.size() - 1].real() + 0.5);
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int S, T, k;
    cin >> S >> T >> k;
    n = max(S, T);
    lg = 1;
    while ((1 << lg) < n) ++lg;
    n = 1 << lg;
    fft::calc_rev(n, lg);
    string s, t;
    cin >> s >> t;
    vector<int> ans(S - T + 1);
    for (char x : {'A', 'T', 'G', 'C'}) {
        vector<int> rez = solve(s, t, x, k);
        forn(i, 0, S - T + 1)
            ans[i] += rez[i];
    }
    int ANS = 0;
    for (int x : ans)
        if (x == (int)t.size())
            ++ANS;
    cout << ANS << '\n';
}