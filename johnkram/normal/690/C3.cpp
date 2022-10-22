#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
#define MAXN 200005
int d[MAXN],f[MAXN][20],n,i,j,x,y,z,z1,z2;
int LCA(int x,int y)
{
    int i,j;
    if(d[x]>d[y])x^=y^=x^=y;
    if(d[x]!=d[y])for(i=19;i>=0;i--)if(d[y]-d[x]>>i&1)y=f[y][i];
    if(x!=y)
    {
        for(i=19;i>=0;i--)if(f[x][i]!=f[y][i])
        {
            x=f[x][i];
            y=f[y][i];
        }
        x=f[x][0];
    }
    return x;
}
int dis(int x,int y)
{
    return d[x]+d[y]-2*d[LCA(x,y)];
}
int main()
{
    scanf("%d",&n);
    for(x=y=1,i=2;i<=n;i++)
    {
        scanf("%d",f[i]);
        d[i]=d[f[i][0]]+1;
        for(j=1;j<20;j++)f[i][j]=f[f[i][j-1]][j-1];
        z1=dis(i,x);
        z2=dis(i,y);
        if(max(z1,z2)>z)if(z1>z2)
        {
            y=i;
            z=z1;
        }
        else
        {
            x=i;
            z=z2;
        }
        printf("%d ",z);
    }
    return 0;
}