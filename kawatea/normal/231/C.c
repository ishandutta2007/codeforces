#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
    return *((int *)a) - *((int *)b);
}

int a[100000];
long long sum[100001];

int main()
{
    int n, k, p = 0, q = 0, i, j;
    
    scanf("%d %d", &n, &k);
    
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    
    qsort(a, n, sizeof(int), cmp);
    
    for (i = 0; i < n; i++) sum[i + 1] = sum[i] + a[i];
    
    for (i = 0; i < n; i++) {
        int l = -1, r = i, m = (l + r) / 2;
        
        while (r - l > 1) {
            if(sum[i + 1] - sum[m] + k >= (long long)a[i] * (i - m + 1)) {
                r = m;
                m = (l + r) / 2;
            } else {
                l = m;
                m = (l + r) / 2;
            }
        }
        
        if (i - r + 1 > p) {
            p = i - r + 1;
            q = a[i];
        }
    }
    
    printf("%d %d\n", p, q);
    
    return 0;
}