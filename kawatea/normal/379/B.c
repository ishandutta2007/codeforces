#include <stdio.h>

int main()
{
    int n, i;
    int a[300];
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    
    for (i = 0; i < n; i++) {
        while (a[i]) {
            putchar('P');
            
            a[i]--;
            
            if (i == 0) {
                putchar('R');
                putchar('L');
            } else {
                putchar('L');
                putchar('R');
            }
        }
        
        if (i < n - 1) putchar('R');
    }
    
    puts("");
    
    return 0;
}