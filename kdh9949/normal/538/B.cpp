#include <stdio.h>
int n,i,j,k,m,qwer[101000],asdf[99999];
int t[1001001][2];
int dig(int n)
{
    while(n)
    {
        if(n%10>1)return 0;
        n/=10;
    }
    return 1;
}
int main()
{
    scanf("%d",&n);
    for(i=1;i<=1000000;i++)
    {
        if(dig(i))asdf[j++]=i;
        t[i][0]=987654321;
    }
    for(i=1;i<=n;i++)
    {
        for(k=0;k<j;k++)
        {
            if(i-asdf[k]>=0)
            {
                if(t[i][0]>t[i-asdf[k]][0]+1)
                t[i][0]=t[i-asdf[k]][0]+1,t[i][1]=asdf[k];
            }
        }
    }
    printf("%d\n",t[n][0]);
    for(i=n;i;)
    {
        printf("%d ",t[i][1]);
        i-=t[i][1];
    }
    return 0;
}