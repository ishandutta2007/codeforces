#include <stdio.h>

int main()
{
    int c = 0, i, j;
    int a[4][2];
    
    for (i = 0; i < 4; i++) scanf("%d %d", &a[i][0], &a[i][1]);
    
    for (i = 0; i < 2; i++) {
        int c1 = 0;
        int c2 = 0;
        
        for (j = 0; j < 2; j++) {
            int x1 = a[i][0];
            int y1 = a[1 - i][1];
            int x2 = a[j + 2][0];
            int y2 = a[3 - j][1];
            
            if (x1 > y2 && y1 > x2) {
                c1++;
            } else if (x1 < y2 && y1 < x2) {
                c2++;
            }
        }
        
        if (c1 == 2) {
            puts("Team 1");
            
            return 0;
        } else if (c2 >= 1) {
            c++;
        }
    }
    
    if (c == 2) {
        puts("Team 2");
    } else {
        puts("Draw");
    }
    
    return 0;
}