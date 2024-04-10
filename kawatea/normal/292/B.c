#include <stdio.h>

int par[100000];
int a[100000];
int c[100000];

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

int main()
{
    int n, m, p = 0, q = 0, i;
    
    scanf("%d %d", &n, &m);
    
    for (i = 0; i < n; i++) par[i] = i;
    
    for (i = 0; i < m; i++) {
        int x, y;
        
        scanf("%d %d", &x, &y);
        
        x--;
        y--;
        
        if (find(x) != find(y)) unite(x, y);
        
        a[x]++;
        a[y]++;
    }
    
    for (i = 0; i < n; i++) c[find(i)]++;
    
    for (i = 0; i < n; i++) {
        if (c[i] != 0 && c[i] != n) {
            puts("unknown topology");
            
            return 0;
        }
    }
    
    for (i = 0; i < n; i++) {
        if (a[i] == 1) {
            p++;
        } else if (a[i] == 2) {
            q++;
        }
    }
    
    if (p == 2 && q == n - 2) {
        puts("bus topology");
    } else if (q == n) {
        puts("ring topology");
    } else if (p == n - 1) {
        puts("star topology");
    } else {
        puts("unknown topology");
    }
    
    return 0;
}