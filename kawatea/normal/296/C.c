#include <stdio.h>

int a[100000];
int b[100000][3];
long long c[100001];
long long d[100001];

int main()
{
    int n, m, k, i;
    
    scanf("%d %d %d", &n, &m, &k);
    
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    
    for (i = 0; i < m; i++) scanf("%d %d %d", &b[i][0], &b[i][1], &b[i][2]);
    
    for (i = 0; i < k; i++) {
        int x, y;
        
        scanf("%d %d", &x, &y);
        
        c[x - 1]++;
        c[y]--;
    }
    
    for (i = 1; i < m; i++) c[i] += c[i - 1];
    
    for (i = 0; i < m; i++) {
        if (c[i] == 0) continue;
        
        d[b[i][0] - 1] += b[i][2] * c[i];
        d[b[i][1]] -= b[i][2] * c[i];
    }
    
    for (i = 1; i < n; i++) d[i] += d[i - 1];
    
    for (i = 0; i < n; i++) {
        if (i > 0) putchar(' ');
        
        printf("%I64d", a[i] + d[i]);
    }
    
    return 0;
}