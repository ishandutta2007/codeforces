#include<cstring>
#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstdlib>
using namespace std;
#define inf 1000000000
int n;
int g[205][205];
int d[205][205];

struct po{
    int x,y;
}p[205],q[205];
int cmp(const po&a,const po&b){
    return a.x<b.x;
}

int work(int i,int j){
    for (int t=1;t<=n;t++){
        p[t]=(po){g[i][j]+d[j][t]-d[i][t],g[i][j]+d[j][t]+d[i][t]};
        if(p[t].x<0)p[t].y+=p[t].x,p[t].x=0;
        else if(p[t].x>2*g[i][j])p[t].y-=p[t].x-2*g[i][j],p[t].x=2*g[i][j];
    }
    sort(p+1,p+1+n,cmp);
    int top=0;
    for (int t=1;t<=n;t++){
        while(top && p[t].y-q[top-1].y>=p[t].x-q[top-1].x)top--;
        if(top && q[top-1].y-p[t].y>=p[t].x-q[top-1].x)continue;
        q[top++]=p[t];
    }
    int ans;
    ans=min(q[0].y-q[0].x,q[top-1].y-(2*g[i][j]-q[top-1].x));
    for (int t=1;t<top;t++)
        ans=min(ans,(q[t-1].x-q[t].x+q[t-1].y+q[t].y)>>1);
    return ans;
}
int main()
{
    int m;
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)for (int j=1;j<=n;j++)g[i][j]=d[i][j]=inf;
    for (int i=1;i<=n;i++)d[i][i]=0;
    while(m--){
        int x,y,w;scanf("%d%d%d",&x,&y,&w);
        g[x][y]=g[y][x]=d[x][y]=d[y][x]=w;
    }
    for (int k=1;k<=n;k++)
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)if(d[i][j]>d[i][k]+d[k][j])d[i][j]=d[i][k]+d[k][j];
    int ans=inf;
    for (int i=1;i<=n;i++)
        for (int j=i+1;j<=n;j++)if(g[i][j]<inf){
            ans=min(ans,work(i,j));
        }
    printf("%.1lf\n",ans/2.0);
    return 0;
}