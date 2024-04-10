#include <stdio.h>

int main()
{
    int n, sx, sy, tx, ty, i;
    char s[100001];
    
    scanf("%d %d %d %d %d", &n, &sx, &sy, &tx, &ty);
    scanf("%s", s);
    
    for (i = 0; i < n; i++) {
        if (s[i] == 'E') {
            if (sx < tx) sx++;
        } else if (s[i] == 'S') {
            if (sy > ty) sy--;
        } else if (s[i] == 'W') {
            if (sx > tx) sx--;
        } else {
            if (sy < ty) sy++;
        }
        
        if (sx == tx && sy == ty) {
            printf("%d\n", i + 1);
            
            return 0;
        }
    }
    
    puts("-1");
    
    return 0;
}