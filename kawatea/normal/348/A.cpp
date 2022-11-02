#include <cstdio>
#include <algorithm>

using namespace std;

int a[100000];

int main()
{
    int n, i;
    long long l, r, m;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    
    l = 0, r = 1e18, m = (l + r) / 2;
    
    while (r - l > 1) {
        long long sum = 0;
        
        for (i = 0; i < n; i++) {
            if (a[i] > m) break;
            
            sum = min(sum + m - a[i], m);
        }
        
        if (i == n && sum >= m) {
            r = m;
            m = (l + r) / 2;
        } else {
            l = m;
            m = (l + r) / 2;
        }
    }
    
    printf("%I64d\n", r);
    
    return 0;
}