#include <stdio.h>

int main()
{
    int n, d, i;
    long long sum = 0;
    int a[100000];
    
    scanf("%d %d", &n, &d);
    
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    
    for (i = 0; i < n; i++) {
        int l = i, r = n, m = (l + r) / 2;
        
        while (r - l > 1) {
            if (a[m] <= a[i] + d) {
                l = m;
                m = (l + r) / 2;
            } else {
                r = m;
                m = (l + r) / 2;
            }
        }
        
        if (l >= i + 2) sum += (long long)(l - i) * (l - i - 1) / 2;
    }
    
    printf("%I64d\n", sum);
    
    return 0;
}