#include <stdio.h>
int main()
{
    int n, i, number, flag;
    long a, min = 1000000001;
    
    scanf("%d", &n);
    for(i = 0; i < n; i += 1)
    {
        scanf("%ld", &a);
        if(a < min)
        {
            min = a;
            number = i + 1;
            flag = 1;
        }
        else if(a == min)
        {
            flag = 0;
        }
    }
    if(flag)
        printf("%d\n", number);
    else
        printf("Still Rozdil\n");

    return 0;
}