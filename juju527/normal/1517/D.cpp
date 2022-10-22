#include<bits/stdc++.h>
using namespace std;
const int maxn=505;
int n,m;
int a[maxn][maxn],b[maxn][maxn];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
struct node{
    int x,y,d;
};
queue<node>q;
bool vis[maxn][maxn];
int dis[maxn][maxn];
int dijkstra(int sx,int sy,int k){
    q.push((node){sx,sy,0});dis[sx][sy]=0;vis[sx][sy]=0;
    int res=0x3f3f3f3f;
    while(!q.empty()){
        int x=q.front().x,y=q.front().y,d=q.front().d;
        vis[x][y]=0;
        q.pop();
        if(d==k)res=min(res,dis[x][y]);
        if(y<m&&d<k){
            dis[x][y+1]=min(dis[x][y+1],dis[x][y]+a[x][y]);
            if(!vis[x][y+1])q.push((node){x,y+1,d+1}),vis[x][y+1]=1;
        }
        if(y>1&&d<k){
            dis[x][y-1]=min(dis[x][y-1],dis[x][y]+a[x][y-1]);
            if(!vis[x][y-1])q.push((node){x,y-1,d+1}),vis[x][y-1]=1;
        }
        if(x<n&&d<k){
            dis[x+1][y]=min(dis[x+1][y],dis[x][y]+b[x][y]);
            if(!vis[x+1][y])q.push((node){x+1,y,d+1}),vis[x+1][y]=1;
        }
        if(x>1&&d<k){
            dis[x-1][y]=min(dis[x-1][y],dis[x][y]+b[x-1][y]);
            if(!vis[x-1][y])q.push((node){x-1,y,d+1}),vis[x-1][y]=1;
        }
        dis[x][y]=0x3f3f3f3f;
    }
    return res;
}
int main(){
    int k;
    n=read();m=read();k=read();
    for(int i=1;i<=n;i++)for(int j=1;j<m;j++)a[i][j]=read();
    for(int i=1;i<n;i++)for(int j=1;j<=m;j++)b[i][j]=read();
    if(k&1){
        for(int i=1;i<=n;i++,printf("\n"))for(int j=1;j<=m;j++)printf("-1 ");
        return 0;
    }
    k/=2;
    memset(dis,0x3f,sizeof(dis));
    for(int i=1;i<=n;i++,puts(""))
        for(int j=1;j<=m;j++)
            printf("%d ",2*dijkstra(i,j,k));
    return 0;
}