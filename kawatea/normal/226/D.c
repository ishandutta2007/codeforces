#include <stdio.h>

int main()
{
    int n, m, i, j;
    int a[100][100];
    int b[100], c[100];
    
    scanf("%d %d", &n, &m);
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    
    for (i = 0; i < m; i++) b[i] = 1;
    for (i = 0; i < n; i++) c[i] = 1;
    
    while (1) {
        int f = 0;
        
        for (i = 0; i < n; i++) {
            int sum = 0;
            
            for (j = 0; j < m; j++) sum += a[i][j] * b[j] * c[i];
            
            if (sum < 0) {
                c[i] *= -1;
                
                f = 1;
            }
        }
        
        for (i = 0; i < m; i++) {
            int sum = 0;
            
            for (j = 0; j < n; j++) sum += a[j][i] * b[i] * c[j];
            
            if (sum < 0) {
                b[i] *= -1;
                
                f = 1;
            }
        }
        
        if (f == 0) {
            int x = 0, y = 0;
            
            for (i = 0; i < n; i++) {
                if (c[i] == 1) x++;
            }
            
            for (i = 0; i < m; i++) {
                if (b[i] == 1) y++;
            }
            
            printf("%d", x);
            
            for (i = 0; i < n; i++) {
                if (c[i] == 1) printf(" %d", i + 1);
            }
            
            puts("");
            
            printf("%d", y);
            
            for (i = 0; i < m; i++) {
                if (b[i] == 1) printf(" %d", i + 1);
            }
            
            puts("");
            
            break;
        }
    }
    
    return 0;
}