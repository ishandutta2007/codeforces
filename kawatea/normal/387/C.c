#include <stdio.h>
#include <string.h>

char s[100001];

int main()
{
    int n, ans = 1, i, j, k;
    
    scanf("%s", s);
    
    n = strlen(s);
    
    for (i = 1; i < n; i++) {
        if (s[i] != '0') break;
    }
    
    for (; i < n;) {
        for (j = i + 1; j < n; j++) {
            if (s[j] != '0') break;
        }
        
        if (j - i < i) {
            ans++;
        } else if (j - i > i) {
            ans = 1;
        } else {
            int f = 0;
            
            for (k = 0; k < i; k++) {
                if (s[k] > s[i + k]) {
                    break;
                } else if (s[k] < s[i + k]) {
                    f = 1;
                    break;
                }
            }
            
            if (f == 0) {
                ans++;
            } else {
                ans = 1;
            }
        }
        
        i = j;
    }
    
    printf("%d\n", ans);
    
    return 0;
}