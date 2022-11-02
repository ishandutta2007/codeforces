#include <stdio.h>
#include <string.h>

int main()
{
    int n, c = 0, i;
    int a[26] = {0};
    char s[1001];
    
    scanf("%s", s);
    
    n = strlen(s);
    
    for (i = 0; i < n; i++) a[s[i] - 'a']++;
    
    for (i = 0; i < 26; i++) {
        if (a[i] % 2 == 1) c++;
    }
    
    if (c % 2 == 1 || c == 0) {
        puts("First");
    } else {
        puts("Second");
    }
    
    return 0;
}