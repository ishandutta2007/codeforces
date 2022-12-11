#include <bits/stdc++.h>
#include <string.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;
typedef pair<ll, int> pll;

const int inf = 1e9;

vector<vector<int > > g;
vector<int> dp;
map<int, int> pos;

bool comp(int a, int b)
{
    return dp[a] < dp[b];
}

void dfs_build(int v, int p)
{
    if (sz(g[v]) == 1 && g[v][0] == p) {
        dp[v] = pos[v];
        return;
    }
    for (int to : g[v]) {
        if (to != p) {
            dfs_build(to, v);
            dp[v] = min(dp[v], dp[to]);
        }
    }
}

vector<int> ans;

void dfs(int v, int p)
{
    ans.pb(v);
    if (sz(g[v]) == 1 && g[v][0] == p) {
        return;
    }
    vector<int> sons;
    for (int to : g[v]) {
        if (to != p) {
            sons.pb(to);
        }
    }
    sort(all(sons), comp);
    for (int to : sons) {
        dfs(to, v);
        ans.pb(v);
    }
}

int main()
{

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);

    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    int n;
    cin >> n;
    g.resize(n);
    dp.assign(n, inf);

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].pb(v);
        g[v].pb(u);
    }
    int id = 0;
    int leaf;
    vector<int> leaves;
    while (cin >> leaf) {
        --leaf;
        leaves.pb(leaf);
        pos[leaf] = id++;
    }

    dfs_build(0, 0);
    dfs(0, 0);

    map<int, int> f;
    for (int i = 0; i < sz(ans); ++i) {
        f[ans[i]] = i;
    }
    for (int i = 0; i < sz(leaves) - 1; ++i) {
        if (f[leaves[i]] > f[leaves[i + 1]]) {
            cout << "-1\n";
            return 0;
        }
    }
    for (int x : ans) {
        cout << x + 1 << " ";
    }
    cout << "\n";

}