#include <stdio.h>

int a[10];

int ok(int x)
{
    while (x) {
        if (a[x % 10] > 0) return 1;
        
        x /= 10;
    }
    
    return 0;
}

int main()
{
    int n, m, c = 0, i;
    
    scanf("%d", &n);
    
    m = n;
    
    while (m) {
        a[m % 10]++;
        
        m /= 10;
    }
    
    for (i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            if (ok(i)) c++;
            if (n / i != i && ok(n / i)) c++;
        }
    }
    
    printf("%d\n", c);
    
    return 0;
}