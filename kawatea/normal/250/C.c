#include <stdio.h>

int main()
{
    int n, k, p = 0, num = 0, i;
    int a[100000];
    int b[100000];
    int c[100000] = {0};
    
    scanf("%d %d", &n, &k);
    
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        
        a[i]--;
    }
    
    for (i = 0; i < n; i++) {
        if (p == 0 || a[i] != b[p - 1]) b[p++] = a[i];
    }
    
    for (i = 0; i < p; i++) {
        if (i == 0 || i == p - 1) {
            c[b[i]]++;
        } else if (b[i - 1] == b[i + 1]) {
            c[b[i]] += 2;
        } else {
            c[b[i]]++;
        }
    }
    
    for (i = 0; i < k; i++) {
        if (c[i] > c[num]) num = i;
    }
    
    printf("%d\n", num + 1);
    
    return 0;
}