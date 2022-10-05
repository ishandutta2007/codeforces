#include<stdio.h>
int a[111][111],i,j,k,n,m,chk[111];
int main()
{
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(a[i][j]==1 || a[i][j]==3){k--;chk[i]=1;break;}
        }
        k++;
    }
    printf("%d\n",k);
    for(i=0;i<n;i++)
    {
        if(chk[i])continue;
        printf("%d ",i+1);
    }
}