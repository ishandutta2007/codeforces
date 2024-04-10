#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

const int N = 1000010;
const int P = 1000000007;

char s[N];

int n, m;
int sum[N];

int64 f[N], g[N], ep[N];

int cal(char ch) {
    if (ch == 'X') return 2;
    return 1;
}

int main() {
    int i, j, k;
    while (scanf("%d%d", &n, &m) != EOF) {
        scanf("%s", s + 1);
        int pos = 0;
        sum[0] = 0,
        ep[0] = 1;
        for (i = 1; i <= n; ++i) {
            sum[i] = sum[i - 1];
            if (s[i] == 'X') ++sum[i];
            ep[i] = (ep[i - 1] * 2) % P;
        }
        f[0] = 0,
        s[0] = '$';
        for (i = 1; i <= n; ++i) {
            f[i] = 0;
            f[i] += f[i - 1] * cal(s[i]);
            if (s[i] == 'B' || s[i] == 'X') {
                if (i - pos >= m && s[i - m] != 'B') {
                    if (i - m == 0) {
                        ++f[i];
                    } else {
                        f[i] += ep[sum[i - m - 1]] - f[i - m - 1];
                    }
                }
            }
            f[i] %= P;
            if (s[i] == 'W') pos = i;
        }
        pos = n + 1;
        sum[n + 1] = 0;
        for (i = n; i >= 1; --i) {
            sum[i] = sum[i + 1];
            if (s[i] == 'X') ++sum[i];
        }
        g[n + 1] = 0;
        int64 res = 0;
        s[n + 1] = '$';
        for (i = n; i >= 1; --i) {
            g[i] = 0;
            g[i] += g[i + 1] * cal(s[i]);
            if (s[i] == 'W' || s[i] == 'X') {
                if (pos - i >= m && s[i + m] != 'W') {
                    if (i + m == n + 1) {
                        res += f[i - 1], ++g[i];
                    } else {
                        g[i] += ep[sum[i + m + 1]] - g[i + m + 1];
                        res +=
                            ((ep[sum[i + m + 1]] - g[i + m + 1]) * f[i - 1]) %
                            P;
                    }
                    res %= P;
                }
            }
            g[i] %= P;
            if (s[i] == 'B') pos = i;
        }
        res %= P;
        res = (res + P) % P;
        cout << res << endl;
    }
    return 0;
}