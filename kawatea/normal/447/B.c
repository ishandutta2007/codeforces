#include <stdio.h>
#include <string.h>

int a[26];
char s[1001];

int main()
{
    int n, k, ans = 0, x = 0, i;
    
    scanf("%s", s);
    scanf("%d", &k);
    
    for (i = 0; i < 26; i++) scanf("%d", &a[i]);
    
    for (i = 0; i < 26; i++) {
        if (a[i] > x) x = a[i];
    }
    
    n = strlen(s);
    
    for (i = 0; i < n; i++) ans += a[s[i] - 'a'] * (i + 1);
    
    for (i = 0; i < k; i++) ans += x * (n + i + 1);
    
    printf("%d\n", ans);
    
    return 0;
}