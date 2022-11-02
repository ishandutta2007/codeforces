#include <cstdio>
#include <cstring>
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

int v = 150;
vector <edge> g[150];
int h[150];
int dist[150];
int prevv[150], preve[150];

void add_edge(int from, int to, int cap, int cost)
{
    g[from].push_back((edge){to, cap, cost, g[to].size()});
    g[to].push_back((edge){from, 0, -cost, g[from].size() - 1});
}

int min_cost_flow(int s, int t, int f)
{
    int res = 0, i;
    
    for (i = 0; i < v; i++) h[i] = 0;
    
    while (f > 0) {
        int d = f;
        priority_queue <pair<int, int> > q;
        
        for (i = 0; i < v; i++) dist[i] = 1e9;
        
        dist[s] = 0;
        
        q.push(make_pair(0, s));
        
        while (!q.empty()) {
            int x = -q.top().first;
            int y = q.top().second;
            
            q.pop();
            
            if (dist[y] < x) continue;
            
            for (i = 0; i < g[y].size(); i++) {
                edge &e = g[y][i];
                
                if (e.cap > 0 && dist[e.to] > dist[y] + e.cost + h[y] - h[e.to]) {
                    dist[e.to] = dist[y] + e.cost + h[y] - h[e.to];
                    prevv[e.to] = y;
                    preve[e.to] = i;
                    
                    q.push(make_pair(-dist[e.to], e.to));
                }
            }
        }
        
        if (dist[t] == 1e9) return -1;
        
        for (i = 0; i < v; i++) h[i] += dist[i];
        
        for (i = t; i != s; i = prevv[i]) {
            d = min(d, g[prevv[i]][preve[i]].cap);
        }
        
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
    int a[26] = {0};
    int b[100][26] = {0};
    int c[100];
    char s[101];
    
    scanf("%s", s);
    
    m = strlen(s);
    
    for (i = 0; i < m; i++) a[s[i] - 'a']++;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        int m1;
        
        scanf("%s %d", s, &c[i]);
        
        m1 = strlen(s);
        
        for (j = 0; j < m1; j++) b[i][s[j] - 'a']++;
        
        add_edge(148, i, c[i], 0);
        
        for (j = 0; j < 26; j++) add_edge(i, 100 + j, b[i][j], i + 1);
    }
    
    for (i = 0; i < 26; i++) add_edge(100 + i, 149, a[i], 0);
    
    printf("%d\n", min_cost_flow(148, 149, m));
    
    return 0;
}