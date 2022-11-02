#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct edge {
    int to;
    int cap;
    int cost;
    int rev;
};

int V;
vector <edge> g[50];
int h[50];
int dist[50];
int prevv[50];
int preve[50];

void add_edge(int from, int to, int cap, int cost)
{
    g[from].push_back((edge){to, cap, cost, g[to].size()});
    g[to].push_back((edge){from, 0, -cost, g[from].size() - 1});
}

long long min_cost_flow(int s, int t, int f)
{
    long long res = 0, i;
    
    for (i = 0; i < V; i++) h[i] = 0;
    
    while (f > 0) {
        int d = f;
        priority_queue <pair<int, int> > q;
        
        for (i = 0; i < V; i++) dist[i] = 1e9;
        
        dist[s] = 0;
        
        q.push(make_pair(0, s));
        
        while (!q.empty()) {
            int c = -q.top().first;
            int v = q.top().second;
            
            q.pop();
            
            if (dist[v] < c) continue;
            
            for (i = 0; i < g[v].size(); i++) {
                edge &e = g[v][i];
                
                if (e.cap > 0 && dist[e.to] > dist[v] + e.cost + h[v] - h[e.to]) {
                    dist[e.to] = dist[v] + e.cost + h[v] - h[e.to];
                    prevv[e.to] = v;
                    preve[e.to] = i;
                    q.push(make_pair(-dist[e.to], e.to));
                }
            }
        }
        
        if (dist[t] == 1e9) return 1e9;
        
        for (i = 0; i < V; i++) h[i] += dist[i];
        
        for (i = t; i != s; i = prevv[i]) d = min(d, g[prevv[i]][preve[i]].cap);
        
        f -= d;
        
        res += d * h[t];
        
        for (i = t; i != s; i = prevv[i]) {
            edge &e = g[prevv[i]][preve[i]];
            e.cap -= d;
            g[i][e.rev].cap += d;
        }
    }
    
    return res;
}

int main()
{
    int n, k, l, r, m, i, j;
    int a[50][50];
    
    scanf("%d %d", &n, &k);
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    
    V = n;
    
    l = 0, r = 1e9, m = (l + r) / 2;
    
    while (r - l > 1) {
        for (i = 0; i < n; i++) g[i].clear();
        
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (a[i][j] > 0) {
                    add_edge(i, j, a[i][j], 0);
                    add_edge(i, j, k, 1);
                }
            }
        }
        
        if (min_cost_flow(0, n - 1, m) <= k) {
            l = m;
            m = (l + r) / 2;
        } else {
            r = m;
            m = (l + r) / 2;
        }
    }
    
    printf("%d\n", l);
    
    return 0;
}