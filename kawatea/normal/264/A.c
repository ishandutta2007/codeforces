#include <stdio.h>
#include <string.h>

int a[1000000];
char s[1000001];

int main()
{
    int n, p, q, i;
    
    scanf("%s", s);
    
    n = strlen(s);
    
    p = 0;
    q = n - 1;
    
    for (i = 0; i < n; i++) {
        if (s[i] == 'l') {
            a[q--] = i + 1;
        } else {
            a[p++] = i + 1;
        }
    }
    
    for (i = 0; i < n; i++) printf("%d\n", a[i]);
    
    return 0;
}