#include <stdio.h>

int main()
{
    int s, n, i, j;
    int x[1000], y[1000];
    int f[1000] = {0};
    
    scanf("%d %d", &s, &n);
    
    for (i = 0; i < n; i++) scanf("%d %d", &x[i], &y[i]);
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (f[j] == 0 && s > x[j]) {
                f[j] = 1;
                
                s += y[j];
            }
        }
    }
    
    for (i = 0; i < n; i++) {
        if (f[i] == 0) {
            puts("NO");
            
            return 0;
        }
    }
    
    puts("YES");
    
    return 0;
}