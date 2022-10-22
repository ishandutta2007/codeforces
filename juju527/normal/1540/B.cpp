#include<bits/stdc++.h>
using namespace std;
const int maxn=205,mod=1e9+7,iv2=5e8+4;
struct Edge{int to,nxt;}e[2*maxn];
int cnt;
int head[maxn];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
inline int add(int x){return x>=mod?x-mod:x;}
inline int power(int x,int b){
    int res=1;
    while(b){
        if(b&1)res=1ll*res*x%mod;
        x=1ll*x*x%mod;
        b>>=1;
    }
    return res;
}
void add(int u,int v){
    e[cnt]=(Edge){v,head[u]};
    head[u]=cnt++;
    return ;
}
int dep[maxn];
int p[maxn][8];
void dfs(int x,int fa){
    dep[x]=dep[fa]+1;
    p[x][0]=fa;
    for(int i=1;i<8;i++)p[x][i]=p[p[x][i-1]][i-1];
    for(int i=head[x];i!=-1;i=e[i].nxt){
        int tmp=e[i].to;
        if(tmp==fa)continue;
        dfs(tmp,x);
    }
    return ;
}
int lca(int x,int y){
    if(dep[x]<dep[y])swap(x,y);
    for(int i=7;i>=0;i--)if(dep[p[x][i]]>=dep[y])x=p[x][i];
    if(x==y)return x;
    for(int i=7;i>=0;i--)if(p[x][i]^p[y][i])x=p[x][i],y=p[y][i];
    return p[x][0];
}
int f[maxn][maxn];
int main(){
    int n;
    n=read();
    memset(head,-1,sizeof(head));
    for(int i=1;i<n;i++){
        int u,v;
        u=read();v=read();
        add(u,v),add(v,u);
    }
    for(int i=1;i<=n;i++)f[0][i]=1;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            f[i][j]=1ll*iv2*add(f[i-1][j]+f[i][j-1])%mod;
    int res=0;
    for(int i=1;i<=n;i++){
        dfs(i,0);
        for(int j=1;j<=n;j++){
            for(int k=1;k<j;k++){
                int a=lca(j,k);
                res=add(res+f[dep[j]-dep[a]][dep[k]-dep[a]]);
            }
        }
    }
    printf("%d\n",1ll*res*power(n,mod-2)%mod);
    return 0;
}