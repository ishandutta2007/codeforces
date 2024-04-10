#include <cstdio>

using namespace std;

long long mod_inverse(long long a, long long m)
{
    long long ans = 1;
    
    while (a > 1) {
        long long b = m % a;
        
        if (b < (a >> 1)) {
            ans = ans * (m - m / a) % m;
            a = b;
        } else {
            ans = ans * (m / a + 1) % m;
            a = a - b;
        }
    }
    
    return ans;
}

int main()
{
    int n, i;
    long long x = 1;
    
    scanf("%d", &n);
    
    if (n <= 4) {
        puts("YES");
        
        if (n <= 3) {
            for (i = 0; i < n; i++) printf("%d\n", i + 1);
        } else {
            puts("1");
            puts("3");
            puts("2");
            puts("4");
        }
        
        return 0;
    }
    
    for (i = 2; i * i <= n; i++) {
        if (n % i == 0) break;
    }
    
    if (n % i == 0) {
        puts("NO");
        
        return 0;
    }
    
    puts("YES");
    
    for (i = 0; i < n - 1; i++) {
        int y = (i + 1) * mod_inverse(x, n) % n;
        
        x = x * y % n;
        
        printf("%d\n", y);
    }
    
    printf("%d\n", n);
    
    return 0;
}