#include <stdio.h>

int main()
{
    int n, p, i, j, k, l;
    double sum = 0;
    int a[50];
    long long b[51][51];
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    
    scanf("%d", &p);
    
    for (i = 0; i < n; i++) {
        double tmp = 0;
        
        for (j = 0; j <= n; j++) {
            for (k = 0; k <= p; k++) {
                b[j][k] = 0;
            }
        }
        
        b[0][0] = 1;
        
        for (j = 0; j < n; j++) {
            if (j == i) continue;
            
            for (k = n - 1; k >= 0; k--) {
                for (l = p; l >= 0; l--) {
                    if (b[k][l] == 0) continue;
                    
                    if (l + a[j] <= p) b[k + 1][l + a[j]] += b[k][l];
                }
            }
        }
        
        for (j = 0; j <= n; j++) {
            for (k = 0; k <= p - a[i]; k++) {
                double tmp2 = b[j][k];
                
                for (l = 1; l <= j; l++) tmp2 *= l;
                for (l = 1; l <= n - j - 1; l++) tmp2 *= l;
                
                tmp += tmp2;
            }
        }
        
        for (j = 1; j <= n; j++) tmp /= j;
        
        sum += tmp;
    }
    
    printf("%lf\n", sum);
    
    return 0;
}