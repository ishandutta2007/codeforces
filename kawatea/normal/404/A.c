#include <stdio.h>

int main()
{
    int n, i, j;
    char s[300][301];
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) scanf("%s", s[i]);
    
    if (s[0][0] == s[0][1]) {
        puts("NO");
        
        return 0;
    }
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (j == i || j == n - i - 1) {
                if (s[i][j] != s[0][0]) {
                    puts("NO");
                    
                    return 0;
                }
            } else {
                if (s[i][j] != s[0][1]) {
                    puts("NO");
                    
                    return 0;
                }
            }
        }
    }
    
    puts("YES");
    
    return 0;
}