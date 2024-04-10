#include <stdio.h>

int main()
{
    int a, b, c, x;
    
    scanf("%d %d %d", &a, &b, &c);
    
    x = (a - b) * c / b;
    
    if (b * x < (a - b) * c) x++;
    
    printf("%d\n", x);
    
    return 0;
}