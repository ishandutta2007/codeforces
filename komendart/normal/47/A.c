#include <stdio.h>
main()
{
    int n, i = 1, x = 1;
    scanf("%d", &n);
    while(x < n)
    {
        x = i * (i + 1) / 2;
        i += 1;
    }
    if(x == n)
        printf("YES\n");
    else
        printf("NO\n");
}