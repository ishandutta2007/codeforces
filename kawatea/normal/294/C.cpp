#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

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
    int n, m, mod = 1000000007, i, j;
    long long x, ans = 1;
    vector <int> v;
    
    scanf("%d %d", &n, &m);
    
    for (i = 0; i < m; i++) {
        int x;
        
        scanf("%d", &x);
        
        v.push_back(x);
    }
    
    sort(v.begin(), v.end());
    
    for (i = 1; i <= n - m; i++) ans = ans * i % mod;
    
    for (i = 0; i < v.size() - 1; i++) {
        int x = v[i + 1] - v[i] - 1;
        long long sum = 1, sum2 = 1;
        
        if (x == 0) continue;
        
        for (j = 2; j <= x; j++) {
            sum = sum * 2 % mod;
            sum2 = sum2 * j % mod;
        }
        
        ans = ans * sum % mod * mod_inverse(sum2, mod) % mod;
    }
    
    x = 1;
    
    if (v[0] > 2) {
        for (i = 1; i < v[0]; i++) x = x * i % mod;
        
        ans = ans * mod_inverse(x, mod) % mod;
    }
    
    x = 1;
    
    if (v.back() < n - 1) {
        for (i = 1; i <= n - v.back(); i++) x = x * i % mod;
        
        ans = ans * mod_inverse(x, mod) % mod;
    }
    
    printf("%d\n", (int)ans);
    
    return 0;
}