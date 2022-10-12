#include <iostream>
#include <vector>

using namespace std;

#define pb push_back
#define sz size()

typedef long long ll;

vector<int> graph[201000];
ll x[201000];
ll n, k, c;
ll subtree[201000];
ll visit[201000];
ll ans = 0;

void dfs(int v)
{
    visit[v] = 1;
    subtree[v] = x[v];
    //cout << v << endl << endl;
    for (int i = 0; i < graph[v].sz; i++)
    {
        int u = graph[v][i];
        //cout << u << endl;
        if (visit[u] == 0)
        {
            dfs(u);
            subtree[v] += subtree[u];
        }
    }
    ans = ans + min(2 * k - subtree[v], subtree[v]);
}

int main()
{
    cin >> n >> k;
    for (int i = 0; i < 2 * k; i++)
    {
        int y;
        cin >> y;
        x[y] = 1;
    }
    for (int i = 0; i < n - 1; i++)
    {
        ll y, z;
        cin >> y >> z;
        graph[y].pb(z);
        graph[z].pb(y);
    }
    for (int i = 1; i <= n; i++)
    {
        if (graph[i].sz == 1)
        {
            c = i;
        }
    }
    dfs(c);
    cout << ans;
}