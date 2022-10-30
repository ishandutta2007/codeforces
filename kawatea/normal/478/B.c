#include <stdio.h>

int main()
{
    int n, m;
    long long x, y, z;
    
    scanf("%d %d", &n, &m);
    
    x = n - m + 1;
    y = n / m;
    z = n % m;
    
    printf("%I64d %I64d\n", y * (y - 1) / 2 * (m - z) + (y + 1) * y / 2 * z, x * (x - 1) / 2);
    
    return 0;
}