#include <stdio.h>

int main()
{
    int n, sum = 0, i;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        int x, y, z;
        
        scanf("%d %d %d", &x, &y, &z);
        
        if (x + y + z >= 2) sum++;
    }
    
    printf("%d\n", sum);
    
    return 0;
}