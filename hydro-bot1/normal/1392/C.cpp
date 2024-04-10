// Hydro submission #623c5e1cf7716b87f5f05acd@1648123420259
#include <bits/stdc++.h>
using namespace std;
#define int long long
 
inline int read() {
    int x = 0, f = 0; char c = 0;
    while (!isdigit(c)) f |= c == '-', c = getchar();
    while (isdigit(c)) x = (x << 3) + (x << 1) + (c & 15), c = getchar();
    return f ? -x : x;
}
 
#define INF (1e9 + 7)
int a[200010];
 
signed main() {
    for (int T = read(); T --;) {
        int n = read(), res = 0;
        for (int i = 1; i <= n; i ++) {
            a[i] = read();
            res += max(0ll, a[i - 1] - a[i]);
        }
        printf("%lld\n", res);
    }
    return 0;
}