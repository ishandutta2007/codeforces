#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
 
using namespace __gnu_pbds;
using namespace std;
const int maxn = 1000005;

#define getchar()(p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
char buf[1<<21],*p1=buf,*p2=buf;
inline int rd()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

int n, m, num, indexx, opt, tot;
int dep[maxn], in[maxn], top[maxn], siz[maxn], son[maxn], h[maxn], fa[maxn], seq[maxn], a[maxn],used[maxn];
struct edge{ int nxt, v;}e[maxn * 2];
inline void add(int u, int v){
	e[++num].v = v, e[num].nxt = h[u], h[u] = num;
	e[++num].v = u, e[num].nxt = h[v], h[v] = num;
}
struct node{
	node *ls, *rs;
	int sum, flag;
	void pushdown(int lf, int rg){
		if(flag == 2){
			int mid  = (lf + rg) >> 1;
			ls->sum  = 0;
			rs->sum  = 0;
			ls->flag = rs->flag = 2;
		}
		flag = 0;
	}
	void update(){
		sum = ls->sum + rs->sum;
	}
}pool[maxn * 2], *tail = pool, *root;
node* build(int lf ,int rg){
	node *bt = ++tail;
	if(lf == rg) {bt->sum = a[seq[lf]]; bt->flag = 0; return bt;}
	int mid = (lf + rg)>>1;
	bt->ls = build(lf, mid), bt->rs = build(mid + 1, rg);
	bt->flag = 0, bt->update();
	return bt;
}
void modify(node *bt, int lf, int rg, int L, int R){
	if(L <= lf && rg <= R){
		bt->flag = 2, bt->sum = 0;
		return;
	}
	int mid = (lf + rg)>>1;
	bt->pushdown(lf, rg);
	if(L <= mid) modify(bt->ls, lf, mid, L, R);
	if(R > mid)  modify(bt->rs, mid + 1, rg , L, R);
	bt->update();
	return;
}
int query(node *bt, int lf, int rg, int L, int R){
	if(L <= lf && rg <= R) return bt->sum;
	int mid = (lf + rg) >> 1, rt = 0;
	bt->pushdown(lf, rg);
	if(L <= mid)  rt += query(bt->ls, lf, mid, L, R);
	if(R > mid) rt += query(bt->rs, mid + 1, rg, L, R);
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
void modify_tree(int u){
	while(top[u] != top[n]){
		if(dep[top[u]] < dep[top[n]]) swap(u, n);
		modify(root, 1, n, in[top[u]], in[u]);
		u = fa[top[u]];
	}
	if(dep[u] < dep[n]) swap(u, n);
	modify(root, 1, n, in[n], in[u]);
}
int query_seg(int u){
	int rt = 0;
	while(top[u] != top[n]){
		if(dep[top[u]] < dep[top[n]]) swap(u, n);
		rt += query(root, 1, n, in[top[u]], in[u]);
		u = fa[top[u]];
	}
	if(dep[u] < dep[n]) swap(u, n);
	rt += query(root, 1, n, in[n], in[u]);
	return rt;
}
int i,j,k,t=100,sb;
int main(){
	n=rd();m=rd();sb=n-m;used[0]=1;
	for(i=1;i<=n;i++){
		int u,v;
		if(i<n){u=rd();v=rd();add(u,v);}a[i]=1;
	}
	dfs1(n), dfs2(n, n);
	root = build(1, n);
	for(i=n;i>=1;i--){
		if(used[i]){continue;}
		k=query_seg(i);
		if(k<=sb){
			sb-=k;j=i;
			while(!used[j]){used[j]=1;j=fa[j];}
			modify_tree(i);
		}
	}
	for(i=1;i<=n;i++){
		if(!used[i]){printf("%d ",i);}
	}
}