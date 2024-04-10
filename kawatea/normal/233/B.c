#include <stdio.h>
#include <math.h>

int s(long long x)
{
    int sum = 0;
    
    while (x) {
        sum += x % 10;
        x /= 10;
    }
    
    return sum;
}

long long min(long long a, long long b)
{
    if (a < b) {
        return a;
    } else {
        return b;
    }
}

long long max(long long a, long long b)
{
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

int main()
{
    long long n, ans = 1e18, i;
    
    scanf("%I64d", &n);
    
    for (i = sqrt(n); max(i, n / i) - min(i, n / i) <= 200 && i <= n; i++) {
        if (n % i == 0) {
            if (n / i < i) {
                if (s(n / i) == i - n / i) ans = min(ans, n / i);
            } else {
                if (s(i) == n / i - i) ans = min(ans, i);
            }
        }
    }
    
    if (ans == 1e18) {
        puts("-1");
    } else {
        printf("%I64d\n", ans);
    }
    
    return 0;
}