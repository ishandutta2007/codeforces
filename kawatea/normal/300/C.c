#include <stdio.h>

long long inv[1000001];

int check(int x, int a, int b)
{
    while (x > 0) {
        if (x % 10 != a && x % 10 != b) return 0;
        
        x /= 10;
    }
    
    return 1;
}

int main()
{
    int a, b, n, m = 1000000007, i, j;
    long long sum = 0, c = 1;
    
    scanf("%d %d %d", &a, &b, &n);
    
    inv[1] = 1;
    
    for (i = 2; i <= n; i++) inv[i] = inv[m % i] * (m - m / i) % m;
    
    for (i = 0; i <= n; i++) {
        int x = a * i + b * (n - i);
        
        if (check(x, a, b)) sum = (sum + c) % m;
        
        c = c * (n - i) % m;
        c = c * inv[i + 1] % m;
    }
    
    printf("%d\n", (int)sum);
    
    return 0;
}