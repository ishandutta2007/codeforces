#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;

template <typename T>
inline void read(T &f) {
    f = 0; T fu = 1; char c = getchar();
    while (c < '0' || c > '9') { if (c == '-') fu = -1; c = getchar(); }
    while (c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
    f *= fu;
}

template <typename T>
void print(T x) {
    if (x < 0) putchar('-'), x = -x;
    if (x < 10) putchar(x + 48);
    else print(x / 10), putchar(x % 10 + 48);
}

template <typename T>
void print(T x, char t) {
    print(x); putchar(t);
}

const int md = 998244353;

inline int add(int x, int y) {
    if (x + y >= md) return x + y - md;
    return x + y;
}

inline void addx(int &x, int y) {
    x += y;
    if (x >= md) x -= md;
}

inline int sub(int x, int y) {
    if (x < y) return x - y + md;
    return x - y;
}

inline void subx(int &x, int y) {
    x -= y;
    if (x < 0) x += md;
}

inline int mul(int x, int y) { return 1ull * x * y % md; }

inline int fpow(int x, int y) {
    int ans = 1;
    while (y) {
        if (y & 1) ans = mul(ans, x);
        y >>= 1; x = mul(x, x);
    }
    return ans;
}

const int N = 3e5 + 5;

pii g[N];
int nxt[N], pre[N], a[N], ban[N], vis[N], t[N], dp[N];
int n, m, k, len, flag;

void link(int u, int v) {
    if (nxt[u] && nxt[u] != v) {
        flag = 1;
        return;
    }
    if (pre[v] && pre[v] != u) {
        flag = 1;
        return;
    }
    nxt[u] = v; pre[v] = u;
}

int main() {
    read(n); read(m); read(k);
    for (int i = 1; i <= n; ++i) {
        int len; read(len);
        flag = 0;
        for (int j = 1; j <= len; ++j) {
            read(a[j]);
            if (j > 1) link(a[j - 1], a[j]);
        }
        if (flag) {
            for (int j = 1; j <= len; ++j) {
                ban[a[j]] = 1;
            }
        }
    }
    for (int i = 1; i <= k; ++i) {
        if (ban[i]) continue;
        if (!pre[i]) {
            int tmp = i, cando = 1;
            while (tmp) {
                if (ban[tmp]) cando = 0;
                tmp = nxt[tmp];
            }
            if (cando) {
                int qwq = 0;
                tmp = i;
                while (tmp) {
                    ++qwq;
                    vis[tmp] = 1;
                    tmp = nxt[tmp];
                }
                ++t[qwq];
            }
        }
    }
    for (int i = 1; i <= k; ++i) {
        if (t[i]) g[++len] = make_pair(i, t[i]);
    }
    dp[0] = 1;
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= len; ++j) {
            if (g[j].first > i) break;
            dp[i] = add(dp[i], mul(dp[i - g[j].first], g[j].second));
        }
    }
    print(dp[m], '\n');
    return 0;
}