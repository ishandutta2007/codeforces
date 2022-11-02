#include <cstdio>

using namespace std;

int par[100][100];

int find(int x, int y)
{
    if (par[x][y] == y) return y;
    
    return par[x][y] = find(x, par[x][y]);
}

void unite(int x, int y, int z)
{
    y = find(x, y);
    z = find(x, z);
    
    if (y == z) return;
    
    par[x][y] = z;
}

int main()
{
    int n, m, q, i, j;
    
    scanf("%d %d", &n, &m);
    
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            par[i][j] = j;
        }
    }
    
    for (i = 0; i < m; i++) {
        int x, y, z;
        
        scanf("%d %d %d", &x, &y, &z);
        
        unite(z - 1, x - 1, y - 1);
    }
    
    scanf("%d", &q);
    
    for (i = 0; i < q; i++) {
        int x, y, ans = 0;
        
        scanf("%d %d", &x, &y);
        
        x--;
        y--;
        
        for (j = 0; j < m; j++) {
            if (find(j, x) == find(j, y)) ans++;
        }
        
        printf("%d\n", ans);
    }
    
    return 0;
}