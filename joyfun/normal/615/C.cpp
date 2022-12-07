#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 2105;
const int INF = 0x3f3f3f3f;

char a[N], b[N];
int ch[N * N][26], l[N * N], r[N * N];
int n;
int sz;
int dp[N], path[N], save[N][N][2];

void print(int n) {
    if (n == 0) return;
    int pre = path[n];
    print(pre);
    printf("%d %d\n", save[pre + 1][n][0], save[pre + 1][n][1]);
}

int main() {
    scanf("%s%s", a + 1, b + 1);
    n = strlen(a + 1);
    sz = 1;
    for (int i = 1; i <= n; i++) {
        int u = 0;
        for (int j = i; j <= n; j++) {
            int c = a[j] - 'a';
            if (!ch[u][c]) {
                l[sz] = i;
                r[sz] = j;
                ch[u][c] = sz++;
            }
            u = ch[u][c];
        }
    }
    for (int i = n; i >= 1; i--) {
        int u = 0;
        for (int j = i; j >= 1; j--) {
            int c = a[j] - 'a';
            if (!ch[u][c]) {
                l[sz] = i;
                r[sz] = j;
                ch[u][c] = sz++;
            }
            u = ch[u][c];
        }
    }
    n = strlen(b + 1);
    for (int i = 1; i <= n; i++) dp[i] = INF;
    for (int i = 0; i < n; i++) {
        int u = 0;
        for (int j = i + 1; j <= n; j++) {
            int c = b[j] - 'a';
            if (!ch[u][c]) break;
            u = ch[u][c];
            if (dp[j] > dp[i] + 1) {
                dp[j] = dp[i] + 1;
                path[j] = i;
                save[i + 1][j][0] = l[u];
                save[i + 1][j][1] = r[u];
            }
        }
    }
    if (dp[n] == INF) printf("-1\n");
    else {
        printf("%d\n", dp[n]);
        print(n);
    }
    return 0;
}