#include <stdio.h>

int main()
{
    int a,b,c,d;
    scanf("%d%d%d",&a,&b,&c);
    if((a+b+c)%2==1)
    {
        printf("Impossible");
        return 0;
    }
    d=(a+b+c)/2;
    if(d-a<0||d-b<0||d-c<0) printf("Impossible");
    else printf("%d %d %d",d-c,d-a,d-b);
}