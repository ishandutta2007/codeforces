#include <stdio.h>

int main()
{
    int k, i, j;
    int a[10] = {0};
    char s[4][5];
    
    scanf("%d", &k);
    
    for (i = 0; i < 4; i++) scanf("%s", s[i]);
    
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            if (s[i][j] == '.') continue;
            
            a[s[i][j] - '0']++;
        }
    }
    
    for (i = 0; i < 10; i++) {
        if (a[i] > k * 2) {
            puts("NO");
            
            return 0;
        }
    }
    
    puts("YES");
    
    return 0;
}