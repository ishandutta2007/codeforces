#include <stdio.h>

int par[100];

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

int main()
{
    int n, sum = 0, i, j;
    int x[100], y[100];
    int c[100] = {0};
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) scanf("%d %d", &x[i], &y[i]);
    
    for (i = 0; i < n; i++) par[i] = i;
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (x[i] == x[j] || y[i] == y[j]) unite(i, j);
        }
    }
    
    for (i = 0; i < n; i++) c[find(i)]++;
    
    for (i = 0; i < n; i++) {
        if (c[i] > 0) sum++;
    }
    
    printf("%d\n", sum - 1);
    
    return 0;
}