#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read() {
    int  x = 0, f = 1, c = getchar();
    for (;!isdigit(c); c = getchar()) if (c == '-') f ^= 1;
    for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
    return f ? x : -x;
}
inline void write(int x) {
    if (!x) {putchar('0'); return;}
    if (x < 0) {putchar('-'); x = -x;}
    int stk[20], tp = 0;
    for (; x; x /= 10) stk[tp ++] = x % 10;
    for (; tp; putchar(stk[-- tp] + '0')) ;
}
int main() {
    int A, B, n;
    A = read(), B = read(), n = read();
    for (; n --; ) {
        int l, t, m;
        l = read(), t = read(), m = read();
        int lb = l, rb = 1e8;
        auto chk = [&] (int r) {
            ll used = ((A + 1LL * (l - 1) * B) + (A + 1LL * (r - 1) * B)) * (r - l + 1) / 2;
            return A + 1LL * (r - 1) * B <= t && used <= 1LL * t * m;
        };
        while (lb < rb) {
            int md = (lb + rb + 1) >> 1;
            if (chk(md)) lb = md;
            else rb = md - 1; 
        }
        write(A + 1LL * (l - 1) * B <= t ? lb : -1); putchar(10);
    }
    return 0;
}