#include <stdio.h>

int main()
{
    int n, m, k, sum = 0, i, j;
    int a[50] = {0};
    
    scanf("%d %d %d", &n, &m, &k);
    
    for (i = 0; i < n; i++) {
        int x;
        
        scanf("%d", &x);
        
        a[x - 1]++;
    }
    
    while (m > k) {
        for (i = 49; i >= 0; i--) {
            if (a[i] > 0) {
                k += i;
                
                a[i]--;
                
                sum++;
                
                break;
            }
        }
        
        if (i < 0) {
            puts("-1");
            
            return 0;
        }
    }
    
    printf("%d\n", sum);
    
    return 0;
}