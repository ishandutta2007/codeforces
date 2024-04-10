#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
int v[maxn];
struct Edge{int to,w,nxt;}e[2*maxn];
int cnt;
int head[maxn];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
void add(int u,int v,int w){
    e[cnt]=(Edge){v,w,head[u]};
    head[u]=cnt++;
    return ;
}
double calc(int x,int fa,int d){
    double sum=d*sqrt(d)*v[x];
    for(int i=head[x];i!=-1;i=e[i].nxt){
        int tmp=e[i].to;
        if(tmp==fa)continue;
        sum+=calc(tmp,x,d+e[i].w);
    }
    return sum;
}
bool vis[maxn];
int siz[maxn];
void dfs1(int x,int fa){
    siz[x]=1;
    for(int i=head[x];i!=-1;i=e[i].nxt){
        int tmp=e[i].to;
        if(vis[tmp]||tmp==fa)continue;
        dfs1(tmp,x);
        siz[x]+=siz[tmp];
    }
    return ;
}
int s,h;
void dfs2(int x,int fa){
    bool flag=1;
    for(int i=head[x];i!=-1;i=e[i].nxt){
        int tmp=e[i].to;
        if(vis[tmp]||tmp==fa)continue;
        dfs2(tmp,x);
        if(siz[tmp]>s-siz[tmp])flag=0;
    }
    if(flag&&s-siz[x]<=siz[x])h=x;
    return ;
}
double tot;
double p[maxn];
void dfs(int x,int fa,int d,int c){
    double val=1.5*v[x]*sqrt(d);
    tot+=val;p[c]+=val;
    for(int i=head[x];i!=-1;i=e[i].nxt){
        int tmp=e[i].to;
        if(tmp==fa)continue;
        dfs(tmp,x,d+e[i].w,c);
    }
    return ;
}
int pos;
double res=4e21;
void chk(double v){if(v<res)res=v,pos=h;return ;}
void solve(int x){
    dfs1(x,0);s=siz[x],dfs2(x,0);
    chk(calc(h,0,0));
    vis[h]=1;
    tot=0;
    for(int i=head[h];i!=-1;i=e[i].nxt){
        int tmp=e[i].to;
        if(vis[tmp])continue;
        p[tmp]=0,dfs(tmp,h,e[i].w,tmp);
    }
    for(int i=head[h];i!=-1;i=e[i].nxt){
        int tmp=e[i].to;
        if(vis[tmp])continue;
        if(tot-2*p[tmp]<0){solve(tmp);return ;}
    }
    return ;
}
int main(){
    int n;
    n=read();
    for(int i=1;i<=n;i++)v[i]=read();
    memset(head,-1,sizeof(head));
    for(int i=1;i<n;i++){
        int u,v,l;
        u=read();v=read();l=read();
        add(u,v,l),add(v,u,l);
    }
    solve(1);
    printf("%d %.7lf",pos,res);
    return 0;
}