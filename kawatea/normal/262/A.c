#include <stdio.h>

int main()
{
    int n, k, sum = 0, i;
    
    scanf("%d %d", &n, &k);
    
    for (i = 0; i < n; i++) {
        int x, y = 0;
        
        scanf("%d", &x);
        
        while (x) {
            if (x % 10 == 4 || x % 10 == 7) y++;
            
            x /= 10;
        }
        
        if (y <= k) sum++;
    }
    
    printf("%d\n", sum);
    
    return 0;
}