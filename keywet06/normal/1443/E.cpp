
#include <bits/stdc++.h>
#define int long long
#define rd(x) x = read()
using namespace std;
const int N = 2e5 + 5;
inline int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while (ch > '9' || ch < '0') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}
int sum, n, q;
int a[16];
int P[16];
int fac[16];
bool vis[16];
void get(int sum) {
    long long res = 0;
    for (int i = 1; i < n; i++) res = (res + a[i]) * (n - i);
    for (int i = 1; i <= 15; i++) {
        a[i] = sum / fac[15 - i];
        sum %= fac[15 - i];
    }
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= 15; i++) {
        int cnt = 0;
        for (int j = 1; j <= 15; j++) {
            if (!vis[j]) cnt++;
            if (cnt == a[i] + 1) {
                P[i] = j;
                vis[j] = 1;
                break;
            }
        }
    }
}
signed main() {
    rd(n);
    rd(q);
    fac[0] = 1;
    for (int i = 1; i <= 15; i++) fac[i] = fac[i - 1] * i;
    while (q--) {
        int opt;
        rd(opt);
        if (opt == 1) {
            int l, r;
            rd(l);
            rd(r);

            int ans = 0;
            get(sum);
            if (r > n - 15) {
                if (l > n - 15) {
                    for (int i = l - n + 15; i <= r - n + 15; i++) ans += P[i];
                    ans += (r - l + 1) * (n - 15);
                } else {
                    ans += (l + n - 15) * (n - 14 - l) / 2;
                    for (int i = 1; i <= r - n + 15; i++) ans += P[i];
                    ans += (r - n + 15) * (n - 15);
                }
            } else
                ans = (l + r) * (r - l + 1) / 2;
            printf("%lld\n", ans);
        }
        if (opt == 2) {
            int x;
            rd(x);
            sum += x;
        }
    }
}