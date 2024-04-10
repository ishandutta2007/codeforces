#include <stdio.h>

int abs(int x)
{
    if (x < 0) {
        return -x;
    } else {
        return x;
    }
}

int main()
{
    int i, j;
    int a[5][5];
    
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            if (a[i][j] == 1) {
                printf("%d\n", abs(i - 2) + abs(j - 2));
                
                return 0;
            }
        }
    }
    
    return 0;
}