#include <stdio.h>

int main()
{
    int n, x = 0, y = 0, z = 0, sum = 0, i;
    char s[200000];
    
    scanf("%d ", &n);
    scanf("%s", s);
    
    for (i = 0; i < n; i++) {
        if (s[i] == 'A') {
            x++;
        } else if (s[i] == 'I') {
            y++;
        } else {
            z++;
        }
    }
    
    if (y == 0) sum += x;
    if (y == 1) sum++;
    
    printf("%d\n", sum);
    
    return 0;
}