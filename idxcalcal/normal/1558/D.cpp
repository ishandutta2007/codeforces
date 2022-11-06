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
int n, m, fac[N << 1], ifac[N << 1];
inline void init_fac() {
    int len = 400001;
    fac[0] = fac[1] = ifac[0] = ifac[1] = 1;
    for (ri i = 2; i <= len; ++i) fac[i] = mul(fac[i - 1], i);
    ifac[len] = Inv(fac[len]);
    for (ri i = len - 1; i > 1; --i) ifac[i] = mul(ifac[i + 1], i + 1);
}
inline int C(int n, int m) { return n < m || m < 0 ? 0 : mul(fac[n], mul(ifac[m], ifac[n - m])); }
namespace bst {
    #define lc (son[p][0])
    #define rc (son[p][1])
    int son[N][2], mn[N], mx[N], vl[N], tg[N];
    inline void pushup(int p) {
        mx[p] = max(vl[p], max(mx[lc], mx[rc]));
        mn[p] = min(vl[p], min(mn[lc], mn[rc]));
    }
    inline void pushnow(int p, int v) {
        tg[p] += v;
        mn[p] += v;
        mx[p] += v;
        vl[p] += v;
    }
    inline void pushdown(int p) {
        if (!tg[p]) return;
        if (lc) pushnow(lc, tg[p]);
        if (rc) pushnow(rc, tg[p]);
        tg[p] = 0;
    }
    inline int merge(int x, int y) {
        if (!x || !y) return x | y;
        pushdown(x), pushdown(y);
        if (rand() & 1) return son[x][1] = merge(son[x][1], y), pushup(x), x;
        return son[y][0] = merge(x, son[y][0]), pushup(y), y;
    }
    inline pii split(int p, int v) {
        if (!p) return pii(0, 0);
        if (mx[p] < v) return pii(p, 0);
        if (mn[p] >= v) return pii(0, p);
        pii tp;
        pushdown(p);
        if (vl[p] >= v) return tp = split(lc, v), lc = tp.se, pushup(p), pii(tp.fi, p);
        return tp = split(rc, v), rc = tp.fi, pushup(p), pii(p, tp.se);
    }
    inline int find(int p, int v) {
        if (!p || mn[p] > v || mx[p] < v) return 0;
        if (vl[p] == v) return 1;
        pushdown(p);
        if (mn[lc] <= v && mx[lc] >= v) return find(lc, v);
        if (mn[rc] <= v && mx[rc] >= v) return find(rc, v);
        return 0;
    }
    int rt = 0, tot = 0;
    inline int newnode(int v) {
        ++tot;
        mx[tot] = mn[tot] = vl[tot] = v;
        son[tot][0] = son[tot][1] = 0;
        return tot;
    }
    inline void ins(int vl) {
        int t = find(rt, vl);
        pii tp = split(rt, vl);
        if (tp.se) pushnow(tp.se, 1);
        if (!t) rt = merge(merge(tp.fi, newnode(vl + 1)), tp.se);
        else rt = merge(tp.fi, tp.se);
    }
    inline void clear() {
        mn[0] = 0x3f3f3f3f, mx[0] = 0;
        for (ri i = 1; i <= tot; ++i) {
            tg[i] = mx[i] = mn[i] = vl[i] = son[i][0] = son[i][1] = 0;
        }
        tot = rt = 0;
    }
}
int main() {
    #ifdef ldxcaicai
    freopen("lx.in", "r", stdin);
    #endif
    srand(time(NULL));
    init_fac();
    for (ri tt = read(); tt; --tt) {
        n = read();
        m = read();
        bst::clear();
        for (ri i = 1, x, y; i <= m; ++i) {
            x = read();
            y = read();
            bst:: ins(y);
        }
        m = bst:: tot + 1;
        int res = 0;
        cout << C(n + n - m, n) << '\n';
    }
    return 0;
}