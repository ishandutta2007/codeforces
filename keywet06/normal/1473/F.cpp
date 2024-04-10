#include<bits/stdc++.h>

using namespace std;

template<typename T>
struct dinic {
    struct edge {
        int u, rev;
        T cap, flow;
    };
    
    int n, s, t;
    T flow;
    vector<int> lst;
    vector<int> d;
    vector<vector<edge>> g;
    
    T scaling_lim;
    bool scaling;
    
    dinic() {}
    
    dinic(int n, int s, int t, bool scaling = false) : n(n), s(s), t(t), scaling(scaling) {
        g.resize(n);
        d.resize(n);
        lst.resize(n);
        flow = 0;
    }

    void add_edge(int v, int u, T cap, bool directed = true) {
        g[v].push_back({u, g[u].size(), cap, 0});
        g[u].push_back({v, int(g[v].size()) - 1, directed ? 0 : cap, 0});
    }

    T dfs(int v, T flow) {
        if (v == t)
            return flow;
        if (flow == 0)
            return 0;
        T result = 0;
        for (; lst[v] < g[v].size(); ++lst[v]) {
            edge& e = g[v][lst[v]];
            if (d[e.u] != d[v] + 1)
                continue;
            T add = dfs(e.u, min(flow, e.cap - e.flow));
            if (add > 0) {
                result += add;
                flow -= add;
                e.flow += add;
                g[e.u][e.rev].flow -= add;
            }
            if (flow == 0)
                break;
        }
        return result;
    }

    bool bfs() {
        fill(d.begin(), d.end(), -1);
        queue<int> q({s});
        d[s] = 0;
        while (!q.empty() && d[t] == -1) {
            int v = q.front(); q.pop();
            for (auto& e : g[v]) {
                if (d[e.u] == -1 && e.cap - e.flow >= scaling_lim) {
                    q.push(e.u);
                    d[e.u] = d[v] + 1;
                }
            }
        }
        return d[t] != -1;
    }

    T calc() {
        T max_lim = numeric_limits<T>::max() / 2 + 1;
        for (scaling_lim = scaling ? max_lim : 1; scaling_lim > 0; scaling_lim >>= 1) {
            while (bfs()) {
                fill(lst.begin(), lst.end(), 0);
                T add;
                while((add = dfs(s, numeric_limits<T>::max())) > 0)
                flow += add;
            }
        }   
        return flow;
    }
    
    vector<bool> min_cut() {
        vector<bool> res(n);
        for(int i = 0; i < n; i++) 
            res[i] = (d[i] != -1);
        return res;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < n; i++)
        cin >> b[i];
    int s = n;
    int t = n + 1;
    dinic<int> d(n + 2, s, t, true);
    vector<int> last(101, -1);
    for(int i = 0; i < n; i++){
        if(b[i] > 0)
            d.add_edge(s, i, b[i]);
        if(b[i] < 0)
            d.add_edge(i, t, -b[i]);
        for(int k = 1; k <= 100; k++)
            if(last[k] != -1 && a[i] % k == 0)
                d.add_edge(i, last[k], int(1e9));
        last[a[i]] = i;    
    }   
    int sum = 0;
    for(int i = 0; i < n; i++)
        sum += max(0, b[i]);
    cout << sum - d.calc() << endl;
}