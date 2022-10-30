#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn = 300055;
int n, m, num, indexx, opt, tot;
int dep[maxn], in[maxn], top[maxn], siz[maxn], son[maxn], h[maxn], fa[maxn], seq[maxn], a[maxn];
struct edge{ int nxt, v;}e[maxn * 2];
inline void add(int u, int v){
	e[++num].v = v, e[num].nxt = h[u], h[u] = num;
	e[++num].v = u, e[num].nxt = h[v], h[v] = num;
}
struct node{
	node *ls, *rs;
	int sum, flag, ad;
	void pushdown(int lf, int rg){
		if(flag==2){
			int mid  = (lf + rg) >> 1;
			ls->sum  = ad;
			rs->sum  = ad;
			ls->flag = rs->flag = 2;
			ls->ad   = rs->ad   = ad;
			flag = 0, ad = 0;
		}
	}
	void update(){
		sum = max(ls->sum,rs->sum);
	}
}pool[maxn * 2], *tail = pool, *root;
node* build(int lf ,int rg){
	node *bt = ++tail;
	if(lf == rg) {bt->sum = 0; bt->ad = bt->flag = 0; return bt;}
	int mid = (lf + rg)>>1;
	bt->ls = build(lf, mid), bt->rs = build(mid + 1, rg);
	bt->ad = 0, bt->flag = 0, bt->update();
	return bt;
}
void modify(node *bt, int lf, int rg, int L, int R, int delta){
	if(L <= lf && rg <= R){
		bt->flag = 2, bt->sum = delta, bt->ad = delta;
		return;
	}
	int mid = (lf + rg)>>1;
	bt->pushdown(lf, rg);
	if(L <= mid) modify(bt->ls, lf, mid, L, R, delta);
	if(R > mid)  modify(bt->rs, mid + 1, rg , L, R, delta);
	bt->update();
	return;
}
int query(node *bt, int lf, int rg, int L, int R){
	if(L <= lf && rg <= R) return bt->sum;
	int mid = (lf + rg) >> 1, rt = 0;
	bt->pushdown(lf, rg);
	if(L <= mid)  rt = max(rt,query(bt->ls, lf, mid, L, R));
	if(R > mid) rt = max(rt,query(bt->rs, mid + 1, rg, L, R));
	bt->update();
	return rt;
}
void dfs1(int u){
	siz[u] = 1;
	for(int i = h[u]; i; i = e[i].nxt){
		int v = e[i].v;
		if(v == fa[u]) continue;
		fa[v] = u, dep[v] = dep[u] + 1;
		dfs1(v), siz[u] += siz[v];
		if(siz[v] > siz[son[u]]) son[u] = v;
	}
}
void dfs2(int u, int tp){
	top[u] = tp;
	in[u] = ++indexx; seq[indexx] = u;
	if(son[u]) dfs2(son[u], tp);
	for(int i = h[u]; i; i = e[i].nxt){
		int v = e[i].v;
		if(v == fa[u] || v == son[u]) continue;
		dfs2(v, v);
	}
}
void modify_tree(int u, int v, int delta){
	while(top[u] != top[v]){
		if(dep[top[u]] < dep[top[v]]) swap(u, v);
		modify(root, 1, n, in[top[u]], in[u], delta);
		u = fa[top[u]];
	}
	if(dep[u] < dep[v]) swap(u, v);
	modify(root, 1, n, in[v], in[u], delta);
}
int query_seg(int u, int v){
	int rt = 0;
	while(top[u] != top[v]){
		if(dep[top[u]] < dep[top[v]]) swap(u, v);
		rt = max(rt,query(root, 1, n, in[top[u]], in[u]));
		u = fa[top[u]];
	}
	if(dep[u] < dep[v]) swap(u, v);
	rt = max(rt,query(root, 1, n, in[v], in[u]));
	return rt;
}

int i,j,k,t,f[maxn],res,x,y,ans;
vector<int> v[maxn];

void dfs3(int x){
	int y;
	if(x>1){
		y=query_seg(1,x);
		if(f[y]){res++;}f[y]++;
	}
	ans=max(ans,res);
	modify_tree(x,x,x);
	
	for(auto i:v[x]){
		dfs3(i);
	}
	f[y]--;
	if(f[y]>=1){res--;}
	modify_tree(x,x,0);
}

int main(){
	t=1;scanf("%d",&t);
	while(t--){
		num=res=indexx=ans=0;
		scanf("%d",&n);
		for(i=1;i<=n;i++){
			f[i]=fa[i]=dep[i]=in[i]=top[i]=siz[i]=son[i]=h[i]=seq[i]=a[i]=0;
			v[i].clear();
		}
		for(i=2;i<=n;i++){
			scanf("%d",&x);
			v[x].push_back(i);
		}
		for(i=2;i<=n;i++){
			scanf("%d",&x);
			add(x,i);
		}
		dfs1(1), dfs2(1, 1);
		root = build(1, n);
		tail=pool;
		dfs3(1);
		printf("%d\n",ans+1);
	}
}