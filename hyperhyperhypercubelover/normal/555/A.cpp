#include<cstdio>

int x[111111];

int main()
{
    int i,n,m,r,t,tt;
    scanf("%d%d",&n,&m);
    r=n+n-m-1;
    for(i=0;i<m;i++)
    {
        scanf("%d",&t);
        while(t--)
        {
            scanf("%d",&tt);
            x[tt]=i;
        }
    }
    for(i=2;i<=n;i++)
    {
        if(x[i]!=x[i-1])break;
        r-=2;
    }
    printf("%d",r);
}