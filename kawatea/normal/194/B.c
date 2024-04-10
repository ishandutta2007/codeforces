#include <stdio.h>

long long gcd(long long a, long long b)
{
    if (a % b == 0) {
        return b;
    } else {
        return gcd(b, a % b);
    }
}

long long lcm(long long a, long long b)
{
    return a / gcd(a, b) * b;
}

int main()
{
    int t, i;
    
    scanf("%d", &t);
    
    for (i = 0; i < t; i++) {
        long long n;
        
        scanf("%I64d", &n);
        
        printf("%I64d\n", lcm(n * 4, n + 1) / (n + 1) + 1);
    }
    
    return 0;
}