// Hydro submission #623c6161f7716b87f5f05ec3@1648124258335
#include <bits/stdc++.h>
using namespace std;
#define int long long
 
inline int read() {
    int x = 0, f = 0; char c = 0;
    while (!isdigit(c)) f |= c == '-', c = getchar();
    while (isdigit(c)) x = (x << 3) + (x << 1) + (c & 15), c = getchar();
    return f ? -x : x;
}
 
char s[200010];
 
signed main() {
    for (int T = read(); T --;) {
        int n = read(), res = 0;
        scanf("%s", s + 1);
        int st = 1, i = 0;
        while (s[st] == s[1]) st ++;
        if (st > n) {
            if (n == 1) puts("0");
            else if (n == 2) puts("0");
            else if (n == 3) puts("1");
            else {
                res = n / 3;
                if (res * 3 != n) res ++;
                printf("%lld\n", res);
            }
            continue;
        }
        i = st;
        do {
            int j = i, nw = 1;
            while (s[(j == n ? 1 : j + 1)] == s[i] && (j == n ? 1 : j + 1) != st) {
                nw ++;
                j ++;
                if (j > n) j = 1;
            }
            res += nw / 3;
            i = j + 1;
            if (i > n) i = 1;
        } while (i != st);
        printf("%lld\n", res);
    }
    return 0;
}