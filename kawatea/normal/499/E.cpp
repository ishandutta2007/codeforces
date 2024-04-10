#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct edge {
    int to;
    int cap;
    int rev;
};

int V;
vector <edge> g[10000];
int level[10000];
int iter[10000];
int a[100];
int b[100][100];
vector <pair<int, int> > v[100];

void add_edge(int from, int to, int cap)
{
    g[from].push_back((edge){to, cap, g[to].size()});
    g[to].push_back((edge){from, 0, g[from].size() - 1});
}

void bfs(int s)
{
    queue <int> q;
    
    for (int i = 0; i < V; i++) level[i] = -1;
    
    level[s] = 0;
    q.push(s);
    
    while (!q.empty()) {
        int x = q.front();
        
        q.pop();
        
        for (int i = 0; i < g[x].size(); i++) {
            edge &e = g[x][i];
            
            if (e.cap > 0 && level[e.to] < 0) {
                level[e.to] = level[x] + 1;
                q.push(e.to);
            }
        }
    }
}

int dfs(int v, int t, int f)
{
    if (v == t) return f;
    
    for (int &i = iter[v]; i < g[v].size(); i++) {
        edge &e = g[v][i];
        
        if (e.cap > 0 && level[v] < level[e.to]) {
            int d = dfs(e.to, t, min(f, e.cap));
            
            if (d > 0) {
                e.cap -= d;
                g[e.to][e.rev].cap += d;
                
                return d;
            }
        }
    }
    
    return 0;
}

int max_flow(int s, int t)
{
    int res = 0, f;
    
    while (1) {
        bfs(s);
        
        if (level[t] < 0) return res;
        
        for (int i = 0; i < V; i++) iter[i] = 0;
        
        while ((f = dfs(s, t, 1e9)) > 0) res += f;
    }
}

int main()
{
    int n, m, c1 = 0, c2 = 0, p, q, r1, r2, i, j, k, l;
    
    scanf("%d %d", &n, &m);
    
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    
    for (i = 0; i < m; i++) {
        int x, y;
        
        scanf("%d %d", &x, &y);
        
        x--;
        y--;
        
        b[x][y] = b[y][x] = 1;
    }
    
    for (i = 0; i < n; i++) {
        for (j = 2; j * j <= a[i]; j++) {
            if (a[i] % j == 0) {
                int c = 0;
                
                while (a[i] % j == 0) {
                    a[i] /= j;
                    c++;
                }
                
                v[i].push_back(make_pair(j, c));
            }
        }
        
        if (a[i] > 1) v[i].push_back(make_pair(a[i], 1));
        
        if (i % 2 == 0) {
            c1 += v[i].size();
        } else {
            c2 += v[i].size();
        }
    }
    
    V = c1 + c2 + 2;
    
    for (i = 0, p = 0, q = c1; i < n; i++) {
        if (i % 2 == 0) {
            for (j = 0; j < v[i].size(); j++) {
                add_edge(V - 2, p++, v[i][j].second);
            }
        } else {
            for (j = 0; j < v[i].size(); j++) {
                add_edge(q++, V - 1, v[i][j].second);
            }
        }
    }
    
    r1 = 0;
    
    for (i = 0; i < n; i += 2) {
        r2 = 0;
        
        for (j = 1; j < n; j += 2) {
            if (b[i][j] == 1) {
                for (k = 0, l = 0; k < v[i].size() && l < v[j].size(); ) {
                    if (v[i][k].first == v[j][l].first) {
                        add_edge(r1 + k, c1 + r2 + l, min(v[i][k].second, v[j][l].second));
                        
                        k++;
                        l++;
                    } else if (v[i][k].first < v[j][l].first) {
                        k++;
                    } else {
                        l++;
                    }
                }
            }
            
            r2 += v[j].size();
        }
        
        r1 += v[i].size();
    }
    
    printf("%d\n", max_flow(V - 2, V - 1));
    
    return 0;
}