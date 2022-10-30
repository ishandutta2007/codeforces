#include <cstdio>

using namespace std;

int a[100000];

int main()
{
    int n, l, r, m, i;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    
    l = 0, r = 1e9, m = (l + r) / 2;
    
    while (r - l > 1) {
        int x = m;
        long long sum = 0;
        
        for (i = 0; i < n; i++) {
            sum += x - a[i];
            x = a[i];
            
            if (sum < 0) break;
        }
        
        if (i == n) {
            r = m;
            m = (l + r) / 2;
        } else {
            l = m;
            m = (l + r) / 2;
        }
    }
    
    printf("%d\n", r);
    
    return 0;
}