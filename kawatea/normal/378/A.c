#include <stdio.h>

int main()
{
    int x, y, i;
    int a[3] = {0};
    
    scanf("%d %d", &x, &y);
    
    for (i = 1; i <= 6; i++) {
        if (abs(x - i) < abs(y - i)) {
            a[0]++;
        } else if (abs(x - i) == abs(y - i)) {
            a[1]++;
        } else {
            a[2]++;
        }
    }
    
    printf("%d %d %d\n", a[0], a[1], a[2]);
    
    return 0;
}