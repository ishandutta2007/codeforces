#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

const int N = 2010;
const int inf = 1000000000;
const ll mod = 1000000007ll;

int n, d;
vector <vector <int> > g;
vector <int> a;

int u;
vector <int> top;
vector <bool> met;
vector <int> pred;

int add;

void dfs (int v, int p)
{
    top.pb(v);
    pred[v] = p;
    met[v] = true;
    for (int i = 0; i < g[v].size(); i++)
    {
        int to = g[v][i];
        if (met[to] == false && a[to] >= a[u] && a[to] - a[u] <= d) dfs(to, v);
    }
}

vector <ll> ans;

void solve (int v)
{
    vector <int> sons;
    for (int i = 0; i < g[v].size(); i++)
    {
        int to = g[v][i];
        if (to != pred[v] && met[to]) sons.pb(to);
    }
    if (sons.empty()) {ans[v] = 1; return;}
    ans[v] = 1;
    for (int i = 0; i < sons.size(); i++)
        if (!(a[sons[i]] == a[u] && sons[i] < u)) {ans[v] *= (ans[sons[i]] + 1); ans[v] %= mod;}
    return;
}

int main()
{

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    cin >> d >> n;
    g.resize(n);
    a.resize(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].pb(v);
        g[v].pb(u);
    }

    ll otv = 0;

    for (u = 0; u < n; u++)
    {
        pred.assign(n, -1);
        met.assign(n, false);
        dfs(u, -1);
        reverse(top.begin(), top.end());
        ans.assign(n, 0);
        for (int i = 0; i < top.size(); i++)
            solve(top[i]);
        otv = (otv + ans[u]) % mod;
        top.clear();
    }

    cout << otv << "\n";

}