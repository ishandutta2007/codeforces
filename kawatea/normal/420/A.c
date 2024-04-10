#include <stdio.h>
#include <string.h>

int a[26] = {1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0};
char s[100001];

int main()
{
    int n, i;
    
    scanf("%s", s);
    
    n = strlen(s);
    
    for (i = 0; i < n / 2; i++) {
        if (s[i] != s[n - i - 1]) {
            puts("NO");
            
            return 0;
        }
    }
    
    for (i = 0; i < n; i++) {
        if (a[s[i] - 'A'] == 0) {
            puts("NO");
            
            return 0;
        }
    }
    
    puts("YES");
    
    return 0;
}