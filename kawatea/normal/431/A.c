#include <stdio.h>
#include <string.h>

int a[4];
char s[100001];

int main()
{
    int n, ans = 0, i;
    
    for (i = 0; i < 4; i++) scanf("%d", &a[i]);
    
    scanf("%s", s);
    
    n = strlen(s);
    
    for (i = 0; i < n; i++) ans += a[s[i] - '1'];
    
    printf("%d\n", ans);
    
    return 0;
}