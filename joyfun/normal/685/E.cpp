#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 200005;
const int INF = 0x3f3f3f3f;

int n, m, q;
int u[N], v[N];
int r[N], s[N], t[N], ans[N];
int dp[1005][1005];
vector<int> Q[N];

int main() {
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 1; i <= m; i++)scanf("%d%d", &u[i], &v[i]);
    int l;
    for (int i = 0; i < q; i++) {
        scanf("%d%d%d%d", &l, &r[i], &s[i], &t[i]);
        Q[l].push_back(i);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++){
            if (i != j) dp[i][j] = INF;
        }
    }
    for (int i = m; i >= 1; i--) {
        for (int j = 1; j <= n; j++) {
            int tmp = min(dp[u[i]][j], dp[v[i]][j]);
            dp[u[i]][j] = dp[v[i]][j] = tmp;
        }
        dp[u[i]][v[i]] = dp[v[i]][u[i]] = i;
        for (int j = 0; j < Q[i].size(); j++) {
            int id = Q[i][j];
            if (dp[s[id]][t[id]] <= r[id]) ans[id] = 1;
        }
    }
    for (int i = 0; i < q; i++) printf("%s\n", ans[i] ? "Yes" : "No");
    return 0;
}