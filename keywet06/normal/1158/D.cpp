#include <bits/stdc++.h>

typedef long long int64;

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
    a = b, b = c;
}

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

inline int sq(int x) { return x * x; }

}  // namespace algo

using namespace algo;

const int N = 2000;

struct Point {
    int x, y;
    void read() { x = read_int(), y = read_int(); }
    bool operator<(const Point& a) { return x != a.x ? x < a.x : y < a.y; }
    Point operator-(const Point& a) const { return {x - a.x, y - a.y}; }
    int64 operator^(const Point& a) const { return 1ll * x * a.y - 1ll * y * a.x; }
};

int n, x;
int vis[N];

Point p[N];

int main() {
    n = read_int();
    for (int i = 0; i != n; ++i) p[i].read();
    for (int i = 1; i != n; ++i) {
        if (p[i] < p[x]) x = i;
    }
    printf("%d ", x + 1);
    vis[x] = 1;
    for (int i = 0; i != n - 2; ++i) {
        bool t = read_char() == 'R';
        int y = -1;
        for (int i = 0; i != n; ++i) {
            if (vis[i]) continue;
            if (!~y) {
                y = i;
            } else if (((p[y] - p[x]) ^ (p[i] - p[x])) > 0 == t) {
                y = i;
            }
        }
        vis[y] = 1;
        x = y;
        printf("%d ", x + 1);
    }
    for (int i = 0; i != n; ++i) {
        if (!vis[i]) printf("%d\n", i + 1);
    }
    return 0;
}