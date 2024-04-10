#include <stdio.h>

int main()
{
    int n, m, x = 0, i;
    long long sum = 0;
    
    scanf("%d %d", &n, &m);
    
    for (i = 0; i < m; i++) {
        int y;
        
        scanf("%d", &y);
        
        y--;
        
        if (x == y) continue;
        
        if (y > x) {
            sum += y - x;
        } else {
            sum += n - x + y;
        }
        
        x = y;
    }
    
    printf("%I64d\n", sum);
    
    return 0;
}