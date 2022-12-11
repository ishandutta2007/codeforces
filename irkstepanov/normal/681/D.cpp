#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define mp make_pair
#define pb push_back

#define fori for (int i = 0; i < n; ++i)
#define forj for (int j = 0; j < n; ++j)

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

vector<vector<int> > g;
vector<char> marked;
vector<int> cnt;
vector<int> parent;
vector<int> seq;

void dfs(int v)
{
    cnt[v] = 0;
    if (marked[v]) {
        ++cnt[v];
    }
    if (parent[v] != -1) {
        cnt[v] += cnt[parent[v]];
    }
    for (int to : g[v]) {
        dfs(to);
    }
    if (marked[v]) {
        seq.pb(v);
    }
}

int main()
{

    //ifstream cin("input");
    //ofstream cout("output");

    //freopen("input", "r", stdin);

    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    g.resize(n);
    marked.assign(n, false);
    cnt.resize(n);
    parent.assign(n, -1);

    int m;
    cin >> m;
    while (m--) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        parent[v] = u;
        g[u].pb(v);
    }

    vector<int> a(n);
    fori {
        cin >> a[i];
        --a[i];
        marked[a[i]] = true;
    }

    fori {
        if (parent[i] == -1) {
            dfs(i);
        }
    }

    fori {
        if (cnt[i] != cnt[a[i]]) {
            cout << "-1\n";
            return 0;
        }
    }

    cout << sz(seq) << "\n";
    for (int x : seq) {
        cout << x + 1 << "\n";
    }

}