#include <stdio.h>

int main()
{
    int n, x, i;
    int a[100000];
    int b[100000] = {0};
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    
    x = a[n - 1];
    
    for (i = n - 2; i >= 0; i--) {
        if (a[i] < x) {
            x = x - a[i];
            
            b[i] = 1;
            b[i + 1] = 1 - b[i + 1];
        } else {
            x = a[i] - x;
            
            b[i + 1] = 1 - b[i + 1];
        }
    }
    
    x = 0;
    
    for (i = 0; i < n; i++) {
        x ^= b[i];
        
        if (x == 0) {
            putchar('+');
        } else {
            putchar('-');
        }
    }
    
    puts("");
    
    return 0;
}