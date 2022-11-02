#include <stdio.h>

int a[300];

int main()
{
    int p, n, i;
    
    scanf("%d %d", &p, &n);
    
    for (i = 0; i < n; i++) {
        int x;
        
        scanf("%d", &x);
        
        if (a[x % p] == 1) {
            printf("%d\n", i + 1);
            
            return 0;
        }
        
        a[x % p] = 1;
    }
    
    puts("-1");
    
    return 0;
}