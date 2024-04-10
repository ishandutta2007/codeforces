#include <stdio.h>
#include <string.h>

char s[1000001];

int main()
{
    int n, p, i;
    long long x = 0, y = 0;
    
    scanf("%s", s);
    
    n = strlen(s);
    
    for (i = 0; i < n; i++) {
        if (s[i] == '^') p = i;
    }
    
    for (i = 0; i < p; i++) {
        if (s[i] >= '1' && s[i] <= '9') x += (s[i] - '0') * (p - i);
    }
    
    for (i = p + 1; i < n; i++) {
        if (s[i] >= '1' && s[i] <= '9') y += (s[i] - '0') * (i - p);
    }
    
    if (x == y) {
        puts("balance");
    } else if (x > y) {
        puts("left");
    } else {
        puts("right");
    }
    
    return 0;
}