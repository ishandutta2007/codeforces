#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 100005;

vector<int> pri[N];
bool vis[N];
int n, dp[N], a[N];
int main() {
    for (int i = 2; i < N; i++) {
        if (vis[i]) continue;
        for (int j = i; j < N; j += i) {
            pri[j].push_back(i);
            vis[j] = true;
        }
    }
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    sort(a + 1, a + 1 + n);
    n = unique(a + 1, a + 1 + n) - a - 1;
    int ans = 1;
    for (int i = 1; i <= n; i++) {
        int Max = 0;
        for (int j = 0; j < pri[a[i]].size(); j++)
            Max = max(Max, dp[pri[a[i]][j]] + 1);
        ans = max(ans, Max);
        for (int j = 0; j < pri[a[i]].size(); j++)
            dp[pri[a[i]][j]] = max(dp[pri[a[i]][j]], Max);
    }
    printf("%d\n", ans);
    return 0;
}