#include <stdio.h>

int a[100][100];
int b[100];
int c[100];
int d[100];

int main()
{
    int n, m, k, i, j;
    
    scanf("%d %d %d", &n, &m, &k);
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    
    for (i = 0; i < m; i++) {
        for (j = 0; j < k; j++) d[j] = 0;
        
        for (j = 0; j < n; j++) {
            if (b[j] > 0) continue;
            
            if (a[j][i] == 0) continue;
            
            d[a[j][i] - 1]++;
        }
        
        for (j = 0; j < n; j++) {
            if (b[j] > 0) continue;
            
            if (a[j][i] == 0) continue;
            
            if (c[a[j][i] - 1] == 1 || d[a[j][i] - 1] > 1) {
                b[j] = i + 1;
                c[a[j][i] - 1] = 1;
            }
        }
    }
    
    for (i = 0; i < n; i++) printf("%d\n", b[i]);
    
    return 0;
}