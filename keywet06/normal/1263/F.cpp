#include <bits/stdc++.h>

using namespace std;

using pairi = pair<int, int>;

const int B = 2;
const int N = 2005;
const int Inf = 1000000000;

int n, n1, n2;
int dp[N][2];
int dp1[N][N], dp2[N][N];

pairi has1[N], has2[N];

vector<int> neigh1[N], neigh2[N];

void Read(int &m, vector<int> neigh[], pairi has[]) {
    scanf("%d", &m);
    for (int i = 2; i <= m; i++) {
        int p;
        scanf("%d", &p);
        neigh[p].push_back(i);
    }
    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        has[x] = pairi(i, i);
    }
}

void Traverse(int v, vector<int> neigh[], pairi has[], int dp[][N]) {
    if (has[v] == pairi(0, 0)) has[v] = pairi(Inf, -Inf);
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        Traverse(u, neigh, has, dp);
        has[v].first = min(has[v].first, has[u].first);
        has[v].second = max(has[v].second, has[u].second);
    }
    if (v != 1) dp[has[v].first][has[v].second]++;
}

void Prepare(int dp[][N]) {
    for (int l = 1; l <= n; l++)
        for (int i = 1, j = i + l; j <= n; i++, j++) {
            dp[i][j] += dp[i + 1][j] + dp[i][j - 1];
            if (i + 1 <= j - 1) dp[i][j] -= dp[i + 1][j - 1];
        }
}

int main() {
    scanf("%d", &n);
    Read(n1, neigh1, has1);
    Read(n2, neigh2, has2);
    Traverse(1, neigh1, has1, dp1);
    Traverse(1, neigh2, has2, dp2);
    Prepare(dp1);
    Prepare(dp2);
    fill((int *)dp, (int *)dp + N * 2, -Inf);
    dp[1][0] = dp[1][1] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n + 1; j++) {
            dp[j][0] = max(dp[j][0], dp[i][1] + dp2[i][j - 1]);
            dp[j][1] = max(dp[j][1], dp[i][0] + dp1[i][j - 1]);
        }
    printf("%d\n", max(dp[n + 1][0], dp[n + 1][1]));
    return 0;
}