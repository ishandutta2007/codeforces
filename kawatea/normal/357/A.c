#include <stdio.h>

int main()
{
    int m, x, y, sum = 0, sum2 = 0, i;
    int a[100];
    
    scanf("%d", &m);
    
    for (i = 0; i < m; i++) {
        scanf("%d", &a[i]);
        
        sum += a[i];
    }
    
    scanf("%d %d", &x, &y);
    
    for (i = 0; i < m; i++) {
        sum -= a[i];
        sum2 += a[i];
        
        if (sum >= x && sum <= y && sum2 >= x && sum2 <= y) {
            printf("%d\n", i + 2);
            
            return 0;
        }
    }
    
    puts("0");
    
    return 0;
}