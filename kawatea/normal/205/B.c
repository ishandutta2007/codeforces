#include <stdio.h>

int main()
{
    int n, i;
    long long sum = 0;
    int a[100000];
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    
    for (i = 1; i < n; i++) {
        if (a[i] < a[i - 1]) sum += a[i - 1] - a[i];
    }
    
    printf("%I64d\n", sum);
    
    return 0;
}