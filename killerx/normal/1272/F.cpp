#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

int n1, n2;
char s1[205], s2[205];
int dp[801][401][201];
int pr[801][401][201];

int main() {
    scanf("%s", s1);
    scanf("%s", s2);
    n1 = strlen(s1);
    n2 = strlen(s2);
    rep(i, n1) s1[i] -= 40;
    rep(i, n2) s2[i] -= 40;
    memset(dp, -0x3f, sizeof(dp));
    dp[0][0][0] = 0;
    auto update = [&] (int ni, int nopen, int nx1, int nx2, int c, int i, int open, int x1, int x2) {
        if (nopen < 0 || nopen > 400) return ;
        if (dp[ni][nopen][nx1] < nx2) {
            dp[ni][nopen][nx1] = nx2;
            pr[ni][nopen][nx1] = c * 805 * 405 * 205 + i * 405 * 205 + open * 205 + x1;
        }
    };
    std::function <void(int, int, int)> print = [&] (int i, int open, int x1) {
        if (!i) return ;
        print(pr[i][open][x1] / (405 * 205) % 805, pr[i][open][x1] / 205 % 405, pr[i][open][x1] % 205);
        putchar(40 + pr[i][open][x1] / (805 * 405 * 205));
    };
    rep(i, 801) {
        if (dp[i][0][n1] == n2) {
            print(i, 0, n1);
            return 0;
        }
        rep(open, 401) {
            rep(x1, n1 + 1) {
                int x2 = dp[i][open][x1];
                if (x2 >= 0) {
                    rep(c, 2) {
                        update(i + 1, open + (c == 0 ? +1 : -1), x1 + (x1 < n1 && s1[x1] == c), x2 + (x2 < n2 && s2[x2] == c), c, i, open, x1, x2);
                    }
                }
            }
        }
    }
    return 0;
}