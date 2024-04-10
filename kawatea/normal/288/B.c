#include <stdio.h>

int a[8] = {1, 2, 9, 64, 625, 7776, 117649, 2097152};
int m = 1000000007;

long long mod_pow(long long x, long long y)
{
    long long ans = 1;
    
    while (y) {
        if (y & 1) ans = ans * x % m;
        
        x = x * x % m;
        y >>= 1;
    }
    
    return ans;
}

int main()
{
    int n, k, i;
    long long ans;
    
    scanf("%d %d", &n, &k);
    
    ans = a[k - 1];
    
    ans = ans * mod_pow(n - k, n - k) % m;
    
    printf("%d\n", (int)ans);
    
    return 0;
}