#include <stdio.h>

int main()
{
    int n, k, i;
    
    scanf("%d %d", &n, &k);
    
    for (i = 0; i < n; i++) {
        if (k - i * 2 >= 3 * (n - i)) break;
    }
    
    printf("%d\n", i);
    
    return 0;
}