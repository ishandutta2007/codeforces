#include <stdio.h>

int a[10001][500];
int b[10001][500];

int find(int *par, int x)
{
    if (par[x] == x) return x;
    
    return par[x] = find(par, par[x]);
}

void unite(int *par, int x, int y)
{
    x = find(par, x);
    y = find(par, y);
    
    if (x == y) return;
    
    par[x] = y;
}

int main()
{
    int n, m, k, i, j;
    int c[10000][2];
    
    scanf("%d %d", &n, &m);
    
    for (i = 0; i < m; i++) {
        scanf("%d %d", &c[i][0], &c[i][1]);
        
        c[i][0]--;
        c[i][1]--;
    }
    
    for (i = 0; i < n; i++) a[0][i] = b[m][i] = i;
    
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) a[i + 1][j] = a[i][j];
        
        unite(a[i + 1], c[i][0], c[i][1]);
    }
    
    for (i = m - 1; i >= 0; i--) {
        for (j = 0; j < n; j++) b[i][j] = b[i + 1][j];
        
        unite(b[i], c[i][0], c[i][1]);
    }
    
    scanf("%d", &k);
    
    for (i = 0; i < k; i++) {
        int x, y, sum = 0;
        int par[500];
        int d[500] = {0};
        
        scanf("%d %d", &x, &y);
        
        for (j = 0; j < n; j++) par[j] = a[x - 1][j];
        
        for (j = 0; j < n; j++) unite(par, j, b[y][j]);
        
        for (j = 0; j < n; j++) d[find(par, j)]++;
        
        for (j = 0; j < n; j++) {
            if (d[j] > 0) sum++;
        }
        
        printf("%d\n", sum);
    }
    
    return 0;
}