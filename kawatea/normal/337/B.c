#include <stdio.h>

int gcd(int a, int b)
{
    if (a % b == 0) return b;
    
    return gcd(b, a % b);
}

int main()
{
    int a, b, c, d, p, q, g;
    
    scanf("%d %d %d %d", &a, &b, &c, &d);
    
    g = gcd(a, b);
    
    a /= g;
    b /= g;
    
    g = gcd(c, d);
    
    c /= g;
    d /= g;
    
    if (a * d == b * c) {
        p = 0;
        q = 1;
    } else if (a * d < b * c) {
        p = b * c - a * d;
        q = b * c;
        
        g = gcd(p, q);
        
        p /= g;
        q /= g;
    } else {
        p = a * d - b * c;
        q = a * d;
        
        g = gcd(p, q);
        
        p /= g;
        q /= g;
    }
    
    printf("%d/%d\n", p, q);
    
    return 0;
}