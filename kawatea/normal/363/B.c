#include <stdio.h>

int a[150000];

int main()
{
    int n, k, sum = 0, x, y = 1, i;
    
    scanf("%d %d", &n, &k);
    
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    
    for (i = 0; i < k; i++) sum += a[i];
    
    x = sum;
    
    for (i = k; i < n; i++) {
        sum += a[i];
        sum -= a[i - k];
        
        if (sum < x) {
            x = sum;
            y = i - k + 2;
        }
    }
    
    printf("%d\n", y);
    
    return 0;
}