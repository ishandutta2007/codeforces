#include <stdio.h>
#include <string.h>

long long powmod(long long x, long long y, long long m)
{
    long long ans = 1;
    
    while (y) {
        if (y & 1) ans = ans * x % m;
        
        x = x * x % m;
        y >>= 1;
    }
    
    return ans;
}

long long mod_inverse(long long a, long long m)
{
    long long b = m, x = 1, y = 0;
    
    while (b) {
        long long t = a / b, tmp;
        
        a -= t * b;
        
        tmp = a;
        a = b;
        b = tmp;
        
        x -= t * y;
        
        tmp = x;
        x = y;
        y = tmp;
    }
    
    return (m + x % m) % m;
}

int main()
{
    int n, k, m = 1000000007, i;
    long long ans = 0, sum = 1;
    char s[100001];
    
    scanf("%s", s);
    scanf("%d", &k);
    
    n = strlen(s);
    
    for (i = 0; i < n; i++) {
        if (s[i] == '0' || s[i] == '5') ans = (ans + sum) % m;
        
        sum = sum * 2 % m;
    }
    
    if (sum == 1) {
        ans = ans * k % m;
    } else {
        ans = ans * ((powmod(sum, k, m) - 1 + m) % m) % m;
        ans = ans * mod_inverse((sum - 1 + m) % m, m) % m;
    }
    
    printf("%d\n", (int)ans);
    
    return 0;
}