#include <cstdio>

char s[200001];

int main()
{
    int n, x = 0, y = 0, i;
    
    scanf("%d", &n);
    scanf("%s", s);
    
    for (i = 0; i < n; i++) {
        if (s[i] == '0') {
            x++;
        } else {
            y++;
        }
    }
    
    if (x < y) {
        printf("%d\n", y - x);
    } else {
        printf("%d\n", x - y);
    }
    
    return 0;
}