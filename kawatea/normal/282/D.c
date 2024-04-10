#include <stdio.h>

char a[301][301][301];
char b[301][301];

int main()
{
    int n, x, y, z, f, i, j, k;
    
    scanf("%d", &n);
    
    if (n == 1) {
        scanf("%d", &x);
        
        if (x == 0) {
            f = 1;
        } else {
            f = 0;
        }
    } else if (n == 2) {
        scanf("%d %d", &x, &y);
        
        for (i = 0; i <= 300; i++) {
            for (j = 0; j <= 300; j++) {
                int f = 0;
                
                for (k = 0; k < i; k++) {
                    if (b[k][j] == 0) f = 1;
                }
                
                for (k = 0; k < j; k++) {
                    if (b[i][k] == 0) f = 1;
                }
                
                for (k = 1; k <= i && k <= j; k++) {
                    if (b[i - k][j - k] == 0) f = 1;
                }
                
                b[i][j] = f;
            }
        }
        
        f = 1 - b[x][y];
    } else {
        scanf("%d %d %d", &x, &y, &z);
        
        for (i = 0; i <= 300; i++) a[0][i][i] = b[i][i] = 1;
        
        for (i = 1; i <= 300; i++) {
            int c[301] = {0};
            
            for (j = 1; j + i >= j * 2; j *= 2) ;
            
            for (; j <= 300; j++) {
                if (c[j] == 1) continue;
                
                for (k = j + 1; k <= 300; k++) {
                    if (b[j][k] == 0 && c[k] == 0) {
                        a[i][j][k] = b[j][k] = c[k] = 1;
                        
                        break;
                    }
                }
            }
        }
        
        if (x > y) {
            int tmp = x;
            x = y;
            y = tmp;
        }
        
        if (y > z) {
            int tmp = y;
            y = z;
            z = tmp;
        }
        
        if (x > y) {
            int tmp = x;
            x = y;
            y = tmp;
        }
        
        f = a[x][y][z];
    }
    
    if (f == 0) {
        puts("BitLGM");
    } else {
        puts("BitAryo");
    }
    
    return 0;
}