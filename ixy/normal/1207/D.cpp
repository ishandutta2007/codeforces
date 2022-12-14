#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int mod = 998244353;

inline int add(int x, int y) { return x + y >= mod ? x + y - mod : x + y; }
inline int sub(int x, int y) { return x - y >= 0 ? x - y : x - y + mod; }

const int N = 1e6 + 5;

int n, fac[N];

struct Number { int x, y; } a[N];

bool compare1(Number u, Number v) {
    return u.x < v.x;
}
int solve1() {
    std::sort(a, a + n, compare1);
    int res = 1;
    for (int i = 1, j = 0; i <= n; i++) {
        if (a[i].x != a[j].x) {
            res = 1ll * res * fac[i - j] % mod;
            j = i;
        }
    } return res;
}

bool compare2(Number u, Number v) {
    return u.y < v.y;
}
int solve2() {
    std::sort(a, a + n, compare2);
    int res = 1;
    for (int i = 1, j = 0; i <= n; i++) {
        if (a[i].y != a[j].y) {
            res = 1ll * res * fac[i - j] % mod;
            j = i;
        }
    } return res;
}

bool compare3(Number u, Number v) {
    if (u.x == v.x) { return u.y < v.y; }
    return u.x < v.x;
}
int solve3() {
    std::sort(a, a + n, compare3);
    for (int i = 1; i < n; i++) {
        if (a[i - 1].x > a[i].x || a[i - 1].y > a[i].y) {
            return 0;
        }
    } int res = 1;
    for (int i = 1, j = 0; i <= n; i++) {
        if (a[i].x != a[j].x || a[i].y != a[j].y) {
            res = 1ll * res * fac[i - j] % mod;
            j = i;
        }
    } return res;
}

int main() {
    n = read();
    for (int i = fac[0] = 1; i <= n; i++) { fac[i] = 1ll * fac[i - 1] * i % mod; }
    for (int i = 0; i < n; i++) { a[i] = (Number) {read(), read()}; }
    printf("%d\n", sub(fac[n], sub(add(solve1(), solve2()), solve3())));
    return 0;
}