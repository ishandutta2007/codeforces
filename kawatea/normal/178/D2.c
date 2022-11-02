#include <stdio.h>
#include <stdlib.h>

int n, sum;
int a[16];
int b[4][4];

int cmp(const void *a, const void *b)
{
    return *((int *)a) - *((int *)b);
}

int dfs(int x, int y, int z)
{
    int p, q, i, j;
    
    if (x == n && y == 0) return 1;
    
    p = x;
    q = y + 1;
    
    if (q == n) {
        p = x + 1;
        q = 0;
    }
    
    for (i = 0; i < n * n; i++) {
        if ((z >> i) & 1) continue;
        
        if (x == n - 1) {
            int s = 0;
            
            for (j = 0; j < n - 1; j++) s += b[j][y];
            
            if (s + a[i] != sum) continue;
        }
        
        if (y == n - 1) {
            int s = 0;
            
            for (j = 0; j < n - 1; j++) s += b[x][j];
            
            if (s + a[i] != sum) continue;
        }
        
        if (x == n - 1 && y == 0) {
            int s = 0;
            
            for (j = 0; j < n - 1; j++) s += b[j][n - j - 1];
            
            if (s + a[i] != sum) continue;
        }
        
        if (x == n - 1 && y == n - 1) {
            int s = 0;
            
            for (j = 0; j < n - 1; j++) s += b[j][j];
            
            if (s + a[i] != sum) continue;
        }
        
        b[x][y] = a[i];
        
        if (dfs(p, q, z | (1 << i)) == 1) return 1;
        
        for (j = i + 1; j < n * n; j++) {
            if (a[i] != a[j]) break;
        }
        
        i = j - 1;
    }
    
    return -1;
}

int main()
{
    int i, j;
    
    scanf("%d", &n);
    
    for (i = 0; i < n * n; i++) {
        scanf("%d", &a[i]);
        
        sum += a[i];
    }
    
    sum /= n;
    
    printf("%d\n", sum);
    
    qsort(a, n * n, sizeof(int), cmp);
    
    dfs(0, 0, 0);
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (j > 0) putchar(' ');
            
            printf("%d", b[i][j]);
        }
        
        puts("");
    }
    
    return 0;
}