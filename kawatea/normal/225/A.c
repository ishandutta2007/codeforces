#include <stdio.h>

int main()
{
    int n, x, i, j;
    
    scanf("%d", &n);
    scanf("%d", &x);
    
    for (i = 0; i < n; i++) {
        int p, q;
        
        scanf("%d %d", &p, &q);
        
        if (i == 0) {
            continue;
        } else {
            int a[7] = {0};
            
            a[p] = a[q] = a[7 - p] = a[7 - q] = 1;
            
            if (a[x] == 1) {
                puts("NO");
                
                return 0;
            }
        }
    }
    
    puts("YES");
    
    return 0;
}