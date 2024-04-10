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
vector <edge> g[6402];
int h[6402];
int dist[6402];
int prevv[6402];
int preve[6402];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void add_edge(int from, int to, int cap, int cost)
{
    g[from].push_back((edge){to, cap, cost, g[to].size()});
    g[to].push_back((edge){from, 0, -cost, g[from].size() - 1});
}

int min_cost_flow(int s, int t, int f)
{
    int res = 0, i;
    
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
        
        if (dist[t] == 1e9) return -1;
        
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
    int n, m, i, j;
    int a[80][80];
    int b[3200] = {0};
    int c[80][80] = {0};
    
    scanf("%d %d", &n, &m);
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &a[i][j]);
            
            if ((i + j) % 2 == 0) {
                b[a[i][j] - 1]++;
                
                c[i][j] = b[a[i][j] - 1];
            }
        }
    }
    
    V = n * m + 2;
    
    for (i = 0; i < n * m; i++) {
        int x = i / m;
        int y = i % m;
        
        if ((x + y) % 2 == 1) continue;
        
        for (j = 0; j < 4; j++) {
            int nx = x + dx[j];
            int ny = y + dy[j];
            
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            
            if (a[x][y] == a[nx][ny] || c[x][y] == 2) {
                add_edge(i, nx * m + ny, 1, 0);
            } else {
                add_edge(i, nx * m + ny, 1, 1);
            }
        }
    }
    
    for (i = 0; i < n * m; i++) {
        int x = i / m;
        int y = i % m;
        
        if ((x + y) % 2 == 0) {
            if (c[x][y] == 2) {
                add_edge(V - 2, i, 1, 1);
            } else {
                add_edge(V - 2, i, 1, 0);
            }
        } else {
            add_edge(i, V - 1, 1, 0);
        }
    }
    
    printf("%d\n", min_cost_flow(V - 2, V - 1, n * m / 2));
    
    return 0;
}