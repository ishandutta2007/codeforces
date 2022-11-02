#include <stdio.h>

int main()
{
    int n, k, i;
    char s[101];
    
    scanf("%d %d", &n, &k);
    scanf("%s", s);
    
    k--;
    
    if (k < (n + 1) / 2) {
        for (i = 0; i < k; i++) puts("LEFT");
        
        for (i = 0; i < n; i++) {
            printf("PRINT %c\n", s[i]);
            
            if (i < n - 1) puts("RIGHT");
        }
    } else {
        for (i = 0; i < n - k - 1; i++) puts("RIGHT");
        
        for (i = n - 1; i >= 0; i--) {
            printf("PRINT %c\n", s[i]);
            
            if (i > 0) puts("LEFT");
        }
    }
    
    return 0;
}