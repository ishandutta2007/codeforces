#include <stdio.h>

int gcd(int a, int b)
{
    if (a % b == 0) {
        return b;
    } else {
        return gcd(b, a % b);
    }
}

int min(int a, int b)
{
    if (a < b) {
        return a;
    } else {
        return b;
    }
}

int main()
{
    int n, m, x, y, a, b, g, p, x1, y1, x2, y2;
    
    scanf("%d %d %d %d %d %d", &n, &m, &x, &y, &a, &b);
    
    g = gcd(a, b);
    
    a /= g;
    b /= g;
    
    p = min(n / a, m / b);
    
    a *= p;
    b *= p;
    
    if ((a + 1) / 2 <= x && n - a / 2 >= x) {
        x1 = x - (a + 1) / 2;
        x2 = x1 + a;
    } else if ((a + 1) / 2 <= x) {
        x1 = n - a;
        x2 = n;
    } else {
        x1 = 0;
        x2 = a;
    }
    
    if ((b + 1) / 2 <= y && m - b / 2 >= y) {
        y1 = y - (b + 1) / 2;
        y2 = y1 + b;
    } else if ((b + 1) / 2 <= y) {
        y1 = m - b;
        y2 = m;
    } else {
        y1 = 0;
        y2 = b;
    }
    
    printf("%d %d %d %d\n", x1, y1, x2, y2);
    
    return 0;
}