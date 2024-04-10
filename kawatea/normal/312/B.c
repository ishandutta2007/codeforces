#include <stdio.h>

int main()
{
    int a, b, c, d;
    
    scanf("%d %d %d %d", &a, &b, &c, &d);
    
    printf("%.12lf\n", (double)a / b / (1 - (1 - (double)a / b) * (1 - (double)c / d)));
    
    return 0;
}