#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 2005;
const int MOD = 1000000007;

int m, d;
char bit[N];

void add(int &x, int y) {
    x += y;
    if (x >= MOD) x -= MOD;
}

int judge() {
    int n = strlen(bit);
    int x = 0;
    for (int i = 0; i < n; i++) {
        x = (x * 10 + bit[i] - '0') % m;
        if (i % 2 && bit[i] - '0' != d) return false;
        if (i % 2 == 0 && bit[i] - '0' == d) return false;
    }
    return x == 0;
}

int dp[N][N][2][2];

int solve() {
    int n = strlen(bit);
    int sum = 0, s1 = 0, s2 = 0, f = 1;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < m; j++) {
            memset(dp[i][j], 0, sizeof(dp[i][j]));
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int f1 = 0; f1 < 2; f1++) {
                for (int f2 = 0; f2 < 2; f2++) {
                    if (dp[i][j][f1][f2] == 0) continue;
                    int up = 9, down = 0;
                    if (f1) up = d, down = d;
                    for (int x = down; x <= up; x++) {
                        int t1 = f1, t2 = f2;
                        if (f2 || x) t1 ^= 1;
                        if (x) t2 = 1;
                        if (f1 && x != d) continue;
                        if (!f1 && x == d) continue;
                        add(dp[i + 1][(j * 10 + x) % m][t1][t2], dp[i][j][f1][f2]);
                    }
                }
            }
        }
        for (int x = 0; x < bit[i] - '0'; x++) {
            int t1 = s1, t2 = s2;
            if (s2 || x) t1 ^= 1;
            if (x) t2 = 1;
            if (s1 && x != d) continue;
            if (!s1 && x == d) continue;
            add(dp[i + 1][(sum * 10 + x) % m][t1][t2], f);
        }
        if (s1 && bit[i] - '0' != d) f = 0;
        if (!s1 && bit[i] - '0' == d) f = 0;
        s1 ^= 1; s2 = 1;
        sum = (sum * 10 + bit[i] - '0') % m;
    }
    int ans = 0;
    for (int f1 = 0; f1 < 2; f1++)
        add(ans, dp[n][0][f1][1]);
    return ans;
}

int main() {
    scanf("%d%d", &m, &d);
    scanf("%s", bit);
    int ans = 0;
    ans = (ans - solve() + MOD) % MOD;
    scanf("%s", bit);
    if (judge()) ans = (ans + 1) % MOD;
    ans = (ans + solve()) % MOD;
    printf("%d\n", ans);
    return 0;
}