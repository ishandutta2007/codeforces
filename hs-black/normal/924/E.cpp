#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define ll long long
using namespace std;

template <typename T>
void read(T &x) {
    x = 0; char c = getchar(); int f = 0;
    for (; !isdigit(c); c = getchar()) f |= c == '-';
    for (; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + (c ^ '0');
    if (f) x = -x;
}

template <typename T>
void write(T x, char ed = '\n') {
    static short st[30]; short tp = 0;
    if (x < 0) putchar('-'), x = -x;
    do st[++tp] = x % 10, x /= 10; while (x);
    while (tp) putchar(st[tp--] | '0');
    putchar(ed);
}

const int N = 10050;
struct node { int a, b; }p[N];
int dp[N], l, r, n, res;
template <typename T>
void Mx(T &x, T y) { x < y && (x = y); }
int main() {
    read(n), read(l), read(r);
    for (int i = 1;i <= n; i++) read(p[i].a), res += p[i].a;
    for (int i = 1;i <= n; i++) read(p[i].b);
    sort(p + 1, p + n + 1, [&](node a, node b){
        return a.b != b.b ? a.b < b.b : a.a > b.a;
    });
    memset(dp, -0x3f, sizeof(dp));
    int tnw = 0; dp[0] = 0; l = res - l, r = res - r, swap(l, r);
    for (int i = 1;i <= n; i++) {
        tnw += p[i].a;
        for (int j = tnw;j >= p[i].a; j--)
            Mx(dp[j], dp[j - p[i].a] + (p[i].b && j >= l && j <= r));
    }
    write(*max_element(dp, dp + tnw + 1));
    return 0;
}