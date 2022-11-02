#include <stdio.h>

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main()
{
    int n, t, i, j, k;
    int a[140][140] = {0};
    
    scanf("%d %d", &n, &t);
    
    a[70][70] = n;
    
    while (1) {
        int f = 0;
        int b[140][140] = {0};
        
        for (i = 0; i < 140; i++) {
            for (j = 0; j < 140; j++) {
                if (a[i][j] >= 4) {
                    for (k = 0; k < 4; k++) {
                         int x = i + dx[k];
                         int y = j + dy[k];
                         
                         b[x][y] += a[i][j] / 4;
                     }
                     
                     b[i][j] += a[i][j] % 4;
                     
                     f = 1;
                } else if (a[i][j] > 0) {
                    b[i][j] += a[i][j];
                }
            }
        }
        
        if (f == 0) break;
        
        for (i = 0; i < 140; i++) {
            for (j = 0; j < 140; j++) {
                a[i][j] = b[i][j];
            }
        }
    }
    
    for (i = 0; i < t; i++) {
        int x, y;
        
        scanf("%d %d", &x, &y);
        
        if (x <= -70 || x >= 70 || y <= -70 || y >= 70) {
            puts("0");
        } else {
            printf("%d\n", a[x + 70][y + 70]);
        }
    }
    
    return 0;
}