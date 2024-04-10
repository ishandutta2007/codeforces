#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef unsigned long long ll;
typedef pair<int, int> pii;
typedef double ld;
typedef pair<ll, ll> pll;

vector<vector<int> > g;
vector<vector<int> > s;
vector<int> color;

void dfs(int v, int p)
{
    set<int> used;
    for (int x : s[v]) {
        if (color[x] != -1) {
            used.insert(color[x]);
        }
    }
    int ptr = 0;
    for (int x : s[v]) {
        if (color[x] == -1) {
            while (used.count(ptr)) {
                ++ptr;
            }
            color[x] = ptr++;
        }
    }
    for (int to : g[v]) {
        if (to != p) {
            dfs(to, v);
        }
    }
}

int main()
{

	//ifstream cin("input.txt");
	//ofstream cout("output.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    s.resize(n);
    int ans = 1;
    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        ans = max(ans, k);
        s[i].resize(k);
        for (int j = 0; j < k; ++j) {
            cin >> s[i][j];
            --s[i][j];
        }
    }

    g.resize(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].pb(v);
        g[v].pb(u);
    }
    int root = 0;
    for (int i = 0; i < n; ++i) {
        if (sz(s[i]) == ans) {
            root = i;
        }
    }

    cout << ans << "\n";
    color.assign(m, -1);
    dfs(root, root);

    for (int i = 0; i < m; ++i) {
        if (color[i] == -1) {
            color[i] = 0;
        }
        cout << color[i] + 1 << " ";
    }
    cout << "\n";

}