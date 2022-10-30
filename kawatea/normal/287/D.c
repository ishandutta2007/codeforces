#include <stdio.h>

int a[2000000];

int main()
{
    int n, i, j;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) a[i] = i + 1;
    
    for (i = 2; i <= n; i++) {
        int x = 0;
        
        for (j = 0; j < n; j += i) {
            int y = a[j + i - 2];
            
            a[j + i - 2] = x;
            
            x = y;
        }
        
        a[n + i - 2] = x;
    }
    
    for (i = 0; i < n; i++) {
        if (i > 0) putchar(' ');
        
        printf("%d", a[i + n - 1]);
    }
    
    puts("");
    
    return 0;
}