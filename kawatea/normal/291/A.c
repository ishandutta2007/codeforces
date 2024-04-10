#include <stdio.h>

int main()
{
    int n, sum = 0, i, j;
    int a[1000];
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    
    for (i = 0; i < n; i++) {
        int c = 0;
        
        if (a[i] == 0) continue;
        
        for (j = i; j < n; j++) {
            if (a[i] == a[j]) c++;
        }
        
        if (c > 2) {
            puts("-1");
            
            return 0;
        }
        
        if (c == 2) sum++;
    }
    
    printf("%d\n", sum);
    
    return 0;
}