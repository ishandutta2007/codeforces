#include <stdio.h>

int main()
{
    int n, c = 0, i, j;
    int x[200], y[200];
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) scanf("%d %d", &x[i], &y[i]);
    
    for (i = 0; i < n; i++) {
        int f = 0;
        
        for (j = 0; j < n; j++) {
            if (i == j) continue;
            
            if (x[i] == x[j]) {
                if (y[i] < y[j]) {
                    f |= 1;
                } else {
                    f |= 2;
                }
            } else if (y[i] == y[j]) {
                if (x[i] < x[j]) {
                    f |= 4;
                } else {
                    f |= 8;
                }
            }
        }
        
        if (f == 15) c++;
    }
    
    printf("%d\n", c);
    
    return 0;
}