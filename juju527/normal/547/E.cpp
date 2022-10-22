#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;
const int maxn=2e5+5,maxq=5e5+5;
char s[maxn];
vector<int> p[maxn];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
int tot;
int to[maxn][26],fail[maxn];
struct Edge{int to,nxt;}e[maxn];
int cnt,head[maxn];
int dfsnum,dfn[maxn],siz[maxn];
void add(int u,int v){
    e[cnt]=(Edge){v,head[u]};
    head[u]=cnt++;
    return ;
}
void dfs(int x){
    siz[x]=1;dfn[x]=++dfsnum;
    for(int i=head[x];i!=-1;i=e[i].nxt){
        int tmp=e[i].to;
        dfs(tmp);
        siz[x]+=siz[tmp];
    }
    return ;
}
queue<int> qq;
void build(){
    for(int i=0;i<26;i++)if(to[0][i])qq.push(to[0][i]);
    while(qq.size()){
        int k=qq.front();
        qq.pop();
        for(int i=0;i<26;i++){
            int tmp=to[k][i];
            if(!tmp)to[k][i]=to[fail[k]][i];
            else fail[tmp]=to[fail[k]][i],qq.push(tmp);
        }
    }
    memset(head,-1,sizeof(head));
    for(int i=1;i<=tot;i++)add(fail[i],i);
    return ;
}
int lowbit[maxn];
ll t[maxn];
void update(int x){while(x<=tot+1)t[x]++,x+=lowbit[x];return ;}
ll query(int x){ll res=0;while(x)res+=t[x],x-=lowbit[x];return res;}
vector<pair<int,int>> q[maxn];
ll res[maxq];
int main(){
    int n,Q;
    n=read();Q=read();
    for(int i=1;i<=n;i++){
        scanf("%s",s);
        int k=0,len=strlen(s);
        for(int j=0;j<len;j++){
            int c=s[j]-'a';
            if(!to[k][c])to[k][c]=++tot;
            k=to[k][c];
            p[i].push_back(k);
        }
    }
    build();
    dfs(0);
    for(int i=1;i<=Q;i++){
        int l,r,k;
        l=read();r=read();k=read();
        q[l-1].push_back(make_pair(k,-i));
        q[r].push_back(make_pair(k,i));
    }
    for(int i=1;i<=tot+1;i++)lowbit[i]=i&-i;
    for(int i=1;i<=n;i++){
        for(int j=0;j<p[i].size();j++)update(dfn[p[i][j]]);
        for(int j=0;j<q[i].size();j++){
            int x=p[q[i][j].fi][p[q[i][j].fi].size()-1];
            ll op=q[i][j].se/abs(q[i][j].se);
            res[abs(q[i][j].se)]+=op*(query(dfn[x]+siz[x]-1)-query(dfn[x]-1));
        }
    }
    for(int i=1;i<=Q;i++)printf("%lld\n",res[i]);
    return 0;
}