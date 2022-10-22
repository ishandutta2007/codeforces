#include <bits/stdc++.h>

using namespace std;


struct bipartite_matching
{
    using graph_t = vector<vector<size_t>>;

    const graph_t& graph;
    size_t n;
    vector<bool> vis;
    vector<size_t> match;

    bipartite_matching(const graph_t& _graph)
        : graph(_graph), n(graph.size()), vis(n), match(n, SIZE_MAX) {}

    bool dfs_match(size_t u)
    {
        if(vis[u])
            return false;
        vis[u] = true;
        for(auto v : graph[u])
        {
            if(match[v] == SIZE_MAX)
            {
                match[u] = v; match[v] = u;
                return true;
            }
        }
        for(auto v : graph[u])
        {
            if(dfs_match(match[v]))
            {
                match[u] = v; match[v] = u;
                return true;
            }
        }
        return false;
    }

    vector<size_t> operator() ()
    {
        fill(match.begin(), match.end(), SIZE_MAX);

        bool any = true;
        while(any)
        {
            any = false;
            fill(vis.begin(), vis.end(), false);
            for(size_t u = 0; u < n; u++)
                if(match[u] == SIZE_MAX and dfs_match(u))
                    any = true;
        }
        return match;
    }
};

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);

    size_t n, m;
    cin >> n >> m;

    mt19937 gen;
    vector<size_t> reno[2];
    for(size_t i = 0; i < 2; i++)
        reno[i].resize(n), iota(reno[i].begin(), reno[i].end(), 0), shuffle(reno[i].begin(), reno[i].end(), gen);

    vector<tuple<size_t, size_t, int>> edges(m);
    vector<int> values(m);

    for(auto& [u, v, d] : edges)
        cin >> u >> v >> d, u = reno[0][u-1], v = reno[1][v-1], values.push_back(d);
    shuffle(edges.begin(), edges.end(), gen);

    sort(values.begin(), values.end());
    values.erase(unique(values.begin(), values.end()), values.end());

    vector<vector<size_t>> graph(2*n);

    size_t lo = 0, hi = values.size();
    while(lo < hi)
    {
        auto mid = (lo + hi) / 2;

        for(size_t w = 0; w < 2*n; w++)
            graph[w].clear();
        for(auto& [u, v, d] : edges)
            if(d <= values[mid])
                graph[u].push_back(n+v), graph[n+v].push_back(u);

        auto match = bipartite_matching{graph}();

        if(not count(match.begin(), match.end(), SIZE_MAX))
            hi = mid;
        else
            lo = mid+1;
    }

    cout << (lo == values.size() ? -1 : (int)values[lo]);
}