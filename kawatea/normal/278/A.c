#include <stdio.h>

int main()
{
    int n, x, y, sum = 0, sum2 = 0, i;
    int a[100];
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        
        sum += a[i];
    }
    
    scanf("%d %d", &x, &y);
    
    x--;
    y--;
    
    if (y < x) {
        int tmp = x;
        x = y;
        y = tmp;
    }
    
    for (i = x; i < y; i++) sum2 += a[i];
    
    if (sum2 * 2 < sum) {
        printf("%d\n", sum2);
    } else {
        printf("%d\n", sum - sum2);
    }
    
    return 0;
}