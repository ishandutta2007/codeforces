#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int n, m, i;
    long long l, r, mid;
    long long a[100000];
    long long b[100000];
    
    scanf("%d %d", &n, &m);
    
    for (i = 0; i < n; i++) scanf("%I64d", &a[i]);
    for (i = 0; i < m; i++) scanf("%I64d", &b[i]);
    
    l = -1, r = 1e18, mid = (l + r) / 2;
    
    while (r - l > 1) {
        int x = 0;
        
        for (i = 0; i < n && x < m; i++) {
            if (a[i] - mid > b[x]) break;
            
            if (a[i] < b[x]) {
                while (x < m && a[i] + mid >= b[x]) x++;
            } else {
                long long y = b[x];
                
                while (x < m && a[i] >= b[x]) x++;
                
                while (x < m && b[x] - y + min(b[x] - a[i], a[i] - y) <= mid) x++;
            }
        }
        
        if (x == m) {
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