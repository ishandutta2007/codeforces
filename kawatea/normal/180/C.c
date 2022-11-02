#include <stdio.h>
#include <string.h>

int min(int a, int b)
{
    if (a < b) {
        return a;
    } else {
        return b;
    }
}

int main()
{
    int n, m = 1e9, x = 0, y = 0, i;
    char s[100001];
    
    scanf("%s", s);
    
    n = strlen(s);
    
    for (i = 0; i < n; i++) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            x++;
        }
    }
    
    for (i = 0; i < n; i++) {
        m = min(m, n - i - x + 2 * y);
        
        if (s[i] >= 'a' && s[i] <= 'z') y++;
    }
    
    m = min(m, y);
    
    printf("%d\n", m);
    
    return 0;
}