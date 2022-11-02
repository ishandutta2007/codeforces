#include <stdio.h>

int main()
{
    int n, i;
    
    scanf("%d", &n);
    
    printf("%d", n);
    
    for (i = 0; i < n - 1; i++) printf(" %d", i + 1);
    
    puts("");
    
    return 0;
}