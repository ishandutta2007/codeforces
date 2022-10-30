#include <stdio.h>
#include <math.h>

int main()
{
    int r, h, x, ans;
    double sum;
    
    scanf("%d %d", &r, &h);
    
    x = (r / 2.0 + h) / r;
    
    ans = x * 2;
    sum = x * r;
    
    if (sum + sqrt(3) * r / 2 <= r + h) ans++;
    
    printf("%d\n", ans);
    
    return 0;
}