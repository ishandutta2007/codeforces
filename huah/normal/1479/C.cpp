#include<bits/stdc++.h>
using namespace std;
const int N=35;
int l,r,f[N],n,m,dis[N][N];
void sol(int x)
{
    dis[1][2]=1;
    f[1]=0;f[2]=1;
    n=2;
    int now=1;
    while(now*2<=x)
    {
        for(int i=1;i<=n;i++)
            if(dis[i][n])
            dis[i][n+1]=dis[i][n];
        dis[n][n+1]=now;
        now*=2;
        n++;
        f[n]=now;
    }
    if(x>now)
    {
        n++;
        for(int i=n-1;i>=1;i--)
            if(x>f[i])
        {
            dis[i][n]=x-f[i];
            x-=f[i];
            if(i==1) assert(x==1);
        }
    }
}
int main()
{
    scanf("%d%d",&l,&r);
    n=m=0;memset(dis,0,sizeof(dis));
    memset(f,0,sizeof(f));
    printf("YES\n");
    sol(r-l+1);
    if(l>1) dis[n][n+1]=l-1,n++;
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
        if(dis[i][j])
            m++;
    printf("%d %d\n",n,m);
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
        if(dis[i][j])
            printf("%d %d %d\n",i,j,dis[i][j]);
}