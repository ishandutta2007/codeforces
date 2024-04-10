#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll INF = 1e18;

void AddEdge(int f, int t, int w, vector<vector<pair<int, int> > > &g)
{
    g[f].push_back({t, w});
    //g[t].push_back({f, w});
}

void AddSetEdges(int f, int t, int w, vector<vector<pair<int, int> > > &g)
{
    AddEdge(4 * f, 4 * t, w, g);
    AddEdge(4 * f, 4 * t + 1, 0, g);
    AddEdge(4 * f, 4 * t + 2, 2 * w, g);
    AddEdge(4 * f, 4 * t + 3, w, g);
    AddEdge(4 * f + 1, 4 * t + 1, w, g);
    AddEdge(4 * f + 1, 4 * t + 3, 2 * w, g);
    AddEdge(4 * f + 2, 4 * t + 2, w, g);
    AddEdge(4 * f + 2, 4 * t + 3, 0, g);
    AddEdge(4 * f + 3, 4 * t + 3, w, g);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    srand(time(NULL));

    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int> > > g(4 * n);
    for (int i = 0; i < m; i++)
    {
        int f, t, w;
        cin >> f >> t >> w;
        f--, t--;
        AddSetEdges(f, t, w, g);
        AddSetEdges(t, f, w, g);
    }
    vector<ll> dist(4 * n, INF);
    dist[0] = 0;
    set<pair<ll, int> > S;
    S.insert({0, 0});
    while (S.size())
    {
        pair<ll, int> st = *S.begin();
        S.erase(S.begin());
        for (auto e : g[st.second])
        {
            if (dist[e.first] > dist[st.second] + e.second)
            {
                S.erase({dist[e.first], e.first});
                dist[e.first] = dist[st.second] + e.second;
                S.insert({dist[e.first], e.first});
            }
        }
    }
    for (int i = 1; i < n; i++)
    {
        cout << dist[4 * i + 3] << " ";
    }
}