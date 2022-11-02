#include <stdio.h>

int main()
{
    int na, ma, nb, mb, ans = 0, p = 0, q = 0, x, y, i, j;
    int a[50][50], b[50][50];
    
    scanf("%d %d", &na, &ma);
    
    for (i = 0; i < na; i++) {
        for (j = 0; j < ma; j++) {
            scanf("%1d", &a[i][j]);
        }
    }
    
    scanf("%d %d", &nb, &mb);
    
    for (i = 0; i < nb; i++) {
        for (j = 0; j < mb; j++) {
            scanf("%1d", &b[i][j]);
        }
    }
    
    for (x = -na; x <= nb; x++) {
        for (y = -ma; y <= mb; y++) {
            int sum = 0;
            
            for (i = 0; i < na; i++) {
                for (j = 0; j < ma; j++) {
                    if (i + x < 0 || i + x >= nb || j + y < 0 || j + y >= mb) continue;
                    
                    sum += a[i][j] * b[i + x][j + y];
                }
            }
            
            if (sum > ans) {
                ans = sum;
                
                p = x;
                q = y;
            }
        }
    }
    
    printf("%d %d\n", p, q);
    
    return 0;
}