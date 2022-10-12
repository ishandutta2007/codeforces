#include <bits/stdc++.h>

// \/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\ \\
// "We created a community that can control itself." \\
// \/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\ \\

// TechnoRush

using namespace std;

#define all(x) (x).begin(), (x).end()

const long long MOD = 1e9 + 7;
const long long INFLL = 1e18;
const long long INF = 1e9;
const int N = 500000;

long long dist[N];

long long p[N];
int n, m, k;
vector<int> graph[N], ugraph[N];
int x, y;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int v, u;
        cin >> v >> u;
        graph[v].push_back(u);
        ugraph[u].push_back(v);
    }
    cin >> k;
    for (int i = 0; i < k; i++) cin >> p[i];
    vector<int> q = {p[k - 1]};
    fill(dist, dist + N, INF);
    dist[p[k - 1]] = 0;
    for (int i = 0; i < q.size(); i++)
    {
        int v = q[i];
        for (auto u : ugraph[v])
        {
            if (dist[u] == INF)
            {
                dist[u] = dist[v] + 1;
                q.push_back(u);
            }
        }
    }
    for (int i = 0; i + 1 < k; i++)
    {
        if (dist[p[i]] <= dist[p[i + 1]]) x++;
        if (dist[p[i]] - 1 == dist[p[i + 1]])
        {
            int cnt = 0;
            int v = p[i];
            for (auto u : graph[v]) if (dist[u] + 1 == dist[v]) cnt++;
            if (cnt == 1) y++;
        }
    }
    cout << x << " " << k - 1 - y;
}