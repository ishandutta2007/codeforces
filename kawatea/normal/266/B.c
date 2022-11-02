#include <stdio.h>

int main()
{
    int n, t, i, j;
    char s[51];
    
    scanf("%d %d", &n, &t);
    scanf("%s", s);
    
    for (i = 0; i < t; i++) {
        for (j = n - 1; j > 0; j--) {
            if (s[j] == 'G' & s[j - 1] == 'B') {
                s[j] = 'B';
                s[j - 1] = 'G';
                j--;
            }
        }
    }
    
    printf("%s\n", s);
    
    return 0;
}