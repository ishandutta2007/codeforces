// Hydro submission #62596c0e37de167dd82c2375@1650027535194
#include <bits/stdc++.h>
using namespace std;
#define int long long
 
inline int read() {
    int x = 0, f = 0; char c = 0;
    while (!isdigit(c)) f |= c == '-', c = getchar();
    while (isdigit(c)) x = (x << 3) + (x << 1) + (c & 15), c = getchar();
    return f ? -x : x;
}
 
#define N 200010
 
int n, P, f[N];
 
signed main() {
    n = read(), P = read();
    f[1] = 1;
    int now = 1;
    for (int i = 2; i <= n; i ++) {
        f[i] = now;
        for (int l = 2, r; l <= i; l = r + 1) {
            r = i / (i / l);
            (f[i] += (r - l + 1) % P * f[i / l] % P) %= P;
        }
        now = (now + f[i]) % P;
    }
    printf("%lld\n", f[n]);
    return 0;
}