#include <stdio.h>

int a[20000][10];
int b[20000];
int c[10];

int main()
{
    int n, m, k, i, j;
    
    scanf("%d %d %d", &n, &m, &k);
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    
    for (i = 0; i < k; i++) {
        int x, y;
        
        scanf("%d %d", &x, &y);
        
        b[x - 1]++;
        c[y - 1]++;
    }
    
    for (i = 0; i < n; i++) {
        int sum = 0;
        
        for (j = 0; j < m; j++) {
            if (a[i][j] == 1) sum += c[j];
        }
        
        sum -= b[i];
        
        if (i > 0) putchar(' ');
        
        printf("%d", sum);
    }
    
    puts("");
    
    return 0;
}