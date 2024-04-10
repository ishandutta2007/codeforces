// Hydro submission #62907b821313ac7ae9bf380e@1653635970359
// #include <bits/stdc++.h>
// using namespace std;

// inline int read() {
//     int x = 0, f = 0; char c = 0;
//     while (!isdigit(c)) f |= c == '-', c = getchar();
//     while (isdigit(c)) x = (x << 3) + (x << 1) + (c & 15), c = getchar();
//     return f ? -x : x;
// }

// int n;
// char s[200005];

// int main() {
//     for (int T = read(); T --;) {
//         n = read();
//         scanf("%s", s + 1);
//         int res = 0;
//         int now = 1, tp = s[1];
//         for (int i = 2; i <= n; i ++) {
//             if (tp == s[i]) {
//                 now ++;
//             } else {
//                 if (now & 1) {
//                     res ++;
//                     now ++;
//                 } else {
//                     now = 1;
//                     tp = s[i];
//                 }
//             }
//         }
//         if (now & 1) res ++;
//         printf("%d\n", res);
//     }
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
#define int long long
 
inline int read() {
    int x = 0, f = 0; char c = 0;
    while (!isdigit(c)) f |= c == '-', c = getchar();
    while (isdigit(c)) x = (x << 3) + (x << 1) + (c & 15), c = getchar();
    return f ? -x : x;
}

#define N 5005

int n, a[N], res = 0;

struct BIT {
    int c[N];
    void clear() { memset(c, 0, sizeof c); }
    void add(int x, int v) {
        for (; x < N && x; x += x & -x) c[x] += v;
    }
    int ask(int x, int r = 0) {
        for (; x; x -= x & -x) r += c[x];
        return r;
    }
} c1, c2;
 
signed main() {
    for (int T = read(); T --;) {
        n = read(), res = 0;
        for (int i = 1; i <= n; i ++) {
            a[i] = read();
        }
        for (int i = 1; i <= n; i ++) {
            c1.clear(), c2.clear();
            for (int j = i + 2; j <= n; j ++) {
                c2.add(a[j], 1);
            }
            int now = 0;
            for (int j = i + 1; j <= n; j ++) {
                if (a[j] > a[i]) {
                    // cout << i << ' ' << j << ' ' << now << " cnm\n";
                    res += now;
                }
                // cout << c1.ask(a[j + 1]) << endl;
                now -= (j - 1 - i) - c1.ask(a[j + 1]);
                c1.add(a[j], 1), c2.add(a[j + 1], -1);
                // cout << c2.ask(a[j]) << " zz\n";
                now += c2.ask(a[j]);
            }
        }
        printf("%lld\n", res);
    }
    return 0;
}