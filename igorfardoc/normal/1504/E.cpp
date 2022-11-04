#include<bits/stdc++.h>
#define INF 100000000000000000ll
using namespace std;
typedef long long ll;
vector<vector<pair<int, int> > > g;



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifdef _FILE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin >> n;
    vector<pair<int, int> > m(n);
    ll ans = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> m[i].first >> m[i].second;
        ans += m[i].second;
    }
    sort(m.begin(), m.end());
    g.resize(n);
    vector<int> maxid(n);
    for(int i = 0; i < n; i++)
    {
        if(i > 0)
        {
            g[i].push_back({i - 1, 0});
        }
        int id1 = upper_bound(m.begin(), m.end(), (pair<int, int>){m[i].first + m[i].second + 1, -1}) - m.begin() - 1;
        g[i].push_back({id1, 0});
        if(id1 != n - 1)
        {
            g[i].push_back({id1 + 1, m[id1 + 1].first - m[i].first - m[i].second});
        }
    }
    vector<ll> dist(n, INF);
    dist[0] = 0;
    set<pair<ll, int> > s;
    vector<bool> used(n, false);
    s.insert({0, 0}); 
    while(!s.empty())
    {
        auto p = *(s.begin());
        s.erase(s.begin());
        int v = p.second;
        used[v] = true;
        ll dist1 = p.first;
        for(int i = 0; i < g[v].size(); i++)
        {
            int u = g[v][i].first;
            if(used[u])
            {
                continue;
            }
            if(dist[u] > dist1 + g[v][i].second)
            {
                if(dist[u] != INF)
                {
                    s.erase(s.find({dist[u], u}));
                }
                dist[u] = dist1 + g[v][i].second;
                s.insert({dist[u], u});
            }
        }
    }
    cout << ans + dist[n - 1];
}