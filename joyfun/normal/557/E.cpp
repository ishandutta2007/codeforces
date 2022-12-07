#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 5005;

char str[N];
int n, k;

int dp[N][N];

int ch[N * N][2], en;
int val[N * N];

void insert(int pos) {
    int u = 0;
    for (int i = pos; i < n; i++) {
        int c = str[i] - 'a';
        if (!ch[u][c])
            ch[u][c] = ++en;
        u = ch[u][c];
        val[u] += dp[pos][i];
    }
}

void gao(int k) {
    int u = 0;
    while (k > 0) {
        if (k <= val[ch[u][0]]) {
            int tmp = ch[u][0];
            k -= val[tmp] - val[ch[tmp][0]] - val[ch[tmp][1]];
            u = ch[u][0];
            printf("a");
        } else {
            int tmp = ch[u][1];
            k -= val[tmp] - val[ch[tmp][0]] - val[ch[tmp][1]] + val[ch[u][0]];
            u = ch[u][1];
            printf("b");
        }
    }
    printf("\n");
}

int main() {
    scanf("%s%d", str, &k);
    n = strlen(str);
    memset(dp, false, sizeof(dp));
    int l, r, u, flag[2];
    for (int i = 0; i < n; i++) {
        l = i; r = i; u = 0;
        flag[0] = flag[1] = 1;
        while (l >= 0 && r < n) {
            if (str[l] != str[r]) flag[u] = 0;
            if (flag[u]) dp[l][r] = true;
            u ^= 1;
            l--; r++;
        }
        l = i; r = i + 1; u = 0;
        flag[0] = flag[1] = 1;
        while (l >= 0 && r < n) {
            if (str[l] != str[r]) flag[u] = 0;
            if (flag[u]) dp[l][r] = true;
            u ^= 1;
            l--; r++;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = n - 1; j >= i; j--)
            dp[i][j] += dp[i][j + 1];
    }
    for (int i = 0; i < n; i++) {
        insert(i);
    }
    gao(k);
    return 0;
}