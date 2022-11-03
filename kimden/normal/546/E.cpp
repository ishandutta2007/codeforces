#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;

vector<int> from, to, cap, flow;
vector<int> dist, ptr;
vector<vector<pii>> g;
const int INF = 1'000'000'123;
int src, snk;

void bfs() {
    queue<int> q;
    q.push(src);
    while(!q.empty()){
        int z = q.front();
        q.pop();
        for(auto pr: g[z]){
            int u = pr.first;
            int e = pr.second;
            if(flow[e] == cap[e] || dist[u] != INF){
                continue;
            }
            dist[u] = dist[z] + 1;
            q.push(u);
        }
    }
}

int dfs(int v, int maxflow = INF){
    if(v == snk){
        return maxflow;
    }
    for(int i = ptr[v]; i < g[v].size(); ++i, ++ptr[v]){
        int u = g[v][i].first;
        int e = g[v][i].second;
        if(dist[u] == dist[v] + 1 && flow[e] < cap[e]){
            int val = dfs(u, min(maxflow, cap[e] - flow[e]));
            if(val){
                flow[e] += val;
                flow[e ^ 1] -= val;
                return val;
            }
        }
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(n);
    ll suma = 0, sumb = 0;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        suma += a[i];
    }
    for(int i = 0; i < n; ++i){
        cin >> b[i];
        sumb += b[i];
    }
    if(suma != sumb){
        cout << "NO" << endl;
        return 0;
    }
    for(int i = 0; i < n; ++i){
        from.push_back(0);
        to.push_back(i + 1);
        cap.push_back(a[i]);
        flow.push_back(0);
        from.push_back(i + 1);
        to.push_back(0);
        cap.push_back(a[i]);
        flow.push_back(a[i]);

        from.push_back(i + 1 + n);
        to.push_back(2 * n + 1);
        cap.push_back(b[i]);
        flow.push_back(0);
        from.push_back(2 * n + 1);
        to.push_back(i + 1 + n);
        cap.push_back(b[i]);
        flow.push_back(b[i]);
    }
    for(int i = 0; i < n; ++i){
        from.push_back(i + 1);
        to.push_back(i + 1 + n);
        cap.push_back(INF);
        flow.push_back(0);
        from.push_back(i + 1 + n);
        to.push_back(i + 1);
        cap.push_back(INF);
        flow.push_back(INF);
    }
    for(int i = 0; i < m; ++i){
        int x, y;
        cin >> x >> y;
        --x;
        --y;
        from.push_back(1 + x);
        to.push_back(n + 1 + y);
        cap.push_back(INF);
        flow.push_back(0);
        from.push_back(n + 1 + y);
        to.push_back(1 + x);
        cap.push_back(INF);
        flow.push_back(INF);

        from.push_back(1 + y);
        to.push_back(n + 1 + x);
        cap.push_back(INF);
        flow.push_back(0);
        from.push_back(n + 1 + x);
        to.push_back(1 + y);
        cap.push_back(INF);
        flow.push_back(INF);
    }
    dist.resize(n * 2 + 2);
    ptr.resize(n * 2 + 2);
    g.resize(n * 2 + 2);
    src = 0;
    snk = 2 * n + 1;
    for(int i = 0; i < from.size(); ++i){
        g[from[i]].push_back({to[i], i});
    }
    int val = 0;
    int delta;
    for(int phase = 0; phase < n * 2 + 2; ++phase){
        fill(all(dist), INF);
        dist[src] = 0;
        bfs();
        if(dist[snk] == INF){
            break;
        }
        fill(all(ptr), 0);
        delta = dfs(src);
        while(delta){
            val += delta;
            delta = dfs(src);
        }
    }
    if(val < suma){
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    vector<vector<int>> ans(n, vector<int>(n, 0));
    for(int i = 4 * n; i < from.size(); i += 2){
        ans[from[i] - 1][to[i] - n - 1] = flow[i];
    }
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            if(j){
                cout << " ";
            }
            cout << ans[i][j];
        }
        cout << endl;
    }
}