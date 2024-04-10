#include <stdio.h>

int min(int a, int b)
{
    if (a < b) {
        return a;
    } else {
        return b;
    }
}

int main()
{
    int n, i, j, k;
    int a[500][500];
    int b[500];
    int c[500] = {0};
    long long d[500];
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    
    for (i = 0; i < n; i++) {
        scanf("%d", &b[i]);
        
        b[i]--;
    }
    
    for (i = n - 1; i >= 0; i--) {
        long long sum = 0;
        
        c[b[i]] = 1;
        
        for (j = 0; j < n; j++) {
            for (k = 0; k < n; k++) {
                a[j][k] = min(a[j][k], a[j][b[i]] + a[b[i]][k]);
                
                if (c[j] == 1 && c[k] == 1) sum += a[j][k];
            }
        }
        
        d[i] = sum;
    }
    
    for (i = 0; i < n; i++) {
        if (i > 0) putchar(' ');
        
        printf("%I64d", d[i]);
    }
    
    return 0;
}