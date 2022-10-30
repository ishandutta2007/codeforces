#include <stdio.h>
#include <string.h>

int main()
{
    int n, m, sum = 0, i;
    char s[2001];
    
    scanf("%d", &n);
    scanf("%s", s);
    
    m = strlen(s);
    
    for (i = n; i < m; i += n) {
        if (s[i - 1] == s[i - 2] && s[i - 2] == s[i - 3]) sum++;
    }
    
    printf("%d\n", sum);
    
    return 0;
}