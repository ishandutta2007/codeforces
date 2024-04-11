#include <stdio.h>
int main()
{
    int n, m, i, j;
    scanf("%d%d", &n, &m);
    long c[n], t[n], v[m];
    for(i = 0; i < n; i += 1)
        scanf("%ld%ld", c + i, t + i);
    for(i = 0; i < m; i += 1)
        scanf("%ld", v + i);

    long all_time = 0;
    for(i = 0, j = 0; j < m; i += 1)
    {
        all_time += c[i] * t[i];
        while(all_time >= v[j] && j < m)
        {
            printf("%d\n", i + 1);
            j += 1;
        }
    }
    return 0;
}