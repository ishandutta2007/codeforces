#include<bits/stdc++.h>
using namespace std;
#define ll long long
int rd(){
    int a=0;char ch=getchar();
    while(!isdigit(ch))ch=getchar();
    while(isdigit(ch))a=(a<<1)+(a<<3)+(ch^48),ch=getchar();
    return a;
}
ll rdll(){
    ll a=0;char ch=getchar();
    while(!isdigit(ch))ch=getchar();
    while(isdigit(ch))a=(a<<1)+(a<<3)+(ch^48),ch=getchar();
    return a;
}

const int N=500005;
const ll inf=1000000000000000ll;
int n,q,cnt,st[N],ed[N];
vector<int>e[N],f[N],ql[N],qr[N],qi[N];
ll d[N],tre[N<<2],lazy[N<<2],ans[N],D;
void dfs(int v,int fa,ll dep){
    if(e[v].size())d[v]=inf;else d[v]=dep;
    st[v]=++cnt;
    for(int i=0;i<(int)e[v].size();i++)dfs(e[v][i],v,dep+f[v][i]);
    ed[v]=  cnt;
}
void in();
#define mid ((l+r)>>1)
#define ls o<<1,l,mid
#define rs o<<1|1,mid+1,r
void pu(int o){tre[o]=min(tre[o<<1],tre[o<<1|1]);}
void pt(int o,ll v){tre[o]+=v,lazy[o]+=v;}
void pd(int o){pt(o<<1,lazy[o]),pt(o<<1|1,lazy[o]),lazy[o]=0;}
void build(int o,int l,int r){
    if(l==r){tre[o]=d[l];return;}
    build(ls),build(rs),pu(o);
}
void add(int o,int l,int r,int L,int R,ll v){
    if(r<L||R<l)return;
    if(L<=l&&r<=R){pt(o,v);return;}
    pd(o),add(ls,L,R,v),add(rs,L,R,v),pu(o);
}
ll query(int o,int l,int r,int L,int R){
    if(r<L||R<l)return inf;
    if(L<=l&&r<=R)return tre[o];
    pd(o);return min(query(ls,L,R),query(rs,L,R));
}
void solve(int v,int fa,int la){
    D+=la,add(1,1,n,st[v],ed[v],-la-la);
    for(int i=0;i<(int)qi[v].size();i++)ans[qi[v][i]]=D+query(1,1,n,ql[v][i],qr[v][i]);
    for(int i=0;i<(int)e[v].size();i++)solve(e[v][i],v,f[v][i]);
    D-=la,add(1,1,n,st[v],ed[v], la+la);
}
int main(){
	in();
	dfs(1,0,0);
	build(1,1,n);
	solve(1,0,0);
	for(int i=1;i<=q;i++)printf("%I64d\n",ans[i]);
	return 0;
}
void in(){
	n=rd(),q=rd();
	for(int i=2;i<=n;i++){
	    int x=rd(),y=rd();
	    e[x].push_back(i);
	    f[x].push_back(y);
	}
	for(int i=1;i<=q;i++){
	    int x=rd(),y=rd(),z=rd();
	    ql[x].push_back(y);
	    qr[x].push_back(z);
	    qi[x].push_back(i);
	}
}