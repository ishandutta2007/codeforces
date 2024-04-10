#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)
mt19937 Rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
template<typename T>void chkmax(T&x,T y){if(x<y)x=y;}
template<typename T>void chkmin(T&x,T y){if(x>y)x=y;}
inline int read() {
  #define nc getchar()
  int x=0;char c=nc;
  while(c<48)c=nc;
  while(c>47)x=x*10+(c^48),c=nc;
  return x;
  #undef nc
}

typedef double db;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
const int maxn=2e5+10;
int n,m,par[maxn],ans[maxn];
struct edge{
  int u,v,w,tid;bool ont;
}EE[maxn];
vi E[maxn],eid[maxn];

namespace zzh{
#define mid ((l + r) >> 1)
int pos,tot,rt[maxn];
struct node {
	int l, r, fa, rk;
} tree[maxn * 40];
void build(int& k, int l, int r) {
	k = ++tot;if (l == r) { tree[k].fa = l; return; }build(tree[k].l, l, mid), build(tree[k].r, mid + 1, r);
}
node get(int x) {
	int k = rt[pos], l = 1, r = n;
	while (l < r) {
		if (x <= mid) {
			k = tree[k].l, r = mid;
		} else {
			k = tree[k].r, l = mid + 1;
		}
	}
	return tree[k];
}
node& upd(int x) {
	int k, o = rt[pos], l = 1, r = n;
	tree[k = rt[pos] = ++tot] = tree[o];
	while (l < r) {
		if (x <= mid) {
			k = tree[k].l = ++tot, o = tree[o].l, r = mid;
		} else {
			k = tree[k].r = ++tot, o = tree[o].r, l = mid + 1;
		}
		tree[k] = tree[o];
	}
	return tree[k];
}
node find(int x) {
	node t = get(x);
	while (t.fa != x) t = get(x = t.fa);
	return t;
}
void unite(int x, int y) {
	node fx = find(x), fy = find(y);
	if (fx.fa != fy.fa) {
		if (fx.rk < fy.rk) swap(x, y), swap(fx, fy);
		upd(fy.fa).fa = fx.fa; if (fx.rk == fy.rk) upd(fx.fa).rk++;
	}
}
void adde(int u,int v,int de){
  if(!pos)build(rt[0],1,n);
  pos+=de,rt[pos]=rt[pos-de],unite(u,v);
}
int query(int u,int v){
  int l=1,r=pos,tmp=pos;
  while(l<r){
    pos=mid;
    find(u).fa==find(v).fa?r=mid:l=mid+1;
  }
  pos=tmp;
  return l;
}
#undef mid
}

int find(int x){
  return par[x]==x?x:par[x]=find(par[x]);
}

namespace lsj{

int sz[maxn], fa[maxn], son[maxn], dep[maxn], top[maxn];

void dfs1(int u, int f) {
  fa[u] = f, sz[u] = 1, dep[u] = dep[f] + 1;
  for (int v : E[u]) if (v != f) {
    dfs1(v, u), sz[u] += sz[v];
    if (sz[son[u]] < sz[v]) son[u] = v;
  }
}

void dfs2(int u, int tp) {
  top[u] = tp;
  if (son[u]) dfs2(son[u], tp);
  for (int v : E[u]) if (v != fa[u] && v != son[u]) dfs2(v, v);
}

int query_lca(int u, int v) {
  for (; top[u] != top[v]; u = fa[top[u]]) {
    if (dep[top[u]] < dep[top[v]]) swap(u, v);
  }
  return dep[u] < dep[v] ? u : v;
}

}

vi V1[maxn],V2[maxn];
multiset<int>S[maxn];

void DFS(int u,int f){
  int id=-1;
  for(int i=0;i<(int)E[u].size();i++){
    int v=E[u][i];
    if(v!=f){
      DFS(v,u);
      if(S[u].size()<S[v].size())swap(S[u],S[v]);
      for(int x:S[v])S[u].insert(x);
      S[v].clear();
    }else id=i;
  }
  for(int x:V1[u])S[u].insert(x);
  for(int x:V2[u])S[u].erase(S[u].find(x)),S[u].erase(S[u].find(x));
  if(!f)return;
  id=eid[u][id];
  if(S[u].empty()){
    ans[id]=-1;
  }else{
    ans[id]=*S[u].begin()-1;
  }
}

void solve() {
  cin>>n>>m;
  rep(i,1,m){
    EE[i].u=read(),EE[i].v=read(),EE[i].w=read(),EE[i].tid=i;
  }
  sort(EE+1,EE+m+1,[](edge P,edge Q){
    return P.w<Q.w;
  });
  rep(i,1,n)par[i]=i;
  static int ev[maxn];int ec=0,ccccc=0;
  rep(i,1,m){
    int j=i;
    while(j<m&&EE[j+1].w==EE[i].w)j++;
    bool flg=1;
    rep(k,i,j){
      int u=EE[k].u,v=EE[k].v;
      if(find(u)!=find(v)){
//        printf("(%d %d %d)\n",u,v,EE[k].w);
        zzh::adde(u,v,flg),flg=0,ccccc++;
        par[find(u)]=find(v),EE[k].ont=1,E[u].push_back(v),E[v].push_back(u),eid[u].push_back(EE[k].tid),eid[v].push_back(EE[k].tid);
      }
    }
    if(!flg)ev[++ec]=EE[i].w;
    i=j;
  }
  if(ccccc<n-1)return puts("GG"),void();
  lsj::dfs1(1,0),lsj::dfs2(1,1);
  rep(i,1,m)if(!EE[i].ont){
    int u=EE[i].u,v=EE[i].v;
    int tim=zzh::query(u,v);
    ans[EE[i].tid]=ev[tim]-1;
    int anc=lsj::query_lca(u,v);
    V1[u].push_back(EE[i].w),V1[v].push_back(EE[i].w),V2[anc].push_back(EE[i].w);
  }
  DFS(1,0);
  rep(i,1,m)printf("%d%c",ans[i],"\n "[i<m]);
}

signed main() {
//  int T=read();
//  while(T--)solve();
  solve();
  return 0;
}