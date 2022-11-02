#include <stdio.h>

int main()
{
    int d, n, sum = 0, i;
    
    scanf("%d", &d);
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        int x;
        
        scanf("%d", &x);
        
        if (i < n - 1) sum += d - x;
    }
    
    printf("%d\n", sum);
    
    return 0;
}