#include <stdio.h>

int par[100];
int g[100][100];
int f[100];

int find(int x)
{
    if (par[x] == x) return x;
    
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
    int i;
    
    f[x] = y;
    
    for (i = 0; i < 100; i++) {
        if (g[x][i] == 1) {
            if (f[i] == y) return 0;
            
            if (f[i] == 0 && dfs(i, -y) == 0) return -1;
        }
    }
    
    return 1;
}

int main()
{
    int n, m, c = 0, p = 0, i;
    int a[10000][3];
    
    scanf("%d %d", &n, &m);
    
    for (i = 0; i < n; i++) par[i] = i;
    
    for (i = 0; i < m; i++) {
        int x, y, z;
        
        scanf("%d %d %d", &x, &y, &z);
        
        x--;
        y--;
        
        a[i][0] = x;
        a[i][1] = y;
        a[i][2] = z;
        
        if (z == 1) unite(x, y);
    }
    
    for (i = 0; i < m; i++) {
        if (a[i][2] == 0) {
            int x = find(a[i][0]);
            int y = find(a[i][1]);
            
            if (x == y) {
                puts("Impossible");
                
                return 0;
            }
            
            g[x][y] = g[y][x] = 1;
        }
    }
    
    for (i = 0; i < n; i++) {
        if (f[i] == 0) {
            if (dfs(i, 1) == 0) {
                puts("Impossible");
                
                return 0;
            }
        }
    }
    
    for (i = 0; i < n; i++) {
        if (f[find(i)] == 1) c++;
    }
    
    printf("%d\n", c);
    
    for (i = 0; i < n; i++) {
        if (f[find(i)] == 1) {
            if (p > 0) putchar(' ');
            
            printf("%d", i + 1);
            
            p++;
        }
    }
    
    puts("");
    
    return 0;
}