#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 30005;

int n, d, cnt[N], dp[N][500];

int dfs(int u, int cha) {
    if (u > 30000) return 0;
    if (dp[u][cha] != -1) return dp[u][cha];
    int tmp = d + cha - 250;
    dp[u][cha] = cnt[u];
    int ans = 0;
    if (tmp > 1)
	ans = max(ans, dfs(u + tmp - 1, cha - 1));
    ans = max(ans, dfs(u + tmp, cha));
    ans = max(ans, dfs(u + tmp + 1, cha + 1));
    dp[u][cha] += ans;
    return dp[u][cha];
}

int main() {
    scanf("%d%d", &n, &d);
    int tmp;
    for (int i = 0; i < n; i++) {
	scanf("%d", &tmp);
	cnt[tmp]++;
    }
    memset(dp, -1, sizeof(dp));
    printf("%d\n", dfs(d, 250));
    return 0;
}