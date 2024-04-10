#include<stdio.h>
int main()
{
    int ans=0,n;
    scanf("%d",&n);
    for(int i=1;i<n;i++)
    {
        int a;
        scanf("%d",&a);
        ans^=a^i;
    }
    printf("%d\n",ans^n);
    return 0;
}