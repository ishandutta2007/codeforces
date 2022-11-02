#include <stdio.h>

int main()
{
    int n, sum, i;
    int a[100000];
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    
    sum = a[0] + n * 2 - 1;
    
    for (i = 1; i < n; i++) {
        if (a[i] > a[i - 1]) {
            sum += a[i] - a[i - 1];
        } else {
            sum += a[i - 1] - a[i];
        }
    }
    
    printf("%d\n", sum);
    
    return 0;
}