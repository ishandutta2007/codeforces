#include <stdio.h>
int main()
{
    int t, count = 0;
    while((t = getchar()) != '\n')
        count += (t == '4' || t == '7');
    if(count == 4 || count == 7)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}