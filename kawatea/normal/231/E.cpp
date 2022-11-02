#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> e[100000];
vector <int> g[100000];
int c[100000];
int f[100000];
int par[100000];
int num[100000];
int parent[20][100000];
int depth[100000];
int cnt[100000];
int pow[100000];

int find(int x)
{
    if (x == par[x]) return x;
    
    return par[x] = find(par[x]);
}

void unite(int x, int y)
{
    x = find(x);
    y = find(y);
    
    if (x == y) return;
    
    par[x] = y;
}

int dfs(int x, int y)
{
    int p = 0, i;
    
    f[x] = 1;
    
    for (i = 0; i < e[x].size(); i++) {
        if (e[x][i] == y) continue;
        
        if (f[e[x][i]] == 1) {
            f[e[x][i]] = 2;
            
            p = 1;
        } else {
            p |= dfs(e[x][i], x);
        }
    }
    
    if (p == 1 && f[x] == 1) {
        unite(x, y);
        
        return 1;
    } else {
        return 0;
    }
}

int dfs2(int x, int y, int z, int w)
{
    int i;
    
    if (num[x] > 1) w++;
    
    parent[0][x] = y;
    depth[x] = z;
    cnt[x] = w;
    
    for (i = 0; i < g[x].size(); i++) {
        if (g[x][i] == y) continue;
        
        dfs2(g[x][i], x, z + 1, w);
    }
}

int lca(int x, int y)
{
    int i;
    
    if (depth[x] > depth[y]) swap(x, y);
    
    for (i = 0; i < 20; i++) {
        if ((depth[y] - depth[x]) >> i & 1) y = parent[i][y];
    }
    
    if (x == y) return x;
    
    for (i = 19; i >= 0; i--) {
        if (parent[i][x] != parent[i][y]) {
            x = parent[i][x];
            y = parent[i][y];
        }
    }
    
    return parent[0][x];
}

int main()
{
    int n, m, k, mod = 1000000007, p = 0, i, j, l;
    
    scanf("%d %d", &n, &m);
    
    for (i = 0; i < m; i++) {
        int x, y;
        
        scanf("%d %d", &x, &y);
        
        x--;
        y--;
        
        e[x].push_back(y);
        e[y].push_back(x);
        
        c[x]++;
        c[y]++;
    }
    
    for (i = 0; i < n; i++) par[i] = i;
    
    for (i = 0; i < n; i++) {
        if (c[i] == 1 || c[i] >= 3) {
            dfs(i, -1);
            
            for (j = 0; j < n; j++) num[find(j)]++;
            
            for (j = 0; j < n; j++) {
                for (l = 0; l < e[j].size(); l++) {
                    if (find(j) == find(e[j][l])) continue;
                    
                    g[find(j)].push_back(find(e[j][l]));
                }
            }
            
            dfs2(find(i), -1, 0, 0);
            
            for (j = 0; j + 1 < 20; j++) {
                for (l = 0; l < n; l++) {
                    if (parent[j][l] < 0) {
                        parent[j + 1][l] = -1;
                    } else {
                        parent[j + 1][l] = parent[j][parent[j][l]];
                    }
                }
            }
            
            p = 1;
            
            break;
        }
    }
    
    pow[0] = 1;
    
    for (i = 1; i < n; i++) pow[i] = pow[i - 1] * 2 % mod;
    
    scanf("%d", &k);
    
    for (i = 0; i < k; i++) {
        int x, y;
        
        scanf("%d %d", &x, &y);
        
        x--;
        y--;
        
        if (p == 0) {
            puts("2");
        } else {
            int z, q = 0;
            
            x = find(x);
            y = find(y);
            
            z = lca(x, y);
            
            q += cnt[x] - cnt[z];
            q += cnt[y] - cnt[z];
            
            if (num[z] > 1) q++;
            
            printf("%d\n", pow[q]);
        }
    }
    
    return 0;
}