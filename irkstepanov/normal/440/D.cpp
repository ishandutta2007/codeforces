//#include <fstream>
#include <iostream>
#include <vector>
#include <set>

#define pb push_back
#define mp make_pair

#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;

const int inf = 1000000000;
const int maxn = 405;

int dp[maxn][maxn], id[maxn][maxn];
int way[maxn][maxn][maxn];
int parent[maxn];
vector <int> g[maxn];
int n, k;

//ifstream cin("input.txt");
//ofstream cout("output.txt");

void dfs (int u, int p)
{
    dp[u][1] = 0;
    parent[u] = p;
    for (int i = 0; i < g[u].size(); i++)
    {
        int v = g[u][i];
        if (v == p) continue;
        dfs (v, u);
        for (int j = n; j >= 0; j--)
        {
            ++dp[u][j];
            for (int g = 0; g <= j; g++)
                if (dp[u][j] >= dp[u][j - g] + dp[v][g])
                {
                    dp[u][j] = dp[u][j - g] + dp[v][g];
                    way[u][v][j] = g;
                }
        }
    }
}

void write (int u, int j, int p)
{
    for (int i = (int) g[u].size() - 1; i >= 0; i--)
    {
        int v = g[u][i];
        if (v == p) continue;
        if (!way[u][v][j]) cout << id[u][v] << " ";
        else
        {
            write(v, way[u][v][j], u);
            j -= way[u][v][j];
        }
    }
}

int main()
{

    cin >> n >> k;

    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].pb(v), g[v].pb(u);
        id[u][v] = i + 1;
        id[v][u] = i + 1;
    }

    for (int i = 0; i < maxn; i++)
        for (int j = 0; j < maxn; j++)
        dp[i][j] = inf;

    dfs (0, -1);

    int ans = dp[0][k], root = 0;
    for (int i = 1; i < n; i++)
        if (ans > dp[i][k] + 1)
    {
        ans = dp[i][k] + 1;
        root = i;
    }

    cout << ans << "\n";
    if (root) cout << id[root][parent[root]] << " ";
    write (root, k, parent[root]);

}

/*if we see l and r both for the first time then call make_new_set
    if l has been senn but not r then we need to push r to l's conditions
    the same stuff here about r
    if we have seen both l and r
    {
        if they are in the same tree then we just need to check the query
        otherwise we need to unite two big trees
    }*/