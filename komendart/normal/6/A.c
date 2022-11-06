#include <stdio.h>
main()
{
    int l[4], i, temp;
    scanf("%d%d%d%d", &l[0], &l[1], &l[2], &l[3]);
    for(i = 0; i < 3; i += 1)
    {
        if(l[i] > l[i + 1])
        {
            temp = l[i];
            l[i] = l[i + 1];
            l[i + 1] = temp;
            i = -1;
        }
    }
    if(l[1] + l[2] > l[3] || l[0] + l[1] > l[2])
        printf("TRIANGLE\n");
    else if(l[1] + l[2] == l[3] || l[0] + l[1] == l[2])
        printf("SEGMENT\n");
    else
        printf("IMPOSSIBLE\n");
}