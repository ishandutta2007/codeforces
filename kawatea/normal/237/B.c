#include <stdio.h>

int main()
{
    int n, m = 0, p = 1, i, j, k, l;
    int a[50][50];
    int b[50][50];
    int c[50];
    int d[2500][4];
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) scanf("%d", &c[i]);
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < c[i]; j++) {
            scanf("%d", &a[i][j]);
            
            b[i][j] = p++;
        }
    }
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < c[i]; j++) {
            int x, y;
            
            if (a[i][j] == b[i][j]) continue;
            
            for (k = 0; k < n; k++) {
                for (l = 0; l < c[k]; l++) {
                    if (a[k][l] == b[i][j]) {
                        x = k;
                        y = l;
                        
                        k = n;
                        
                        break;
                    }
                }
            }
            
            d[m][0] = i + 1;
            d[m][1] = j + 1;
            d[m][2] = x + 1;
            d[m++][3] = y + 1;
            
            a[x][y] = a[i][j];
            a[i][j] = b[i][j];
        }
    }
    
    printf("%d\n", m);
    
    for (i = 0; i < m; i++) printf("%d %d %d %d\n", d[i][0], d[i][1], d[i][2], d[i][3]);
    
    return 0;
}