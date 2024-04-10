#include <stdio.h>

int main()
{
    int n, m, ans = 0, i, j;
    int a[3000];
    int b[3000];
    
    scanf("%d %d", &n, &m);
    
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    for (i = 0; i < m; i++) scanf("%d", &b[i]);
    
    for (i = 0, j = 0; i < n; i++) {
        if (j == m) {
            ans++;
        } else if (a[i] > b[j]) {
            i--;
            j++;
        } else {
            j++;
        }
    }
    
    printf("%d\n", ans);
    
    return 0;
}