#include <bits/stdc++.h>
#define For(i, a, b) for (register int i = (a); i <= (b); i++)
#define Dow(i, b, a) for (int i = (b); i >= (a); i--)
#define GO(i, x) for (int i = head[x]; i; i = e[i].nex)
#define mem(x, s) memset(x, s, sizeof(x))
#define cpy(x, s) memcpy(x, s, sizeof(x))
#define YES return puts("YES"), 0
#define NO return puts("NO"), 0
#define GG return puts("-1"), 0
#define pb push_back
using namespace std;

struct IO {
#define MAXSIZE (1 << 20)
#define isdigit(x) (x >= '0' && x <= '9')
    char buf[MAXSIZE], *p1, *p2;
    char pbuf[MAXSIZE], *pp;
    IO() : p1(buf), p2(buf), pp(pbuf) {}
    inline char gc() {
        //    	return getchar();
        if (p1 == p2) p2 = (p1 = buf) + fread(buf, 1, MAXSIZE, stdin);
        return p1 == p2 ? ' ' : *p1++;
    }
    inline bool blank(char ch) {
        return ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t';
    }
    template <class T>
    inline void read(T &x) {
        register double tmp = 1;
        register bool sign = 0;
        x = 0;
        register char ch = gc();
        for (; !isdigit(ch); ch = gc())
            if (ch == '-') sign = 1;
        for (; isdigit(ch); ch = gc()) x = x * 10 + (ch - '0');
        if (ch == '.')
            for (ch = gc(); isdigit(ch); ch = gc())
                tmp /= 10.0, x += tmp * (ch - '0');
        if (sign) x = -x;
    }
    inline void read(char *s) {
        register char ch = gc();
        for (; blank(ch); ch = gc())
            ;
        for (; !blank(ch); ch = gc()) *s++ = ch;
        *s = 0;
    }
    inline void read(char &c) {
        for (c = gc(); blank(c); c = gc())
            ;
    }
    template <class t>
    inline void write(t x) {
        if (x < 0)
            putchar('-'), write(-x);
        else {
            if (x > 9) write(x / 10);
            putchar('0' + x % 10);
        }
    }
} io;

const int mod = 1e9 + 7;
const int mo = 998244353;
const int N = 1e6 + 5;

int n, m, a[N], f[N], g[N];
long long b[N];

inline int min(int x, int y) { return (x > y) ? y : x; }

signed main() {
    io.read(n), io.read(m);
    For(i, 1, n) {
        io.read(a[i]);
        b[i] = b[i - 1] + a[i];
    }
    for (; m--;) {
        long long x;
        io.read(x);
        if (b[n] <= x) {
            puts("1");
            continue;
        }
        f[n + 1] = 0;
        Dow(i, n, 1) {
            g[i] = i;
            int l = i, r = n;
            f[i] = f[i + 1] + 1;
            while (l <= r) {
                int mid = l + r >> 1;
                if (b[mid] - b[i - 1] <= x)
                    g[i] = mid, l = mid + 1;
                else
                    r = mid - 1;
            }
            f[i] = f[g[i] + 1] + 1;
            if (g[i] == n)
                g[i] = i;
            else if (g[i] + 1 <= n)
                g[i] = g[g[i] + 1];
        }
        int ans = 1e9;
        For(i, 1, n) if (b[i - 1] <= x) {
            long long half = b[n] - b[g[i] - 1];
            if (half + b[i - 1] <= x)
                ans = min(ans, f[i]);
            else
                ans = min(ans, f[i] + 1);
        }
        else break;
        io.write(ans), putchar('\n');
    }
    return 0;
}