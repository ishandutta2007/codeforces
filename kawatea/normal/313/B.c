#include <stdio.h>
#include <string.h>

int main()
{
    int n, m, i;
    char s[100001];
    int a[100001] = {0};
    
    scanf("%s", s);
    
    n = strlen(s);
    
    for (i = 0; i < n - 1; i++) {
        if (s[i] == s[i + 1]) a[i + 1] = 1;
    }
    
    for (i = 1; i <= n; i++) a[i] += a[i - 1];
    
    scanf("%d", &m);
    
    for (i = 0; i < m; i++) {
        int x, y;
        
        scanf("%d %d", &x, &y);
        
        printf("%d\n", a[y - 1] - a[x - 1]);
    }
    
    return 0;
}