#include <stdio.h>

int a[2000];
int b[2000][2000];
double c[2001][2001];

int main()
{
    int n, k, i, j;
    double sum = 0;
    int a[2000] = {0};
    
    for (i = 0; i <= 2000; i++) {
        c[i][0] = c[i][i] = 1;
        
        for (j = 1; j < i; j++) c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
    }
    
    scanf("%d %d", &n, &k);
    
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            int x;
            
            scanf("%d", &x);
            
            b[i][j] = b[j][i] = x;
            
            if (x >= 0) {
                a[i]++;
                a[j]++;
            }
        }
        
        b[i][i] = -1;
    }
    
    for (i = 0; i < n; i++) {
        if (a[i] >= k) {
            for (j = 0; j < n; j++) {
                if (b[i][j] >= 0) sum += c[a[i] - 1][k - 1] * b[i][j];
            }
        }
    }
    
    printf("%I64d\n", (long long)(sum / c[n][k] + 1e-8));
    
    return 0;
}