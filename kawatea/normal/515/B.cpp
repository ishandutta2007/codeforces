#include <cstdio>

using namespace std;

int a[200];
int par[200];

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
    int n, m, b, g, i, j;
    
    scanf("%d %d", &n, &m);
    
    scanf("%d", &b);
    
    for (i = 0; i < b; i++) {
        int x;
        
        scanf("%d", &x);
        
        a[x] = 1;
    }
    
    scanf("%d", &g);
    
    for (i = 0; i < g; i++) {
        int x;
        
        scanf("%d", &x);
        
        a[n + x] = 1;
    }
    
    for (i = 0; i < n + m; i++) par[i] = i;
    
    for (i = 0; i < n * m; i++) unite(i % n, n + i % m);
    
    for (i = 0; i < n + m; i++) {
        for (j = 0; j < n + m; j++) {
            if (find(i) == find(j) && a[j] == 1) break;
        }
        
        if (j == n + m) {
            puts("No");
            
            return 0;
        }
    }
    
    puts("Yes");
    
    return 0;
}