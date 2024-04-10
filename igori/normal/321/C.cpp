#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cmath>

#define int long long
//#define double long double

using namespace std;

long long n;
vector<int> graph[500000];
long long centroid[500000];
long long sz[500000];
long long whole_sz[500000];

void dfs(int v)
{
    sz[v] = 1;
    for (int i = 0; i < graph[v].size(); i++)
    {
        int u = graph[v][i];
        if (sz[u] == 0 && centroid[u] == 0)
        {
            dfs(u);
            sz[v] += sz[u];
        }
    }
}

void mark(int v, int val)
{
    whole_sz[v] = val;
    for (int i = 0; i < graph[v].size(); i++)
    {
        int u = graph[v][i];
        if (whole_sz[u] == 0 && centroid[u] == 0)
        {
            mark(u, val);
        }
    }
}

signed main()
{
    cin >> n;
    for (int i = 0; i + 1 < n; i++)
    {
        int v, u;
        cin >> v >> u;
        v--, u--;
        graph[v].push_back(u);
        graph[u].push_back(v);
    }
    for (int j = 1; j <= 20; j++)
    {
        fill(sz, sz + n, 0);
        fill(whole_sz, whole_sz + n, 0);
        for (int i = 0; i < n; i++)
        {
            if (centroid[i] == 0 && sz[i] == 0)
            {
                dfs(i);
                mark(i, sz[i]);
            }
        }
        for (int i = 0; i < n; i++)
        {
            int t = 1;
            if (centroid[i] != 0) continue;
            long long sz_up = whole_sz[i] - 1;
            for (auto g : graph[i])
            {
                if (centroid[g] == j) t = 0;
                if (sz[g] < sz[i])
                {
                    sz_up = sz_up - sz[g];
                    if (sz[g] * 2 > whole_sz[i]) t = 0;
                }
            }
            if (sz_up * 2 > whole_sz[i]) t = 0;
            //cout << i << " step " << j << " " << sz_up << " " << whole_sz[i] << endl;
            if (t)
            {
                centroid[i] = j;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << (char)(centroid[i] - 1 + 'A') << " ";
    }
}