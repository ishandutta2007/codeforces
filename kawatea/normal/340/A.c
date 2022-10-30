#include <stdio.h>

int gcd(int a, int b)
{
    if (a % b == 0) return b;
    
    return gcd(b, a % b);
}

int lcm(int a, int b)
{
    return a * b / gcd(a, b);
}

int main()
{
    int x, y, a, b;
    
    scanf("%d %d %d %d", &x, &y, &a, &b);
    
    x = lcm(x, y);
    
    printf("%d\n", b / x - (a - 1) / x);
    
    return 0;
}