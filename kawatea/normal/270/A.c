#include <stdio.h>

int main()
{
    int t, i, j;
    
    scanf("%d", &t);
    
    for (i = 0; i < t; i++) {
        int x;
        
        scanf("%d", &x);
        
        for (j = 1; j <= 1000; j++) {
            if (180 * j == x * (j + 2)) break;
        }
        
        if (j <= 1000) {
            puts("YES");
        } else {
            puts("NO");
        }
    }
    
    return 0;
}