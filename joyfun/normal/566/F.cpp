#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 1000005;

int n;
int cnt[N];
int dp[N];
vector<int> g[N];

int dfs(int num) {
    if (dp[num] != -1) return dp[num];
    dp[num] = cnt[num];
    for (int i = 0; i < g[num].size(); i++) {
        dp[num] = max(dp[num], dfs(num / g[num][i]) + cnt[num]);
    }
    return dp[num];
}

int f[N];

int main() {
    for (int i = 2; i < N; i++) {
        if (f[i]) continue;
        for (int j = i; j < N; j += i) {
            f[j] = 1;
            g[j].push_back(i);
        }
    }
    //int Max = 0;
    //for (int i = 1; i < N; i++)
    //Max = max(Max, (int)g[i].size());
   // printf("%d\n", Max);
    scanf("%d", &n);
    while (n--) {
        int x;
        scanf("%d", &x);
        cnt[x]++;
    }
    int ans = 0;
    memset(dp, -1, sizeof(dp));
    for (int i = 1; i < N; i++) {
        ans = max(ans, dfs(i));
    }
    printf("%d\n", ans);
    return 0;
}