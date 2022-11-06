#include <stdio.h>
int main()
{
    int n, i;
    scanf("%d", &n);
    int max_i = 0, min_i = 0, max = 0, min = 101;
    for(i = 0; i < n; i += 1)
    {
        int a;
        scanf("%d", &a);
        if(a <= min)
        {
            min = a;
            min_i = i;
        }
        if(a > max)
        {
            max = a;
            max_i = i;
        }
    }
    printf("%d\n", max_i + n - (min_i + 1) - (max_i > min_i));
    return 0;
}