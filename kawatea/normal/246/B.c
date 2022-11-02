#include <stdio.h>

int main()
{
    int n, sum = 0, i;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        int x;
        
        scanf("%d", &x);
        
        sum += x;
    }
    
    if (sum % n == 0) {
        printf("%d\n", n);
    } else {
        printf("%d\n", n - 1);
    }
    
    return 0;
}