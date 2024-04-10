#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=2e5+5,maxm=2e5+5;
struct Edge{
    int to,w,nxt;
}e1[maxm],e2[maxm];
int cnt1,cnt2;
int head1[maxn],head2[maxn];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
void add1(int u,int v,int w){
    e1[cnt1]=(Edge){v,w,head1[u]};
    head1[u]=cnt1++;
    return ;
}
void add2(int u,int v,int w){
    e2[cnt2]=(Edge){v,w,head2[u]};
    head2[u]=cnt2++;
    return ;
}
int dfsnum,scc;
int b[maxn];
int dfn[maxn],low[maxn];
bool vis[maxn];
stack<int>s;
void tarjan(int x){
    dfn[x]=low[x]=++dfsnum;
    vis[x]=1;s.push(x);
    for(int i=head1[x];i!=-1;i=e1[i].nxt){
        int tmp=e1[i].to;
        if(!dfn[tmp]){tarjan(tmp);low[x]=min(low[x],low[tmp]);}
        else if(vis[tmp])low[x]=min(low[x],dfn[tmp]);
    }
    if(dfn[x]==low[x]){
        scc++;
        while(s.top()^x){b[s.top()]=scc;vis[s.top()]=0;s.pop();}
        b[x]=scc;vis[x]=0;s.pop();
    }
    return ;
}
ll p[maxn],q[maxn];
ll res[maxn];
void dfs1(int x){
    vis[x]=1;
    for(int i=head1[x];i!=-1;i=e1[i].nxt){
        int tmp=e1[i].to;
        if(vis[tmp]||b[tmp]!=b[x])continue;
        p[tmp]=p[x]+e1[i].w;
        dfs1(tmp);
    }
    return ;
}
void dfs2(int x){
    vis[x]=1;
    for(int i=head2[x];i!=-1;i=e2[i].nxt){
        int tmp=e2[i].to;
        if(vis[tmp]||b[tmp]!=b[x])continue;
        q[tmp]=q[x]+e2[i].w;
        dfs2(tmp);
    }
    return ;
}
ll gcd(ll x,ll y){
    return y==0?x:gcd(y,x%y);
}
int main(){
    int n,m,Q;
    n=read();m=read();
    memset(head1,-1,sizeof(head1));
    memset(head2,-1,sizeof(head2));
    for(int i=1;i<=m;i++){
        int u,v,w;
        u=read();v=read();w=read();
        add1(u,v,w);
        add2(v,u,w);
    }
    for(int i=1;i<=n;i++)if(!dfn[i])tarjan(i);
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=n;i++)if(!vis[i])dfs1(i);
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=n;i++)if(!vis[i])dfs2(i);
    for(int i=1;i<=n;i++){
        for(int j=head1[i];j!=-1;j=e1[j].nxt){
            int tmp=e1[j].to;
            if(b[tmp]^b[i])continue;
            res[b[i]]=gcd(res[b[i]],p[i]+e1[j].w+q[tmp]);
        }
    }
    Q=read();
    for(int i=1;i<=Q;i++){
        int x,s,t;
        x=read();s=read();t=read();
        if(s%gcd(res[b[x]],t))puts("NO");
        else puts("YES");
    }
    return 0;
}