#include <stdio.h>

int a[18][1 << 17];

int main()
{
    int n, m, i, j;
    
    scanf("%d %d", &n, &m);
    
    for (i = 0; i < (1 << n); i++) scanf("%d", &a[0][i]);
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < (1 << (n - i)); j += 2) {
            if (i % 2 == 0) {
                a[i + 1][j / 2] = a[i][j] | a[i][j + 1];
            } else {
                a[i + 1][j / 2] = a[i][j] ^ a[i][j + 1];
            }
        }
    }
    
    for (i = 0; i < m; i++) {
        int x, y;
        
        scanf("%d %d", &x, &y);
        
        x--;
        
        a[0][x] = y;
        
        for (j = 0; j < n; j++) {
            if (j % 2 == 0) {
                if (x % 2 == 0) {
                    a[j + 1][x / 2] = a[j][x] | a[j][x + 1];
                } else {
                    a[j + 1][x / 2] = a[j][x] | a[j][x - 1];
                }
            } else {
                if (x % 2 == 0) {
                    a[j + 1][x / 2] = a[j][x] ^ a[j][x + 1];
                } else {
                    a[j + 1][x / 2] = a[j][x] ^ a[j][x - 1];
                }
            }
            
            x /= 2;
        }
        
        printf("%d\n", a[n][0]);
    }
    
    return 0;
}