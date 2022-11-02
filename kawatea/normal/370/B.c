#include <stdio.h>

int main()
{
    int n, i, j, k;
    int a[100][100] = {0};
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        int x;
        
        scanf("%d", &x);
        
        for (j = 0; j < x; j++) {
            int y;
            
            scanf("%d", &y);
            
            a[i][y - 1] = 1;
        }
    }
    
    for (i = 0; i < n; i++) {
        int f = 0;
        
        for (j = 0; j < n; j++) {
            if (i == j) continue;
            
            for (k = 0; k < 100; k++) {
                if (a[i][k] == 0 && a[j][k] == 1) break;
            }
            
            if (k == 100) f = 1;
        }
        
        if (f == 0) {
            puts("YES");
        } else {
            puts("NO");
        }
    }
    
    return 0;
}