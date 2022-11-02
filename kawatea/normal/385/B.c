#include <stdio.h>
#include <string.h>

int main()
{
    int n, ans = 0, i, j;
    int a[5000] = {0};
    char s[5001];
    
    scanf("%s", s);
    
    n = strlen(s);
    
    for (i = 3; i < n; i++) {
        if (s[i - 3] == 'b' && s[i - 2] == 'e' && s[i - 1] == 'a' && s[i] == 'r') a[i] = 1;
    }
    
    for (i = 0; i < n; i++) {
        int f = 0;
        
        for (j = i + 3; j < n; j++) {
            if (a[j] == 1) f = 1;
            
            ans += f;
        }
    }
    
    printf("%d\n", ans);
    
    return 0;
}