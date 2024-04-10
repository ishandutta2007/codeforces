#include <stdio.h>
#include <string.h>

int main()
{
    int n, m, x = 0, y = 0, i;
    char s1[1001], s2[1001];
    
    scanf("%s", s1);
    scanf("%s", s2);
    
    n = strlen(s1);
    m = strlen(s2);
    
    for (i = 0; i < n; i++) {
        if (s1[i] == '1') x++;
    }
    
    for (i = 0; i < m; i++) {
        if (s2[i] == '1') y++;
    }
    
    if (x % 2 == 1) x++;
    
    if (x >= y) {
        puts("YES");
    } else {
        puts("NO");
    }
    
    return 0;
}