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
char p[1000005];
int ps[1000005];
int z[1000005];
int main() {
    int n, m;
    n = read(), m = read();
    scanf("%s", p);
    int len = strlen(p);
    for (int i = 1, l = 0, r = 0; i < len; ++ i) {
        if (i < r) z[i] = min(r - i + 1, z[i - l]);
        for (; i + z[i] < len && p[i + z[i]] == p[z[i]]; ++ z[i]);
        if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
    }
    for (int i = 0; i < m; ++ i) ps[i] = read() - 1;
    int certain = m ? len : 0;
    for (int i = 1; i < m; ++ i) {
        if (ps[i] - ps[i - 1] + 1 <= len) {
            if (ps[i] - ps[i - 1] + z[ps[i] - ps[i - 1]] < len) {
                write(0); putchar(10); return 0;
            }
        }
        certain += len - max(0, ps[i - 1] + len - ps[i]);
    }
    int ans = 1;
    for (; certain < n; ++ certain) ans = 26LL * ans % 1000000007;
    write(ans); putchar(10);
    return 0;
}