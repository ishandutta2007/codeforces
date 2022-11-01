#include<bits/stdc++.h>
using namespace std;
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define nep(i,r,l) for(int i=r;i>=l;i--)
const int N=1005;
int n,m,k,a[N][N],f[N*N];
int id(int i,int j){return m*(i-1)+j;}
pair<int,int>pos(int x){return {(x-1)/m+1,(x-1)%m+1};}
int getf(int x){return f[x]==x?x:f[x]=getf(f[x]);}
void link(int x,int y)
{
    x=getf(x);y=getf(y);
    if(x<y) swap(x,y);
    f[y]=x;
}
int sol(int y)
{
    int x=1;
    // cout<<x<<' '<<y<<' '<<a[x][y]<<' '<<getf(id(x,y))<<' '<<'\n';
    while(x!=n+1)
    {
        if(a[x][y]==2)
        {
            pair<int,int>nex=pos(getf(id(x,y)));
            x=nex.first,y=nex.second;
            x++;
            continue;
        }
        else
        {
            int dy=0;
            if(a[x][y]==1) dy++;
            else dy--;
            a[x][y]=2;
            if(a[x-1][y]==2) link(id(x,y),id(x-1,y));
            if(a[x+1][y]==2) link(id(x,y),id(x+1,y));
            y+=dy;
        }
    }
    return y;
}
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        scanf("%d",&a[i][j]);
    rep(i,1,n*m) f[i]=i;
    rep(i,1,n-1)
        rep(j,1,m)
        if(a[i][j]==2&&a[i+1][j]==2)
            link(id(i,j),id(i+1,j));
    vector<int>ans;
    for(int i=1;i<=k;i++)
    {
        int x;scanf("%d",&x);
        ans.push_back(sol(x));
    }
    for(int i=1;i<=k;i++)
        printf(i==k?"%d\n":"%d ",ans[i-1]);
}