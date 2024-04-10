#include <cstdio>
#include <algorithm>

using namespace std;

int a[100000];
int d[500][500];
int par[100000];

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
    int n, m, k, c = 0, i, j, l;
    
    scanf("%d %d %d", &n, &m, &k);
    
    for (i = 0; i < k; i++) {
        int x;
        
        scanf("%d", &x);
        
        while (x--) a[c++] = i;
    }
    
    for (i = 0; i < n; i++) par[i] = i;
    
    for (i = 0; i < k; i++) {
        for (j = 0; j < k; j++) {
            if (i == j) {
                d[i][j] = 0;
            } else {
                d[i][j] = 1e9;
            }
        }
    }
    
    for (i = 0; i < m; i++) {
        int x, y, z;
        
        scanf("%d %d %d", &x, &y, &z);
        
        x--;
        y--;
        
        if (z == 0) unite(x, y);
        
        d[a[x]][a[y]] = min(d[a[x]][a[y]], z);
        d[a[y]][a[x]] = min(d[a[y]][a[x]], z);
    }
    
    for (i = 0; i < k; i++) {
        for (j = 0; j < k; j++) {
            for (l = 0; l < k; l++) {
                d[j][l] = min(d[j][l], d[j][i] + d[i][l]);
            }
        }
    }
    
    c = 0;
    
    for (i = 0; i < k; i++) {
        int x = find(c);
        
        for (j = c; j < n; j++) {
            if (a[j] != i) break;
            
            if (find(j) != x) {
                puts("No");
                
                return 0;
            }
        }
        
        c = j;
    }
    
    puts("Yes");
    
    for (i = 0; i < k; i++) {
        for (j = 0; j < k; j++) {
            if (j > 0) putchar(' ');
            
            if (d[i][j] == 1e9) d[i][j] = -1;
            
            printf("%d", d[i][j]);
        }
        
        puts("");
    }
    
    return 0;
}