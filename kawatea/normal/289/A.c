#include <stdio.h>

int main()
{
    int n, k, i;
    long long sum = 0;
    
    scanf("%d %d", &n, &k);
    
    for (i = 0; i < n; i++) {
        int x, y;
        
        scanf("%d %d", &x, &y);
        
        sum += y - x + 1;
    }
    
    printf("%d\n", (k - sum % k) % k);
    
    return 0;
}