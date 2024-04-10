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
const int N = 1005;
int n, m, a[N], b[N], sz, pre[N];
ll cur[N];
bool vs[N];
vector <int> e[N];
inline bool chk(ll W) {
    static int que[N], hd, tl;
    if (sz == n) return 1;
    ll w = W;
    for (ri i = 1; i <= n; ++i) cur[i] = pre[i] = 0;
    hd = 1, tl = 0;
    for (ri u = 1; u <= n; ++u) if (vs[u]) {
        w += b[u];
        que[++tl] = u;
    }
    for (ri i = hd; i <= tl; ++i) cur[que[i]] = w;
    vector <int> pt;
    for (ri u; hd <= tl && !pt.size(); ) {
        u = que[hd++];
        for (ri i = 0, v; i < e[u].size(); ++i) {
            v = e[u][i];
            if (v == pre[u]) continue;
            if (vs[v]) {
                if (vs[u]) continue;
                while (!vs[u]) {
                    pt.pb(u);
                    u = pre[u];
                }
                break;
            }
            if (a[v] < cur[u]) {
                if (cur[v]) {
                    while (!vs[u]) {
                        pt.pb(u);
                        u = pre[u];
                    }
                    while (!vs[v]) {
                        pt.pb(v);
                        v = pre[v];
                    }
                    break;
                }
                pre[v] = u;
                cur[v] = cur[u] + b[v];
                que[++tl] = v;
            }
        }
    }
    if (!pt.size()) return 0;
    for (ri i = 0; i < pt.size(); ++i) {
        if (!vs[pt[i]]) ++sz;
        vs[pt[i]] = 1;
    }
    return chk(W);
}
int main() {
    #ifdef ldxcaicai
    freopen("lx.in", "r", stdin);
    #endif
    for (ri tt = read(); tt; --tt) {
        n = read();
        m = read();
        int l = 0x3f3f3f3f, r = 0, res = l;
        for (ri i = 2; i <= n; ++i) a[i] = read(), l = min(l, a[i]), r = max(r, a[i]);
        for (ri i = 2; i <= n; ++i) b[i] = read();
        for (ri i = 1; i <= n; ++i) e[i].clear();
        for (ri i = 1, u, v; i <= m; ++i) {
            u = read();
            v = read();
            e[u].pb(v);
            e[v].pb(u);
        }
        ++l, ++r;
        while (l <= r) {
            int mid = (l + r) >> 1;
            sz = 1;
            for (ri i = 1; i <= n; ++i) vs[i] = 0;
            vs[1] = 1;
            if (chk(mid)) r = mid - 1, res = mid;
            else l = mid + 1;
        }
        cout << res << '\n';
    }
    return 0;
}