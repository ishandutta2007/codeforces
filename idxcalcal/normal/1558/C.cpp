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
const int N = 3005;
int n, a[N], ps[N];
int main() {
    #ifdef ldxcaicai
    freopen("lx.in", "r", stdin);
    #endif
    for (ri tt = read(); tt; --tt) {
        n = read();
        bool ff = 1;
        for (ri i = 1; i <= n; ++i) {
            a[i] = read();
            ps[a[i]] = i;
            if ((a[i] - i) & 1) ff = 0;
        }
        if (!ff) {
            puts("-1");
            continue;
        }
        vector <int> f;
        for (ri i = n; i > 1; i -= 2) {
            if (ps[i] == i && ps[i - 1] == i - 1) continue;
            if (ps[i] != 1) {
                int len = ps[i];
                f.pb(len);
                for (ri j = 1; j + j <= len; ++j) {
                    swap(a[j], a[len - j + 1]);
                    ps[a[j]] = j;
                    ps[a[len - j + 1]] = len - j + 1;
                }
            }
            if (ps[i - 1] != 2) {
                int len = ps[i - 1] - 1;
                f.pb(len);
                for (ri j = 1; j + j <= len; ++j) {
                    swap(a[j], a[len - j + 1]);
                    ps[a[j]] = j;
                    ps[a[len - j + 1]] = len - j + 1;
                }
                len = ps[i - 1] + 1;
                f.pb(len);
                for (ri j = 1; j + j <= len; ++j) {
                    swap(a[j], a[len - j + 1]);
                    ps[a[j]] = j;
                    ps[a[len - j + 1]] = len - j + 1;
                }
                len = 3;
                f.pb(len);
                for (ri j = 1; j + j <= len; ++j) {
                    swap(a[j], a[len - j + 1]);
                    ps[a[j]] = j;
                    ps[a[len - j + 1]] = len - j + 1;
                }
            }
            int len = i;
            f.pb(len);
            for (ri j = 1; j + j <= len; ++j) {
                swap(a[j], a[len - j + 1]);
                ps[a[j]] = j;
                ps[a[len - j + 1]] = len - j + 1;
            }
        }
        cout << f.size() << '\n';
        for (ri i = 0; i < f.size(); ++i) cout << f[i] << ' ';
        if (f.size()) cout << '\n';
    }
    return 0;
}