#include <stdio.h>

int main()
{
    int n, i;
    char s[1001];
    
    scanf("%d", &n);
    scanf("%s", s);
    
    for (i = 0; i < n; i++) {
        if (s[i] != '.') break;
    }
    
    printf("%d", i + 1);
    
    for (; i < n; i++) {
        if (s[i] != 'R') break;
    }
    
    if (s[i] == 'L') {
        printf(" %d\n", i);
    } else {
        printf(" %d\n", i + 1);
    }
    
    return 0;
}