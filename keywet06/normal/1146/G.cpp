#include <bits/stdc++.h>

const int INF = 1e9;

namespace FastIO {

const int BUF_SIZE = 1 << 24;

char buf[BUF_SIZE], *p1, *p2;

inline char gc() { return p1 == p2 ? p2 = (p1 = buf) + fread(buf, 1, BUF_SIZE, stdin) : 0, p1 == p2 ? -1 : *p1++; }

inline int read_int() {
    int ans = 0;
    char c = gc();
    bool sign = 0;
    for (; (~c) && !isdigit(c); c = gc()) sign = (c == '-');
    for (; isdigit(c); c = gc()) ans = (ans << 3) + (ans << 1) + (c ^ '0');
    if (sign) ans = -ans;
    return ans;
}

inline char read_char() {
    char c = gc();
    for (; isspace(c);) c = gc();
    return c;
}

inline int read_string(char* p) {
    char* q = p;
    char c = gc();
    for (; isspace(c); c = gc())
        ;
    for (; (~c) && !isspace(c); c = gc()) *q++ = c;
    *q = 0;
    return q - p;
}

}  // namespace FastIO

using namespace FastIO;

namespace algo {

template <class T>
inline const T& min(const T& a, const T& b) {
    return a < b ? a : b;
}

template <class T>
inline const T& max(const T& a, const T& b) {
    return a > b ? a : b;
}

template <class T>
inline void swap(T& a, T& b) {
    T c = a;
    a = b;
    b = c;
}

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

inline int sq(int x) { return x * x; }

template <class T>
inline void fill(T* a, T* b, const T& c) {
    for (; a != b; *a++ = c)
        ;
}

}  // namespace algo

using namespace algo;

const int N = 50;

int n, h, m;

namespace Flow {

const int V = 2552, E = 10100;

struct Edge {
    int to, next, cap;
} e[E];

int n, s, t, Tot;
int head[V], cur[V], h[V];

void link(int u, int v, int cap) {
    e[Tot] = {v, head[u], cap};
    head[u] = Tot++;
    e[Tot] = {u, head[v], 0};
    head[v] = Tot++;
}

bool bfs() {
    static int q[V];
    fill(h, h + n, -1);
    h[s] = 0;
    int l = 0, r = 0;
    q[r++] = s;
    for (; l != r;) {
        int u = q[l++];
        for (int i = head[u]; ~i; i = e[i].next) {
            int v = e[i].to, cap = e[i].cap;
            if (cap && !~h[v]) {
                h[v] = h[u] + 1;
                if (v == t) return 1;
                q[r++] = v;
            }
        }
    }
    return 0;
}

int dfs(int u, int Flow) {
    if (u == t) return Flow;
    int res = Flow;
    for (int& i = cur[u]; ~i && res; i = e[i].next) {
        int v = e[i].to, cap = e[i].cap;
        if (cap && h[v] == h[u] + 1) {
            int min_flow = dfs(v, min(res, cap));
            res -= min_flow;
            e[i].cap -= min_flow;
            e[i ^ 1].cap += min_flow;
        }
    }
    return Flow - res;
}

int Solve() {
    int Flow = 0;
    for (; bfs();) {
        memcpy(cur, head, n * sizeof(int));
        int augment_flow;
        for (; (augment_flow = dfs(s, INF));) Flow += augment_flow;
    }
    return Flow;
}

}  // namespace Flow

int main() {
    n = read_int();
    h = read_int();
    m = read_int();
    Flow::n = n * h + m + 2;
    Flow::s = Flow::n - 2;
    Flow::t = Flow::n - 1;
    fill(Flow::head, Flow::head + Flow::n, -1);
    for (int i = 0; i < n; ++i) Flow::link(Flow::s, i * h, sq(h));
    for (int i = 0; i < n; ++i)
        for (int j = 1; j < h; ++j) Flow::link(i * h + j - 1, i * h + j, sq(h) - sq(j));
    for (int i = 0; i < m; ++i) {
        int l, r, x, c;
        l = read_int();
        r = read_int();
        x = read_int();
        c = read_int();
        if (x == h) continue;
        for (int j = l - 1; j < r; ++j) Flow::link(j * h + x, n * h + i, INF);
        Flow::link(n * h + i, Flow::t, c);
    }
    printf("%d\n", n * sq(h) - Flow::Solve());
    return 0;
}