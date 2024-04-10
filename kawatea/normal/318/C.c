#include <stdio.h>

int main()
{
    long long x, y, m, sum = 0;
    
    scanf("%I64d %I64d %I64d", &x, &y, &m);
    
    if (x >= m || y >= m) {
        puts("0");
        
        return 0;
    }
    
    if (x <= 0 && y <= 0) {
        puts("-1");
        
        return 0;
    }
    
    if (x > y) {
        long long tmp = x;
        x = y;
        y = tmp;
    }
    
    if (x < 0) {
        sum += -x / y;
        
        x += y * sum;
    }
    
    while (x < m && y < m) {
        if (x < y) {
            x += y;
        } else {
            y += x;
        }
        
        sum++;
    }
    
    printf("%I64d\n", sum);
    
    return 0;
}