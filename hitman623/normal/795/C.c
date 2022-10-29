#include <stdio.h>
#include <stdlib.h>

int main()
{
    long n,i;
    scanf("%d",&n);
    if(n%2==1) printf("7");
    for(i=0;i<n/2-(n%2);++i)
    printf("1");
    return 0;
}