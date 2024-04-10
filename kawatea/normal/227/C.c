#include <stdio.h>

long long f(long long p, int n, int m)
{
    if (n == 1) {
        return p;
    } else if (n % 2 == 0) {
        return f(p * p % m, n / 2, m);
    } else {
        return f(p, n - 1, m) * p % m;
    }
}

int main()
{
    int n, m;
    long long x;
    
    scanf("%d %d", &n, &m);
    
    x = f(3, n, m);
    
    printf("%d\n", (int)((x - 1 + m) % m));
    
    return 0;
}