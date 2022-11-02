#include <stdio.h>

int main()
{
    int n, i;
    int a[100000];
    int b[100000][2];
    int c[100000][2];
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    
    b[0][0] = b[0][1] = 0;
    
    for (i = 1; i < n; i++) {
        b[i][0] = b[i - 1][0];
        b[i][1] = b[i - 1][1];
        
        if (a[i] < a[i - 1]) b[i][0] = 1;
        if (a[i] > a[i - 1]) b[i][1] = 1;
    }
    
    c[n - 1][0] = c[n - 1][1] = 0;
    
    for (i = n - 2; i >= 0; i--) {
        c[i][0] = c[i + 1][0];
        c[i][1] = c[i + 1][1];
        
        if (a[i] > a[i + 1]) c[i][0] = 1;
        if (a[i] < a[i + 1]) c[i][1] = 1;
    }
    
    for (i = 0; i < n - 1; i++) {
        if (a[i] == a[i + 1]) continue;
        
        if (a[i] > a[i + 1]) {
            if (b[i][0] == 1 || c[i + 1][0] == 1 || (i > 0 && a[i - 1] > a[i + 1]) || (i < n - 2 && a[i] > a[i + 2])) {
                printf("%d %d\n", i + 1, i + 2);
                
                return 0;
            }
        } else {
            if (b[i][1] == 1 || c[i + 1][1] == 1 || (i > 0 && a[i - 1] < a[i + 1]) || (i < n - 2 && a[i] < a[i + 2])) {
                printf("%d %d\n", i + 1, i + 2);
                
                return 0;
            }
        }
    }
    
    puts("-1");
    
    return 0;
}