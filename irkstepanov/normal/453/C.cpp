#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <queue>

#define pb push_back
#define mp make_pair

#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;
typedef long double ld;

vector <vector <int> > g;
int n, m;
vector <int> x;

vector <char> used, ready;
vector <int> is;
vector <int> ans;

void dfs (int v, int pr)
{
    used[v] = true;
    ++is[v];
    ans.pb(v);
    int son = -1;
    for (int i = 0; i < g[v].size(); i++)
    {
        int to = g[v][i];
        if (!ready[to] && !used[to])
        {
            dfs(to, v);
            son = to;
        }
    }
    if (is[v] % 2 != x[v])
    {
        if (pr != -1)
        {
            ans.pb(pr), ans.pb(v);
            ++is[v], ++is[pr];
        }
        else
        {
            ans.pb(son), ans.pb(v), ans.pb(son);
            ++is[v];
        }
    }
    if (pr != -1) {++is[pr]; ans.pb(pr);}
    ready[v] = true;
}

int main()
{

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    int n, m;
    cin >> n >> m;
    g.resize(n);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].pb(v);
        g[v].pb(u);
    }

    x.resize(n);
    for (int i = 0; i < n; i++)
        cin >> x[i];

    is.assign(n, 0);
    ready.assign(n, false);
    used.assign(n, false);

    int call = 0;

    for (int i = 0; i < n; i++)
        if (!ready[i] && x[i])
    {
        ++call;
        if (call > 1) {cout << "-1\n"; return 0;}
        dfs(i, -1);
    }

    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] + 1 << " ";
    if (ans.size()) cout << "\n";
    return 0;

}