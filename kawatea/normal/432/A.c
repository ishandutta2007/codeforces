#include <stdio.h>

int main()
{
    int n, k, sum = 0, i;
    
    scanf("%d %d", &n, &k);
    
    for (i = 0; i < n; i++) {
        int x;
        
        scanf("%d", &x);
        
        if (5 - x >= k) sum++;
    }
    
    printf("%d\n", sum / 3);
    
    return 0;
}