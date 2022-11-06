#include <stdio.h>
int main()
{
    int n, k, i, number = 0;
    char string[300000];
    
    scanf("%d%d%s", &n, &k, string);
    
    for(i = 0; i < n; i += 1)
    {
        if(string[i] == '.')
            number = 0;
        else
            number += 1;
        if(number == k)
        {
            printf("NO\n");
            return 0;
        }
    }
    
    printf("YES\n");
    
    return 0;
}