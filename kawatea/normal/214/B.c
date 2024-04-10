#include <stdio.h>

int main()
{
    int n, sum = 0, i, j;
    int a[10] = {0};
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        int x;
        
        scanf("%d", &x);
        
        a[x]++;
        
        sum += x;
    }
    
    if (a[0] == 0) {
        puts("-1");
    } else {
        if (sum % 3 == 1) {
            if (a[1] + a[4] + a[7] > 0) {
                for (i = 1; ; i += 3) {
                    if (a[i] > 0) {
                        a[i]--;
                        n--;
                        
                        break;
                    }
                }
            } else if (a[2] + a[5] + a[8] > 1) {
                int p = 2;
                
                for (i = 2; p > 0; i += 3) {
                    while (p > 0 && a[i] > 0) {
                        a[i]--;
                        p--;
                        n--;
                    }
                }
            } else {
                puts("-1");
                
                return 0;
            }
        } else if (sum % 3 == 2) {
            if (a[2] + a[5] + a[8] > 0) {
                for (i = 2; ; i += 3) {
                    if (a[i] > 0) {
                        a[i]--;
                        n--;
                        
                        break;
                    }
                }
            } else if (a[1] + a[4] + a[7] > 1) {
                int p = 2;
                
                for (i = 1; p > 0; i += 3) {
                    while (p > 0 && a[i] > 0) {
                        a[i]--;
                        p--;
                        n--;
                    }
                }
            } else {
                puts("-1");
                
                return 0;
            }
        }
        
        if (a[0] == n) a[0] = 1;
        
        for (i = 9; i >= 0; i--) {
            for (j = 0; j < a[i]; j++) printf("%d", i);
        }
        
        puts("");
    }
    
    return 0;
}