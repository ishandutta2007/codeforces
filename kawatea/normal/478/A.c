#include <stdio.h>

int main()
{
    int sum = 0, i;
    
    for (i = 0; i < 5; i++) {
        int x;
        
        scanf("%d", &x);
        
        sum += x;
    }
    
    if (sum % 5 == 0 && sum > 0) {
        printf("%d\n", sum / 5);
    } else {
        puts("-1");
    }
    
    return 0;
}