#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;


const int N = 500000;
int n, m;
vector<int> graph[N];
int marked[N];
vector<int> child[N];
int sz[N];

void dfs(int v)
{
    marked[v] = 1;
    for (auto u : graph[v])
    {
        if (!marked[u])
        {
            child[v].push_back(u);
            dfs(u);
        }
    }
}

int color[N];
vector<int> painting[N];
int c2[N];

void dfs2(int v)
{
    c2[v] = 1;
    for (auto u : painting[v]) if (c2[u] == 0) dfs2(u);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(1);
    for (int i = 1; i <= n; i++) if (marked[i] == 0) cout << 0, exit(0);

    int mindeg = graph[1].size(), id = 1;
    for (int i = 2; i <= n; i++)
    {
        if (graph[i].size() < mindeg)
        {
            id = i, mindeg = graph[i].size();
        }
    }
    vector<int> keks = graph[id];
    int cnt = 1;
    fill(color, color + N, 1);
    for (auto v : keks) color[v] = 0;
    for (auto v : keks)
    {
        vector<int> mek(n + 1, 1);
        for (auto u : graph[v]) mek[u] = 0;
        for (int i = 1; i <= n; i++)
        {
            if (mek[i] == 0) continue;
            if (color[i] != 0)
            {
                if (color[v] == 0) color[v] = color[i];
                else
                {
                    painting[color[v]].push_back(color[i]);
                    painting[color[i]].push_back(color[v]);
                }
            }
        }
        if (color[v] == 0)
        {
            cnt++;
            color[v] = cnt;
        }
    }
    int r = 0;
    for (int i = 1; i <= cnt; i++)
    {
        if (c2[i] == 0)
        {
            dfs2(i);
            r++;
        }
    }
    cout << r - 1;
}