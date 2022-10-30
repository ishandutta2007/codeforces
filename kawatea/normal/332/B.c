#include <stdio.h>

int a[200000];
long long b[200000][2];
long long sum[200001];

int main()
{
    int n, k, x, y, i;
    long long ans = 0;
    
    scanf("%d %d", &n, &k);
    
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    
    for (i = 0; i < n; i++) sum[i + 1] = sum[i] + a[i];
    
    for (i = n - 1; i >= 0; i--) {
        if (i + k > n) continue;
        
        if (b[i + 1][1] > sum[i + k] - sum[i]) {
            b[i][0] = b[i + 1][0];
            b[i][1] = b[i + 1][1];
        } else {
            b[i][0] = i;
            b[i][1] = sum[i + k] - sum[i];
        }
    }
    
    for (i = 0; i < n; i++) {
        if (i + 2 * k > n) break;
        
        if (sum[i + k] - sum[i] + b[i + k][1] > ans) {
            ans = sum[i + k] - sum[i] + b[i + k][1];
            
            x = i + 1;
            y = b[i + k][0] + 1;
        }
    }
    
    printf("%d %d\n", x, y);
    
    return 0;
}