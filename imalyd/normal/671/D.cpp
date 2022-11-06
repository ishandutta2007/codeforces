#include<bits/stdc++.h>
using namespace std;
void init();
#define ll long long
#define pb push_back
#define fo(i,v,e) for(int i=0;i<(int)e[v].size();i++)
const int N=300005;const ll inf=1e18;
int n,m,d[N],vis[N],dfn[N],la[N],c[N],L[N],R[N],xxx[N];
ll dp[N],sum[N],tre[N<<2],lazy[N<<2];
struct node{int s,t,v;}nod[N];
bool cmp(node a,node b){return dfn[a.s]<dfn[b.s];}
vector<int>e[N],S[N],E[N];
void inc(ll &a,ll b){a+=b;if(inf<a)a=inf;}
int add(ll a,ll b){a+=b;if(inf<a)a=inf;return a;}
int rd(){
    int a=0;char ch=getchar();
    while(!isdigit(ch))ch=getchar();
    while(isdigit(ch))a=(a<<1)+(a<<3)+(ch^48),ch=getchar();
    return a;
}
#define mid ((l+r)>>1)
void pu(int c){tre[c]=min(tre[c<<1],tre[c<<1|1]);}
void paint(ll v,int c){inc(tre[c],v),inc(lazy[c],v);}
void pd(int c){paint(lazy[c],c<<1);paint(lazy[c],c<<1|1);lazy[c]=0;}
void upd(int l,int r,int x,ll v,int c){
    if(l==r){tre[c]=v;return;}
    pd(c);
    if(x<=mid)upd(l,mid,x,v,c<<1);else upd(mid+1,r,x,v,c<<1|1);
    pu(c);
}
void add(int l,int r,int L,int R,ll v,int c){
    if(r<L||R<l)return;
    if(L<=l&&r<=R){paint(v,c);return;}
    pd(c);
    add(l,mid,L,R,v,c<<1);add(mid+1,r,L,R,v,c<<1|1);
    pu(c);
}
ll query(int l,int r,int L,int R,int c){
	if(r<L||R<l)return inf;
	if(L<=l&&r<=R)return tre[c];
	pd(c);
	return min(query(l,mid,L,R,c<<1),query(mid+1,r,L,R,c<<1|1));
}
void dfs(int v,int fa){
    fo(i,v,e){int u=e[v][i];if(u!=fa)dfs(u,v),inc(sum[v],dp[u]);}
    fo(i,v,S){int u=S[v][i];upd(1,m,u,sum[v]+c[u],1);}
    fo(i,v,E){int u=E[v][i];if(v!=1)upd(1,m,u,inf,1);}
    fo(i,v,e){int u=e[v][i];if(u!=fa&&L[u]<=R[u])add(1,m,L[u],R[u],sum[v]-dp[u],1);}
    if(L[v]<=R[v])dp[v]=query(1,m,L[v],R[v],1);else dp[v]=inf;
}
int main(){
    init();dfs(1,0);
	for(int i=1;i<=n;i++)if(inf<=dp[i]){printf("-1");return 0;}
	cout<<dp[1];
}
void dfs1(int v,int fa){
    dfn[v]=++dfn[0];
    for(int i=0;i<(int)e[v].size();i++){
        int u=e[v][i];
        if(u!=fa)dfs1(u,v);
    }
    la[v]=dfn[0];
}
void init(){
    scanf("%d%d",&n,&m);
    if(n==1){printf("0");exit(0);}
    for(int i=1;i<n;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        e[a].push_back(b),e[b].push_back(a);
    }
    for(int i=1;i<=m;i++){
        int a=rd(),b=rd(),c=rd();
        nod[i]=(node){a,b,c};
    }
    dfs1(1,0);
    sort(nod+1,nod+m+1,cmp);
    for(int i=1;i<=m;i++)S[nod[i].s].push_back(i),E[nod[i].t].push_back(i),c[i]=nod[i].v,xxx[i]=dfn[nod[i].s];
    for(int i=1;i<=n;i++){
        L[i]=lower_bound(xxx+1,xxx+m+1,dfn[i])-xxx;
        R[i]=upper_bound(xxx+1,xxx+m+1, la[i])-xxx-1;
    }
	for(int i=1;i<=m;i++)upd(1,m,i,inf,1);
}