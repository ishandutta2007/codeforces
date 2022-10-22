#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5,maxm=1e5+5;
struct Edge{
    int to,nxt;
}e[4*maxn];
int cnt;
int head[2*maxn];
int n,m,q;
int w[maxn];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
void add(int u,int v){
    e[cnt].to=v;
    e[cnt].nxt=head[u];
    head[u]=cnt++;
    return ;
}
int dfsnum,block;
int dfn[2*maxn],low[maxn];
stack<int>s;
vector<int>to[2*maxn];
void tarjan(int x){
    dfn[x]=low[x]=++dfsnum;
    s.push(x);
    for(int i=head[x];i!=-1;i=e[i].nxt){
        int tmp=e[i].to;
        if(!dfn[tmp]){
            tarjan(tmp);
            low[x]=min(low[x],low[tmp]);
            if(low[tmp]==dfn[x]){
                block++;
                int p=0;
                while(p^tmp){
                    p=s.top();
                    to[block].push_back(p);
                    to[p].push_back(block);
                    s.pop();
                }
                to[block].push_back(x);
                to[x].push_back(block);
            }
        }
        else
            low[x]=min(low[x],dfn[tmp]);
    }
    return ;
}
int f[2*maxn];
int num[2*maxn],siz[2*maxn],hson[2*maxn];
int dep[2*maxn];
int top[2*maxn];
multiset<int>st[2*maxn];
void dfs1(int x,int fa){
    siz[x]=1;
    f[x]=fa;
    dep[x]=dep[fa]+1;
    for(int i=head[x];i!=-1;i=e[i].nxt){
        int tmp=e[i].to;
        if(tmp==fa)continue;
        dfs1(tmp,x);
        siz[x]+=siz[tmp];
        if(siz[tmp]>siz[hson[x]])hson[x]=tmp;
        if(x>n)st[x].insert(w[tmp]);
    }
    return ;
}
void dfs2(int x,int tp){
    dfn[x]=++dfsnum;num[dfsnum]=x;
    top[x]=tp;
    if(hson[x])dfs2(hson[x],tp);
    for(int i=head[x];i!=-1;i=e[i].nxt){
        int tmp=e[i].to;
        if(tmp==f[x]||tmp==hson[x])continue;
        dfs2(tmp,tmp);
    }
    return ;
}
int mn[maxn<<3];
void build(int k,int l,int r){
    if(l==r){
        mn[k]=(*st[num[l]].begin());
        return ;
    }
    int mid=l+((r-l)>>1);
    build(k<<1,l,mid);
    build(k<<1|1,mid+1,r);
    mn[k]=min(mn[k<<1],mn[k<<1|1]);
    return ;
}
void modify(int k,int l,int r,int x){
    if(l>x||r<x)return ;
    if(l==r){
        mn[k]=(*st[num[l]].begin());
        return ;
    }
    int mid=l+((r-l)>>1);
    modify(k<<1,l,mid,x);
    modify(k<<1|1,mid+1,r,x);
    mn[k]=min(mn[k<<1],mn[k<<1|1]);
    return ;
}
int query(int k,int l,int r,int x,int y){
    if(l>y||r<x)return 1e9+5;
    if(l>=x&&r<=y)return mn[k];
    int mid=l+((r-l)>>1);
    return min(query(k<<1,l,mid,x,y),query(k<<1|1,mid+1,r,x,y));
}
int query_dist(int x,int y){
    int ans=1e9+5;
    while(top[x]^top[y]){
        if(dep[top[x]]<dep[top[y]])swap(x,y);
        ans=min(ans,query(1,1,block,dfn[top[x]],dfn[x]));
        x=f[top[x]];
    }
    if(dep[x]<dep[y])swap(x,y);
    ans=min(ans,query(1,1,block,dfn[y],dfn[x]));
    if(y>n)ans=min(ans,w[f[y]]);
    return ans;
}
int main(){
    n=read();m=read();q=read();
    for(int i=1;i<=n;i++)w[i]=read();
    memset(head,-1,sizeof(head));
    for(int i=1;i<=m;i++){
        int u,v;
        u=read();v=read();
        add(u,v);
        add(v,u);
    }
    block=n;
    tarjan(1);
    cnt=0;
    memset(head,-1,sizeof(head));
    for(int i=1;i<=block;i++){
        for(int j=0;j<to[i].size();j++){
            int tmp=to[i][j];
            add(i,tmp);
        }
    }
    for(int i=1;i<=block;i++)st[i].insert(1e9+5);
    for(int i=1;i<=n;i++)st[i].insert(w[i]);
    dfsnum=0;
    dfs1(1,0);
    dfs2(1,1);
    build(1,1,block);
    for(int i=1;i<=q;i++){
        char opt;
        int a,b;
        cin>>opt;
        a=read();b=read();
        if(opt=='C'){
            int pmn=*st[f[a]].begin();
            st[f[a]].erase(w[a]);st[f[a]].insert(b);
            st[a].erase(w[a]);st[a].insert(b);
            if(w[a]^b)modify(1,1,block,dfn[a]);
            w[a]=b;
            if((*st[f[a]].begin())!=pmn)modify(1,1,block,dfn[f[a]]);
        }
        else
            printf("%d\n",query_dist(a,b));
    }
    return 0;
}