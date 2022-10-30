#include <stdio.h>

int main()
{
    int n, ans = 0, i, j, k;
    int a[100];
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    
    for (i = 0; i < n; i++) {
        for (j = i; j < n; j++) {
            int c = 0;
            
            for (k = 0; k < i; k++) c += a[k];
            for (k = i; k <= j; k++) c += 1 - a[k];
            for (k = j + 1; k < n; k++) c += a[k];
            
            if (c > ans) ans = c;
        }
    }
    
    printf("%d\n", ans);
    
    return 0;
}