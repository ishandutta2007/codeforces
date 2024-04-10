#include <stdio.h>
#include <string.h>

char s1[1000001];
char s2[1000001];

int main()
{
    int n, m, i;
    
    scanf("%s", s1);
    scanf("%s", s2);
    
    n = strlen(s1);
    m = strlen(s2);
    
    if (n != m) {
        puts("NO");
    } else {
        int x = 0, y = 0;
        
        for (i = 0; i < n; i++) x += s1[i] - '0';
        for (i = 0; i < n; i++) y += s2[i] - '0';
        
        if ((x == 0 && y != 0) || (x != 0 && y == 0)) {
            puts("NO");
        } else {
            puts("YES");
        }
    }
    
    return 0;
}