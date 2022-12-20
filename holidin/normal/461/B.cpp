#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int N = 1e6 + 1;
const long long mod = 1e9 + 7;


vector <int> e[N];
long long ct[N][2], x[N];

void dfs(int u) {
    vector <long long> dp0, dp1;
    dp0.resize(e[u].size() + 1);
    dp1.resize(e[u].size() + 1);
    for (int i = 0; i <= e[u].size(); ++i) {
        dp0[i] = 0;
        dp1[i] = 0;
    }
    if (x[u] == 0)
        dp0[0] = 1;
    else
        dp1[0] = 1;
    for (int i = 0; i < e[u].size(); ++i) {
        dfs(e[u][i]);
        dp0[i + 1] = (dp0[i] * (ct[e[u][i]][0] + ct[e[u][i]][1])) % mod;
        dp1[i + 1] = (dp1[i] * (ct[e[u][i]][0] + ct[e[u][i]][1]) + dp0[i] * ct[e[u][i]][1]) % mod;
    }
    ct[u][0] = dp0[e[u].size()];
    ct[u][1] = dp1[e[u].size()];
}

int main() {
    int i, j, k, n;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (i = 1; i < n; ++i) {
        cin >> j;
        e[j].push_back(i);
    }
    for (i = 0; i < n; ++i)
        cin >> x[i];
    dfs(0);
    cout << ct[0][1];
}