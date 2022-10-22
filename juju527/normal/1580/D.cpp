#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=4005;
const ll inf=0x3f3f3f3f3f3f3f3f;
int n,m;
ll a[maxn];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
struct Edge{int to,nxt;}e[2*maxn];
int cnt;
int head[maxn];
void add(int u,int v){
    e[cnt]=(Edge){v,head[u]};
    head[u]=cnt++;
    return ;
}
int solve(int l,int r){
    if(l>r)return 0;
    int pos=0;
    for(int i=l;i<=r;i++)if(a[i]<a[pos])pos=i;
    add(pos,solve(l,pos-1));
    add(pos,solve(pos+1,r));
    return pos;
}
int siz[maxn];
ll f[maxn][maxn],g[maxn];
void dfs(int x,int fa){
    siz[x]=1;
    f[x][0]=0,f[x][1]=1ll*(m-1)*a[x];
    for(int i=head[x];i!=-1;i=e[i].nxt){
        int tmp=e[i].to;
        if(!tmp)continue;
        dfs(tmp,x);
        for(int j=0;j<=siz[x];j++)
            for(int k=0;k<=siz[tmp];k++)
                g[j+k]=max(g[j+k],f[x][j]+f[tmp][k]-2ll*j*k*a[x]);
        siz[x]+=siz[tmp];
        for(int j=0;j<=siz[x];j++)f[x][j]=g[j],g[j]=-inf;
    }
    return ;
}
int main(){
    n=read();m=read();
    for(int i=1;i<=n;i++)a[i]=read();
    a[0]=inf;
    for(int i=0;i<=n;i++)head[i]=-1;
    for(int i=0;i<=n;i++)g[i]=-inf;
    int rt=solve(1,n);
    dfs(rt,0);
    printf("%lld\n",f[rt][m]);
    return 0;
}