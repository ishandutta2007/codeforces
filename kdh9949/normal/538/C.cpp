#include<stdio.h>
#include<stdlib.h>
int a[100100][2],i,j,k,n,m,q,w=-987654321,e,r,mosoon;
int main()
{
    scanf("%d%d",&n,&m);
    for(i=0;i<m;i++)
    {
        scanf("%d%d",&a[i][0],&a[i][1]);
    }
    w=a[0][0]+a[0][1]-1;
    e=(n-a[m-1][0])+a[m-1][1];
    w=w>e?w:e;
    for(i=0;i<m-1;i++)
    {
        if(abs(a[i][0]-a[i+1][0])<abs(a[i][1]-a[i+1][1]))mosoon=1;
        q=(a[i][0]-a[i][1]+a[i+1][0]+a[i+1][1])/2-a[i][0]+a[i][1];
        w=q>w?q:w;
    }
    if(mosoon)printf("IMPOSSIBLE");
    else printf("%d",w);
}