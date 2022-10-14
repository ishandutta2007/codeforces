#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 605;
const int MAXM = MAXN * MAXN;
const llint INF = 1000000000000000000LL;

int n, m, q, sol;
int ea[MAXM], eb[MAXM];
llint w[MAXN][MAXN], d[MAXN][MAXN], cost[MAXN][MAXN];

void calc_dist () {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            d[i][j] = w[i][j];
        }
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (d[i][k] + d[k][j] < d[i][j]) d[i][j] = d[i][k] + d[k][j];
            }
        }
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i != j) w[i][j] = INF;
        }
    }
    for (int i = 1; i <= m; i++) {
        llint val;
        cin >> ea[i] >> eb[i] >> val;
        w[ea[i]][eb[i]] = w[eb[i]][ea[i]] = val;
    }
    calc_dist();
    cin >> q;
    for (int i = 1; i <= q; i++) {
        int u, v, len;
        cin >> u >> v >> len;
        for (int j = 1; j <= n; j++) {
            cost[j][u] = max(cost[j][u], len - d[j][v]);
            cost[j][v] = max(cost[j][v], len - d[j][u]);
        }
    }
    for (int i = 1; i <= m; i++) {
        int ok = 0;
        for (int j = 1; j <= n; j++) {
            if (w[ea[i]][eb[i]] + d[eb[i]][j] <= cost[ea[i]][j]) ok = 1;
            if (w[ea[i]][eb[i]] + d[ea[i]][j] <= cost[eb[i]][j]) ok = 1;
            if (ok) break;
        }
        sol += ok;
    }
    cout << sol;
    return 0;
}