#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int n = 4;
vector <int> v[1000005];
int parent[20][1000005];
int depth[1000005];

void dfs(int x, int y, int z)
{
    parent[0][x] = y;
    depth[x] = z;
    
    for (int i = 0; i < v[x].size(); i++) {
        if (v[x][i] != y) dfs(v[x][i], x, z + 1);
    }
}

void init(void)
{
    dfs(0, -1, 0);
    
    for (int i = 0; i + 1 < 20; i++) {
        for (int j = 0; j < n; j++) {
            if (parent[i][j] == -1) {
                parent[i + 1][j] = -1;
            } else {
                parent[i + 1][j] = parent[i][parent[i][j]];
            }
        }
    }
}

int lca(int x, int y)
{
    if (depth[x] > depth[y]) swap(x, y);
    
    for (int i = 0; i < 20; i++) {
        if (((depth[y] - depth[x]) >> i) & 1) y = parent[i][y];
    }
    
    if (x == y) return x;
    
    for (int i = 20 - 1; i >= 0; i--) {
        if (parent[i][x] != parent[i][y]) {
            x = parent[i][x];
            y = parent[i][y];
        }
    }
    
    return parent[0][x];
}

int dist(int x, int y)
{
    return depth[x] + depth[y] - depth[lca(x, y)] * 2;
}

int main()
{
    int q, x = 1, y = 2, z = 2, i;
    
    scanf("%d", &q);
    
    v[0].push_back(1);
    v[0].push_back(2);
    v[0].push_back(3);
    
    for (i = 0; i < q; i++) {
        int x;
        
        scanf("%d", &x);
        
        v[x - 1].push_back(n++);
        v[x - 1].push_back(n++);
    }
    
    init();
    
    for (i = 0; i < q; i++) {
        int d1 = dist(x, i * 2 + 4);
        int d2 = dist(y, i * 2 + 4);
        
        if (d1 > d2) {
            swap(x, y);
            swap(d1, d2);
        }
        
        if (d2 > z) {
            x = i * 2 + 4;
            z = d2;
        }
        
        printf("%d\n", z);
    }
    
    return 0;
}