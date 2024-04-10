#include<stdio.h>
#include<algorithm>
int a[1111],i,j,k,n;
int main()
{
    scanf("%d",&n);
    for(i=0;i<n;i++)scanf("%d",a+i);
    std::sort(a,a+n);
    if(a[0]==1){puts("-1");return 0;}
    printf("1");
}