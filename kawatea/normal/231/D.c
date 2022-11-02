#include <stdio.h>

int main()
{
    int x, y, z, x1, y1, z1, sum = 0, i;
    int a[6];
    
    scanf("%d %d %d", &x, &y, &z);
    scanf("%d %d %d", &x1, &y1, &z1);
    
    for (i = 0; i < 6; i++) scanf("%d", &a[i]);
    
    if (y < 0) sum += a[0];
    if (y > y1) sum += a[1];
    if (z < 0) sum += a[2];
    if (z > z1) sum += a[3];
    if (x < 0) sum += a[4];
    if (x > x1) sum += a[5];
    
    printf("%d\n", sum);
    
    return 0;
}