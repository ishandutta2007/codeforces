#include <stdio.h>
#include <string.h>

int main()
{
    int n, m, p = 0, i;
    char s[51], t[51];
    
    scanf("%s", s);
    scanf("%s", t);
    
    n = strlen(s);
    m = strlen(t);
    
    for (i = 0; i < m && p < n; i++) {
        if (s[p] == t[i]) p++;
    }
    
    printf("%d\n", p + 1);
    
    return 0;
}