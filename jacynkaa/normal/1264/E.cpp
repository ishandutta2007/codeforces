#include <bits/stdc++.h>
#include <math.h>
#include <chrono>
using namespace std;
#pragma GCC optimize("-O3")
#define endl "\n"
#define mp make_pair
#define st first
#define nd second
#define pii pair<int, int>
#define pb push_back
#define _upgrade ios_base::sync_with_stdio(0), cout.setf(ios::fixed), cout.precision(10) //cin.tie(0); cout.tie(0);
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define FWD(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define fwd(i, a, b) for (int i = (a); i < (b); ++i)
#define all(c) (c).begin(), (c).end()
#define what(x) cerr << #x << " is " << x << endl;

const int MAXN = 52;

int val[MAXN];
int ans[MAXN][MAXN];
int E[MAXN][MAXN]; //-1 1 0
bitset<MAXN> visited;
vector<int> V;
int n, m;

bool comp(int a, int b)
{
    if (val[a] != val[b])
        return val[a] > val[b];
    return a < b;
}

void compute()
{
    rep(i, n)
        val[i] = 0;
    rep(i, n) rep(j, n) if (E[i][j] == 1 || ans[i][j] == 1) val[i]++;
}

void pre()
{
    cin >> n >> m;
    rep(i, n)
        V.push_back(i);

    rep(i, n) rep(j, n)
    {
        if (i > j)
            continue;

        if (i == j)
            E[i][j] = -1;
        if (rand() % 2)
        {
            E[i][j] = 1;
            E[j][i] = 0;
        }
        else
        {
            E[j][i] = 1;
            E[i][j] = 0;
        }
    }

    rep(i, m)
    {
        int a, b;
        cin >> a >> b;
        ans[--a][--b] = 1;
        E[a][b] = E[b][a] = -1;
    }
}

bool dfs(int x, int g, bool krawedzi = 0)
{
    // cerr << x << " " << g << endl;
    visited[x] = true;
    if (val[x] < g - 1)
    {
        val[x]++;
        visited[x] = false;
        return true;
    }

    rep(y, n) if (E[x][y] == 1 && !visited[y]) if (dfs(y, g))
    {
        swap(E[x][y], E[y][x]);
        visited[x] = false;
        return true;
    }

    return false;
}

bool polepsz()
{

    //compute();
    sort(all(V), comp);
    visited.reset();
    /*
    cerr << "dzialam" << endl;
    rep(i, n) cerr << val[i] << " ";
    cerr << endl;
*/
    bool znalazlem = false;
    for (int a : V)
    {
        if (!visited[a] && dfs(a, val[a], 1))
        {
            znalazlem = true;
            val[a]--;
        }
    }
    return znalazlem;
}

main()
{
    _upgrade;
    pre();
    compute();
    while (polepsz())
    {
    }
    rep(i, n)
    {
        rep(j, n) cout << max(E[i][j], ans[i][j]);
        cout << endl;
    }
}