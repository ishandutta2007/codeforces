#include <stdio.h>
#include <string.h>

int main()
{
    int n, c1 = 0, c2 = 0, f = 0, ans = 1, i;
    int a[10] = {0};
    char s[100001];
    
    scanf("%s", s);
    
    n = strlen(s);
    
    for (i = 0; i < n; i++) {
        if (s[i] >= 'A' && s[i] <= 'J') {
            a[s[i] - 'A'] = 1;
        } else if (s[i] == '?') {
            c1++;
        }
    }
    
    for (i = 0; i < 10; i++) {
        if (a[i] == 1) c2++;
    }
    
    if (s[0] == '?') {
        ans *= 9;
        
        c1--;
    } else if (s[0] >= 'A' && s[0] <= 'J') {
        f = 1;
        
        c2--;
    }
    
    if (f == 0) {
        for (i = 0; i < c2; i++) ans *= 10 - i;
    } else {
        ans *= 9;
        
        for (i = 0; i < c2; i++) ans *= 9 - i;
    }
    
    printf("%d", ans);
    
    for (i = 0; i < c1; i++) putchar('0');
    
    puts("");
    
    return 0;
}