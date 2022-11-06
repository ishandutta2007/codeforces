#include <bits/stdc++.h>
#define ri register int
using namespace std;
const int rlen = 1 << 20 | 5;
char buf[rlen], *ib = buf, *ob = buf;
#define gc() getchar()//(((ib == ob) && (ob = (ib = buf) + fread(buf, 1, rlen, stdin))), ib == ob ? -1 : *ib++)
#define pb push_back
#define fi first
#define se second
#define ppp pop_back
#define rez resize
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <int, ll> pil;
typedef pair <ll, int> pli;
typedef pair <ll, ll> pll;
typedef vector <int> poly;
typedef vector <pii> vii;
inline int read() {
    static int ans, f;
    static char ch;
    for (f = 1, ch = gc(); !isdigit(ch); f ^= ch == '-', ch = gc());
    for (ans = 0; isdigit(ch); ans = ((ans << 2) + ans << 1) + (ch ^ 48), ch = gc());
    return f ? ans : -ans;
}
inline ll readl() {
    static ll ans;
    static int f;
    static char ch;
    for (f = 1, ch = gc(); !isdigit(ch); f ^= ch == '-', ch = gc());
    for (ans = 0; isdigit(ch); ans = ((ans << 2) + ans << 1) + (ch ^ 48), ch = gc());
    return f ? ans : -ans;
}
namespace modular {
    const int mod = 998244353;
    inline int add(int a, int b) { return a < mod - b ? a + b : a - mod + b; }
    inline int dec(int a, int b) { return a < b ? a - b + mod : a - b; }
    inline int mul(int a, int b) { return (ll) a * b % mod; }
    inline void Add(int &a, int b) { a = a < mod - b ? a + b : a - mod + b; }
    inline void Dec(int &a, int b) { a = a < b ? a - b + mod : a - b; }
    inline void Mul(int &a, int b) { a = (ll) a * b % mod; }
    inline int ksm(int a, int p) {
        static int ret;
        for (ret = 1; p; p >>= 1, Mul(a, a)) (p & 1) && (Mul(ret, a), 1);
        return ret;
    }
    inline int Inv(int a) { return ksm(a, mod - 2); }
}  using namespace modular;
const int N = 2e5 + 5;
int a, b;
bool f[N];
int main() {
    #ifdef ldxcaicai
    freopen("lx.in", "r", stdin);
    #endif
    for (ri tt = read(); tt; --tt) {
        a = read(), b = read();
        for (ri i = 0; i <= a + b; ++i) f[i] = 0;
        int t1 = (a + b + 1) / 2, t2 = (a + b) / 2;
        int ss;
        for (ri i = 0; i <= a; ++i) {
            if (a - i > t2) continue;
            if (i > t1) continue;
            if (b - (t1 - i) > t2) continue;
            f[t1 - i + a - i] = 1;
        }
        for (ri i = 0; i <= b; ++i) {
            if (b - i > t2) continue;
            if (i > t1) continue;
            if (a - (t1 - i) > t2) continue;
            f[t1 - i + b - i] = 1;
        }
        vector <int> res;
        for (ri i = 0; i <= a + b; ++i) if (f[i]) {
            f[i] = 0;
            res.pb(i);
        }
        cout << res.size() << '\n';
        for (ri i = 0; i < res.size(); ++i) cout << res[i] << ' ';
        cout << '\n';
    }
    return 0;
}