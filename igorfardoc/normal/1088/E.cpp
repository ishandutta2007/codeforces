#include<bits/stdc++.h>
#define inf 1000000000000000000ll
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
vvi g;
int n;
vi a;
int k;
ll ans;
vector<ll> dp;

void dfs1(int v, int p) {
    dp[v] = a[v];
    for(int u : g[v]) {
        if(u == p) continue;
        dfs1(u, v);
        dp[v] += max(0ll, dp[u]);
    }
    ans = max(ans, dp[v]);
}

void dfs2(int v, int p) {
    dp[v] = a[v];
    for(int u : g[v]) {
        if(u == p) continue;
        dfs2(u, v);
        dp[v] += max(0ll, dp[u]);
    }
    if(dp[v] == ans) {
        ++k;
        dp[v] = 0;
    }
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifdef _FILE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin >> n;
    g.resize(n);
    a.resize(n);
    dp.resize(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n - 1; i++) {
        int v, u;
        cin >> v >> u;
        --v;
        --u;
        g[v].push_back(u);
        g[u].push_back(v);
    }
    ans = -inf;
    dfs1(0, -1);
    dfs2(0, -1);
    cout << ans * k << ' ' << k;
}