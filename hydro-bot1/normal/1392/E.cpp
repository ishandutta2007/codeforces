// Hydro submission #623c67c7f7716b87f5f063ec@1648465798001
#include <bits/stdc++.h>
using namespace std;
#define int long long
 
inline int read() {
    int x = 0, f = 0; char c = 0;
    while (!isdigit(c)) f |= c == '-', c = getchar();
    while (isdigit(c)) x = (x << 3) + (x << 1) + (c & 15), c = getchar();
    return f ? -x : x;
}
 
#define N 110
 
int n, s[N], a[N][N];
 
signed main() {
    int n = read();
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= n; j ++) {
            int x = i + j;
            a[i][j] = (s[x] ++ & 1ll) << x - 2;
        }
    }
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= n; j ++) {
            printf("%lld ", a[i][j]);
        } 
        puts(""), fflush(stdout);
    }
    for (int T = read(); T --;) {
        int s = read(), x = 1, y = 1;
        while (x != n || y != n) {
            printf("%lld %lld\n", x, y), fflush(stdout);
            int st = s & (1ll << (x + y - 1ll));
            (st == a[x + 1][y] && x < n) ? x ++ : y ++;
        }
        printf("%lld %lld\n", x, y), fflush(stdout);
    }
    return 0;
}