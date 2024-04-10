#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <algorithm>
 
using namespace std;
 
template <class Type>
class LCA {
    public:
    
    LCA(int n) : size(n), high(32 - __builtin_clz(n)), graph(n) {
        parent = (int *)malloc(sizeof(int) * size * high);
        depth = (int *)malloc(sizeof(int) * size);
        distance = (Type *)malloc(sizeof(Type) * size);
        q.resize(size, vector <priority_queue<int> >(20));
    }
    
    ~LCA() {
        free(parent);
        free(depth);
        free(distance);
    }
    
    void add_undirected_edge(int from, int to, Type cost = 1) {
        graph[from].push_back(Edge(to, cost));
        graph[to].push_back(Edge(from, cost));
    }
    
    void init(int root = 0) {
        dfs(root, -1, 0, 0);
        
        for (int i = 0; i + 1 < high; i++) {
            for (int j = 0; j < size; j++) {
                if (parent[j * high + i] == -1) {
                    parent[j * high + i + 1] = -1;
                } else {
                    parent[j * high + i + 1] = parent[parent[j * high + i] * high + i];
                }
            }
        }
    }
    
    void add(int x, int y) {
        q[x][0].push(y);
        if (q[x][0].size() > 10) q[x][0].pop();
    }
    
    void calc(void) {
        for (int i = 0; i + 1 < high; i++) {
            for (int j = 0; j < size; j++) {
                if (parent[j * high + i] == -1) {
                } else {
                    priority_queue <int> tmp = q[parent[j * high + i]][i];
                    q[j][i + 1] = q[j][i];
                    
                    while (!tmp.empty()) {
                        q[j][i + 1].push(tmp.top());
                        tmp.pop();
                        if (q[j][i + 1].size() > 10) q[j][i + 1].pop();
                    }
                }
            }
        }
    }
    
    int lca(int x, int y) {
        if (depth[x] > depth[y]) swap(x, y);
        
        y = up(y, depth[y] - depth[x]);
        
        if (x == y) return x;
        
        for (int i = 31 - __builtin_clz(depth[x]); i >= 0; i--) {
            if (parent[x * high + i] != parent[y * high + i]) {
                x = parent[x * high + i];
                y = parent[y * high + i];
            }
        }
        
        return parent[x * high];
    }
    
    Type dist(int x, int y) {
        return distance[x] + distance[y] - distance[lca(x, y)] * 2;
    }
    
    int up(int x, int y) {
        while (y > 0) {
            int right = __builtin_ctz(y);
            
            x = parent[x * high + right];
            y ^= 1 << right;
        }
        
        return x;
    }
    
    priority_queue<int> get(int x, int y) {
        priority_queue <int> ans;
        
        while (y > 0) {
            int right = __builtin_ctz(y);
            
            if (ans.size() == 0) {
                ans = q[x][right];
            } else {
                priority_queue <int> tmp = q[x][right];
                
                while (!tmp.empty()) {
                    ans.push(tmp.top());
                    tmp.pop();
                    if (ans.size() > 10) ans.pop();
                }
            }
            
            x = parent[x * high + right];
            y ^= 1 << right;
        }
        
        return ans;
    }
    
    priority_queue<int> get2(int x) {
        return q[x][0];
    }
    
    private:
    
    int size;
    int high;
    int *parent;
    int *depth;
    Type *distance;
    vector <vector <priority_queue<int> > > q;
    
    struct Edge {
        int to;
        Type cost;
        Edge(int to, Type cost) : to(to), cost(cost) {}
    };
    
    vector <vector <Edge> > graph;
    
    void dfs(int now, int par, int dep, Type dist) {
        parent[now * high] = par;
        depth[now] = dep;
        distance[now] = dist;
        
        for (int i = 0; i < graph[now].size(); i++) {
            if (graph[now][i].to != par) dfs(graph[now][i].to, now, dep + 1, dist + graph[now][i].cost);
        }
    }
};

int a[10];
 
int main()
{
    int n, m, q, i, j;
    
    scanf("%d %d %d", &n, &m, &q);
    
    LCA <int> lca(n);
    
    for (i = 0; i < n - 1; i++) {
        int x, y;
        
        scanf("%d %d", &x, &y);
        
        lca.add_undirected_edge(x - 1, y - 1);
    }
    
    lca.init();
    
    for (i = 0; i < m; i++) {
        int x;
        
        scanf("%d", &x);
        
        lca.add(x - 1, i + 1);
    }
    
    lca.calc();
    
    for (i = 0; i < q; i++) {
        int x, y, z, w, d1, d2;
        priority_queue <int> ans, tmp, tmp2;
        
        scanf("%d %d %d", &x, &y, &z);
        
        x--;
        y--;
        
        w = lca.lca(x, y);
        
        d1 = lca.dist(x, w);
        d2 = lca.dist(y, w);
        
        ans = lca.get(x, d1);
        tmp = lca.get(y, d2);
        tmp2 = lca.get2(w);
        
        while (ans.size() > z) ans.pop();
        while (!tmp.empty()) {
            ans.push(tmp.top());
            tmp.pop();
            if (ans.size() > z) ans.pop();
        }
        while (!tmp2.empty()) {
            ans.push(tmp2.top());
            tmp2.pop();
            if (ans.size() > z) ans.pop();
        }
        
        printf("%d", (int)ans.size());
        
        for (j = 0; !ans.empty(); j++) {
            a[j] = ans.top();
            ans.pop();
        }
        
        for (j--; j >= 0; j--) printf(" %d", a[j]);
        
        puts("");
    }
    
    return 0;
}