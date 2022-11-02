#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    long long n, m, k, l, r, mid, i;
    
    scanf("%I64d %I64d %I64d", &n, &m, &k);
    
    l = 0, r = 1e18, mid = (l + r) / 2;
    
    while (r - l > 1) {
        long long c = 0;
        
        for (i = 1; i <= n; i++) {
            long long x = mid / i;
            
            c += min(x, m);
        }
        
        if (c >= k) {
            r = mid;
            mid = (l + r) / 2;
        } else {
            l = mid;
            mid = (l + r) / 2;
        }
    }
    
    printf("%I64d\n", r);
    
    return 0;
}