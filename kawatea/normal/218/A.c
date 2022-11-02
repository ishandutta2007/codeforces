#include <stdio.h>

int main()
{
    int n, k, i;
    int r[201];
    
    scanf("%d %d", &n, &k);
    
    for (i = 0; i < 2 * n + 1; i++) scanf("%d", &r[i]);
    
    for (i = 1; i < 2 * n + 1 && k > 0; i += 2) {
        if (r[i] - r[i - 1] > 1 && r[i] - r[i + 1] > 1) {
            r[i]--;
            
            k--;
        }
    }
    
    for (i = 0; i < 2 * n + 1; i++) {
        if (i > 0) putchar(' ');
        
        printf("%d", r[i]);
    }
    
    puts("");
    
    return 0;
}