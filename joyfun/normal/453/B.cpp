#include <cstdio>
#include <cstring>
#include <cstdlib>

const int N = 105;
const int MAXN = (1<<16) + 5;
const int INF = 0x3f3f3f3f;

int n, num[N], prime[N], pn = 0, vis[N], to[N];

void get_prime() {
    for (int i = 2; i < 59; i++) {
    if (vis[i]) continue;
    prime[pn++] = i;
    for (int j = i * i; j < 60; j += i) {
        vis[j] = 1;
    }
    }
}

int tra(int num) {
    int ans = 0;
    for (int i = 0; i < pn; i++) {
    if (num % prime[i] == 0) ans |= (1<<i);
    while (num % prime[i] == 0) num /= prime[i];
    }
    return ans;
}

int dp[N][MAXN], zh[N][MAXN][2];

void print(int now, int s) {
    if (now == 0) return;
    print(now - 1, zh[now][s][0]);
    printf("%d%c", zh[now][s][1], now == n? '\n' : ' ');
}

int main() {
    get_prime();
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    scanf("%d", &num[i]);
    for (int i = 1; i < 59; i++)
    to[i] = tra(i);
    int maxs = (1<<pn);
    memset(dp, INF, sizeof(dp));
    memset(dp[0], 0, sizeof(dp[0]));
    for (int i = 1; i <= n; i++) {
    for (int j = 1; j < 59; j++) {
        int x = (~to[j])&(maxs - 1);
        for (int k = x; ; k = (k - 1)&x) {
        int ss = k^to[j];
        if (dp[i][ss] > dp[i - 1][k] + abs(num[i] - j)) {
            dp[i][ss] = dp[i - 1][k] + abs(num[i] - j);
            zh[i][ss][0] = k;
            zh[i][ss][1] = j;
        }
        if (k == 0) break;
        }
    }
    }
    int Min = INF, Min_v;
    for (int i = 0; i < maxs; i++) {
    if (dp[n][i] < Min) {
        dp[n][i] = Min;
        Min_v = i;
    }
    }
    print(n, Min_v);
    return 0;
}