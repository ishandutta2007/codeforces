// Hydro submission #6290747c37e0de7afd3990d5@1653634173274
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
 
inline int read() {
    int x = 0, f = 0; char c = 0;
    while (!isdigit(c)) f |= c == '-', c = getchar();
    while (isdigit(c)) x = (x << 3) + (x << 1) + (c & 15), c = getchar();
    return f ? -x : x;
}
 
#define N 1000005
 
int n, m;
char s[N];
 
int main() {
    for (int T = read(); T --;) {
        n = read(), m = read();
        scanf("%s", s + 1);
        vector<int> sum;
        vector<vector<bool>> a;
        vector<vector<int>> res, ans;
        sum.resize(m + 1);
        a.resize(n + 1, vector<bool>(m + 1));
        res.resize(n + 1, vector<int>(m + 1));
        ans.resize(n + 1, vector<int>(m + 1));
        for (int i = 1, k = 1; i <= n; i ++) {
            for (int j = 1; j <= m; j ++) {
                a[i][j] = s[k ++] - '0';
            }
        }
        for (int i = 1, k = 1; i <= n; i ++) {
            for (int j = 1; j <= m; j ++, k --) {
                if (!k) k = m;
                sum[k] += a[i][j];
                if (j == 1) res[i][j] = res[i - 1][m];
                else res[i][j] = res[i][j - 1];
                if (sum[k] == 1 && a[i][j]) res[i][j] ++;
            }
        }
        for (int l = 1, r = 0, now = 0, i = 1, j = 0;;) {
            now += s[++ r] - '0';
            j ++;
            if (j > m) i ++, j = 1;
            if (r > n * m) break;
            if (r - l + 1 > m) now -= s[l ++] - '0';
            if (now == 0) continue;
            ans[i][j] += 1;
        }
        for (int i = 1; i <= m; i ++) {
            for (int j = 1; j <= n; j ++) {
                ans[j][i] += ans[j - 1][i];
                res[j][i] += ans[j][i];
            }
        }
        for (int i = 1; i <= n; i ++) {
            for (int j = 1; j <= m; j ++) {
                printf("%d ", res[i][j]);
            }
        }
        puts("");
    }
    return 0;
}