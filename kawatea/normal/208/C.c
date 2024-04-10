#include <stdio.h>

int a[100][100];
int d[2][100];
long long c[2][100];

int main()
{
    int n, m, i, j, k;
    double max = 1;
    
    scanf("%d %d", &n, &m);
    
    for (i = 0; i < m; i++) {
        int x, y;
        
        scanf("%d %d", &x, &y);
        
        x--;
        y--;
        
        a[x][y] = a[y][x] = 1;
    }
    
    for (i = 0; i < n; i++) d[0][i] = d[1][i] = 1e9;
    
    d[0][0] = d[1][n - 1] = 0;
    c[0][0] = c[1][n - 1] = 1;
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (d[0][j] == i) {
                for (k = 0; k < n; k++) {
                    if (a[j][k] == 1 && d[0][k] >= i + 1) {
                        d[0][k] = i + 1;
                        c[0][k] += c[0][j];
                    }
                }
            }
            
            if (d[1][j] == i) {
                for (k = 0; k < n; k++) {
                    if (a[j][k] == 1 && d[1][k] >= i + 1) {
                        d[1][k] = i + 1;
                        c[1][k] += c[1][j];
                    }
                }
            }
        }
    }
    
    for (i = 1; i < n - 1; i++) {
        double tmp;
        
        if (d[0][i] + d[1][i] > d[0][n - 1]) continue;
        
        tmp = 2.0 * c[0][i] * c[1][i] / c[0][n - 1];
        
        if (tmp > max) max = tmp;
    }
    
    printf("%.12lf\n", max);
    
    return 0;
}