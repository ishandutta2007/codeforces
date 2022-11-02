#include <stdio.h>

int main()
{
    int n, sum = 0, i;
    
    scanf("%d", &n);
    
    for (i = 1; i < n; i++) sum += i * (n - i);
    
    sum += n;
    
    printf("%d\n", sum);
    
    return 0;
}