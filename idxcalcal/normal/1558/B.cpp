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
    int mod;
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
const int N = 4e6 + 5;
int n, f[N], ad[N];
int main() {
    #ifdef ldxcaicai
    freopen("lx.in", "r", stdin);
    #endif
    for (ri tt = 1; tt; --tt) {
        n = read();
        mod = read();
        f[1] = 1;
        int ss = 0;
        for (ri i = 1; i <= n; ++i) {
            Add(ss, ad[i]);
            Add(f[i], ss);
            Add(ss, f[i]);
            for (ri j = 1; i * j <= n; ++j) {
                Add(ad[i * j + (j == 1)], f[i]);
                if ((i + 1) * j <= n) Dec(ad[(i + 1) * j], f[i]);
            }
        }
        cout << f[n] << '\n';
    }
    return 0;
}