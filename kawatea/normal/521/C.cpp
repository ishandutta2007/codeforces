#include <cstdio>

using namespace std;

int m = 1000000007;
long long inv[100001];
long long fact[100001];
long long invfact[100001];
long long a[100000];
long long c[100000];
char s[100001];

long long comb(int x, int y)
{
    return fact[x] * invfact[y] % m * invfact[x - y] % m;
}

int main()
{
    int n, k, i;
    long long ans = 0, sum = 0;
    
    scanf("%d %d", &n, &k);
    scanf("%s", s);
    
    inv[1] = 1;
    
    for (i = 2; i <= n; i++) inv[i] = inv[m % i] * (m - m / i) % m;
    
    fact[0] = invfact[0] = 1;
    
    for (i = 1; i <= n; i++) fact[i] = fact[i - 1] * i % m;
    for (i = 1; i <= n; i++) invfact[i] = invfact[i - 1] * inv[i] % m;
    
    a[0] = 1;
    
    for (i = 1; i < n; i++) a[i] = a[i - 1] * 10 % m;
    
    if (k == 0) {
        c[n - 1] = 1;
        sum = a[n - 1];
    } else {
        for (i = 0; i < n - k; i++) {
            c[i] = comb(n - i - 2, k - 1);
            sum = (sum + a[i] * c[i] % m) % m;
        }
    }
    
    for (i = 0; i < n; i++) {
        if (i > k) {
            c[n - i - 1] = (c[n - i - 1] + c[n - i]) % m;
            sum = (sum - a[n - i] * c[n - i] % m + a[n - i - 1] * c[n - i] % m + m) % m;
        }
        
        ans = (ans + sum * (s[i] - '0') % m) % m;
    }
    
    printf("%I64d\n", ans);
    
    return 0;
}