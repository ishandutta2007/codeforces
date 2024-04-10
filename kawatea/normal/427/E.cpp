#include <cstdio>
#include <algorithm>

using namespace std;

int a[1000000];
int b[1000000];
int c[1000000];

int main()
{
    int n, m, c1 = 0, c2 = 0, p = 0, q = 0, i;
    long long ans = 1e18, sum = 0;
    
    scanf("%d %d", &n, &m);
    
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    
    for (i = n - 1; i >= 0; i--) {
        if (c1 % m == 0) {
            b[p++] = a[i] - a[0];
            sum += a[i] - a[0];
        }
        
        c1++;
    }
    
    ans = min(ans, sum);
    
    for (i = 0; i < n; i++) {
        if (c2 % m == 0) {
            c[q++] = a[n - 1] - a[i];
            sum += a[n - 1] - a[i];
        }
        
        c2++;
        
        if (m == 1 || c1 % m == 1) sum -= b[--p];
        
        c1--;
        
        ans = min(ans, sum - (long long)p * (a[i] - a[0]) - (long long)q * (a[n - 1] - a[i]));
    }
    
    printf("%I64d\n", ans * 2);
    
    return 0;
}