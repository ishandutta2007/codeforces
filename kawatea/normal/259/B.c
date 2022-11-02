#include <stdio.h>

int main()
{
    int i, j, k;
    int a[3][3];
    
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    
    for (i = 1; ; i++) {
        int sum = i + a[0][1] + a[0][2];
        
        a[0][0] = i;
        a[1][1] = sum - a[1][0] - a[1][2];
        a[2][2] = sum - a[2][0] - a[2][1];
        
        if (a[1][1] <= 0 || a[2][2] <= 0) continue;
        
        for (j = 0; j < 3; j++) {
            int x = 0;
            
            for (k = 0; k < 3; k++) x += a[k][j];
            
            if (x != sum) break;
        }
        
        if (j < 3) continue;
        
        if (a[0][0] + a[1][1] + a[2][2] != sum) continue;
        if (a[0][2] + a[1][1] + a[2][0] != sum) continue;
        
        for (j = 0; j < 3; j++) {
            for (k = 0; k < 3; k++) {
                if (k > 0) putchar(' ');
                
                printf("%d", a[j][k]);
            }
            
            puts("");
        }
        
        return 0;
    }
    
    return 0;
}