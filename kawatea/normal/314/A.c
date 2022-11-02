#include <stdio.h>

int a[200000];
long long d[200001];

int main()
{
    int n, k, c = 0, i, j;
    
    scanf("%d %d", &n, &k);
    
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    
    for (i = 0; i < n; i++) {
        long long x = (long long)(n - i - 1) * a[i] * (i - c);
        
        d[i + 1] = d[i];
        
        if (d[i] < k + x) {
            printf("%d\n", i + 1);
            
            c++;
        } else {
            d[i + 1] += (long long)a[i] * (i - c);
        }
    }
    
    return 0;
}