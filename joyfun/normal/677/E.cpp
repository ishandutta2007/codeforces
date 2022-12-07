#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;
const int N = 2005;
int n;
char str[N][N], tmp[N][N];
double lg2 = log(2.0), lg3 = log(3.0);
int p2[N], p3[N];

struct Ans {
    int a, b;
    Ans() {a = 0; b = 0;}
    bool operator < (const Ans& c) const {
        return (a - c.a) * 1.0 < lg3 / lg2 * (c.b - b) * 1.0;
    }
    bool operator > (const Ans &c) const {
        return (a - c.a) * 1.0 > lg3 / lg2 * (c.b - b) * 1.0;
    }
};

int len[4][N][N], sum[2][N][N][2];
int vis[N][N];

Ans solve() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            //printf("%c", str[i][j]);
            sum[0][i][j][0] = sum[0][i][j - 1][0] + (str[i][j] == '2');
            sum[0][i][j][1] = sum[0][i][j - 1][1] + (str[i][j] == '3');
            len[0][i][j] = len[0][i][j - 1] + 1;
            if (str[i][j] == '0') len[0][i][j] = 0;

            sum[1][j][i][0] = sum[1][j - 1][i][0] + (str[j][i] == '2');
            sum[1][j][i][1] = sum[1][j - 1][i][1] + (str[j][i] == '3');
            len[2][j][i] = len[2][j - 1][i] + 1;
            if (str[j][i] == '0') len[2][j][i] = 0;
        }
        //printf("\n");
        len[1][i][n + 1] = 0; len[3][n + 1][i] = 0;
        for (int j = n; j >= 1; j--) {
            len[1][i][j] = len[1][i][j + 1] + 1;
            if (str[i][j] == '0') len[1][i][j] = 0;
            len[3][j][i] = len[3][j + 1][i] + 1;
            if (str[j][i] == '0') len[3][j][i] = 0;
        }
    }
    Ans ans;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (str[i][j] == '0') continue;
            if (vis[i][j]) continue;
            int sb = INF;
            for (int k = 0; k < 4; k++)
                sb = min(sb, len[k][i][j]);
            Ans tmp;
            tmp.a = sum[0][i][j + sb - 1][0] - sum[0][i][j - sb][0] + sum[1][i + sb - 1][j][0] - sum[1][i - sb][j][0];
            tmp.b = sum[0][i][j + sb - 1][1] - sum[0][i][j - sb][1] + sum[1][i + sb - 1][j][1] - sum[1][i - sb][j][1];
            if (str[i][j] == '2') tmp.a--;
            if (str[i][j] == '3') tmp.b--;
            ans = max(ans, tmp);
        }
    }
    return ans;
}

void rot() {
    for (int i = 1; i <= n * 2; i++)
        for (int j = 1; j <= n * 2; j++)
            tmp[i][j] = '0';
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int h = i + j - 1;
            tmp[h][j * 2 - 1 + n - h] = str[i][j];
            if (i != 1 && j != n) {
                tmp[h][j * 2 + n - h] = '1';
                vis[h][j * 2 + n - h] = 1;
            }
        }
    }
    n *= 2;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            str[i][j] = tmp[i][j];
}

int main() {
    p2[0] = p3[0] = 1;
    for (int i = 1; i < N; i++) {
        p2[i] = 2LL * p2[i - 1] % MOD;
        p3[i] = 3LL * p3[i - 1] % MOD;
    }
    Ans ans;
    scanf("%d", &n);
    int f = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%s", str[i] + 1);
        for (int j = 1; j <= n; j++) {
            if (str[i][j] != '0') f = 1;
        }
    }
    if (!f) {
        printf("0\n");
        return 0;
    }
    ans = max(ans, solve());
    rot();
    ans = max(ans, solve());
    printf("%d\n", 1LL * p2[ans.a] * p3[ans.b] % MOD);
    return 0;
}