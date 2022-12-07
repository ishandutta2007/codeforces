#include <cstdio>
#include <cstring>
#include <vector>
#include <stack>
#include <algorithm>
#include <string>
#include <iostream>
#include <map>
using namespace std;

typedef long long ll;

const int N = 1000005;

vector<int> g[N], scc[N];
int pre[N], lowlink[N], sccno[N], dfs_clock, scc_cnt;
stack<int> S;

typedef pair<ll, ll> pii;
int n, m, hn;
map<string, int> hash;
string str[N];
pii s[N];
pii p[N];
pii dp[N];
int vis[N];

vector<int> g2[N];

void dfs_scc(int u) {
    pre[u] = lowlink[u] = ++dfs_clock;
    S.push(u);
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if (!pre[v]) {
            dfs_scc(v);
            lowlink[u] = min(lowlink[u], lowlink[v]);
        } else if (!sccno[v])
            lowlink[u] = min(lowlink[u], pre[v]);
    }
    if (lowlink[u] == pre[u]) {
        scc_cnt++;
        pii tmp = s[S.top()];
        while (1) {
            int x = S.top(); S.pop();
            tmp = min(tmp, s[x]);
            sccno[x] = scc_cnt;
            if (x == u) break;
        }
        p[scc_cnt] = tmp;
    }
}

void find_scc(int n) {
    dfs_clock = scc_cnt = 0;
    memset(sccno, 0, sizeof(sccno));
    memset(pre, 0, sizeof(pre));
    for (int i = 0; i < n; i++)
        if (!pre[i]) dfs_scc(i);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < g[i].size(); j++) {
            int u = sccno[i], v = sccno[g[i][j]];
            if (u == v) continue;
            g2[u].push_back(v);
        }
    }
}

int get(string& str) {
    for (int i = 0; i < str.length(); i++)
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] = str[i] - 'A' + 'a';
    if (!hash.count(str)) {
        hash[str] = hn;
        int cnt = 0;
        for (int i = 0; i < str.length(); i++)
            if (str[i] == 'r') cnt++;
        s[hn].first = cnt;
        s[hn].second = str.length();
        hn++;
    }
    return hash[str];
}

pii dfs(int u) {
    if (vis[u]) return dp[u];
    vis[u] = 1;
    dp[u] = p[u];
    for (int i = 0; i < g2[u].size(); i++) {
        int v = g2[u][i];
        dp[u] = min(dp[u], dfs(v));
    }
    return dp[u];
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        cin >> str[i];
        get(str[i]);
    }
    scanf("%d", &m);
    string u, v;
    while (m--) {
        cin >> u >> v;
        int uu = get(u);
        int vv = get(v);
        g[uu].push_back(vv);
    }
    find_scc(hn);
    ll ans1 = 0, ans2 = 0;
    for (int i = 0; i < n; i++) {
        int u = sccno[get(str[i])];
        dfs(u);
        ans1 += dp[u].first;
        ans2 += dp[u].second;
    }
    cout << ans1 << " " << ans2 << endl;
    return 0;
}