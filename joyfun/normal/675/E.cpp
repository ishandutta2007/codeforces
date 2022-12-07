#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;
const int N = 100005;
int n, a[N], dp[20][N];
vector<int> g[N];

int get(int l, int r) {
    int len = 0;
    while ((1<<(len + 1)) <= r - l + 1) len++;
    if (a[dp[len][l]] > a[dp[len][r - (1<<len) + 1]]) return dp[len][l];
    else return dp[len][r - (1<<len) + 1];
}

long long ans[N];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n - 1; i++) scanf("%d", &a[i]);
    a[n] = INF;
    for (int i = 1; i <= n; i++) dp[0][i] = i;
    for (int i = 1; i < 20; i++) {
        for (int j = 1; j + (1<<i) - 1 <= n; j++) {
            if (a[dp[i - 1][j]] > a[dp[i - 1][j + (1<<(i - 1))]]) dp[i][j] = dp[i - 1][j];
            else dp[i][j] = dp[i - 1][j + (1<<(i - 1))];
        }
    }
    for (int i = 1; i <= n - 1; i++) {

        g[get(i + 1, a[i])].push_back(i);
    }
    queue<int> Q;
    Q.push(n);
    while (!Q.empty()) {
        int u = Q.front(); Q.pop();
        for (int i = 0; i < g[u].size(); i++) {
            int v = g[u][i];
            int tmp = a[v] - u;
            if (tmp < 0) tmp = 0;
            ans[v] = ans[u] + (n - v) - tmp;
            Q.push(v);
        }
    }
    long long tot = 0;
    for (int i = 1; i <= n - 1; i++) tot += ans[i];
    printf("%lld\n", tot);
    return 0;
}