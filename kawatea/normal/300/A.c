#include <stdio.h>

int main()
{
    int n, c = 0, f = 0, i;
    int a[100];
    int b[100] = {0};
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    
    for (i = 0; i < n; i++) {
        if (a[i] < 0) {
            b[i] = 1;
            
            break;
        }
    }
    
    for (i = 0; i < n; i++) {
        if (a[i] == 0) {
            b[i] = 2;
            
            break;
        }
    }
    
    for (i = 0; i < n; i++) {
        if (b[i] != 0) continue;
        
        if (a[i] < 0) c++;
    }
    
    if (c % 2 == 1) {
        f = 1;
        
        for (i = 0; i < n; i++) {
            if (b[i] != 0) continue;
            
            if (a[i] < 0) {
                b[i] = 2;
                
                break;
            }
        }
    }
    
    printf("1 ");
    
    for (i = 0; i < n; i++) {
        if (b[i] == 1) {
            printf("%d\n", a[i]);
        }
    }
    
    printf("%d", n - 2 - f);
    
    for (i = 0; i < n; i++) {
        if (b[i] == 0) {
            printf(" %d", a[i]);
        }
    }
    
    puts("");
    
    printf("%d", f + 1);
    
    for (i = 0; i < n; i++) {
        if (b[i] == 2) {
            printf(" %d", a[i]);
        }
    }
    
    puts("");
    
    return 0;
}