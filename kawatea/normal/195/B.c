#include <stdio.h>

int main()
{
    int n, m, p = 0, i;
    int a[100000];
    
    scanf("%d %d", &n, &m);
    
    if (m % 2 == 1) {
        a[p++] = (m + 1) / 2;
        
        for (i = 1; i <= (m + 1) / 2; i++) {
            if ((m + 1) / 2 - i >= 1) a[p++] = (m + 1) / 2 - i;
            if ((m + 1) / 2 + i <= m) a[p++] = (m + 1) / 2 + i;
        }
    } else {
        a[p++] = m / 2;
        
        for (i = 1; i <= m / 2; i++) {
            if (m / 2 + i <= m) a[p++] = m / 2 + i;
            if (m / 2 - i >= 1) a[p++] = m / 2 - i;
        }
    }
    
    for (i = 0; i < n; i++) printf("%d\n", a[i % p]);
    
    return 0;
}