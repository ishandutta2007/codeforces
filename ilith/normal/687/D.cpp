#include<bits/stdc++.h>
#define rgi register int
#define mid (l+r>>1)
#define lc k<<1
#define rc lc|1
using namespace std;
const int N=1010,M=500010;
#define set(x) fa[x]=x,fa[x+n]=x+n
#define ve vector<edge>
#define vl(x) x.begin(),x.end()
int n,m,q,fa[N<<1],l,r;
struct edge{int u,v,w;}e[M];
int fi(int x){return x==fa[x]?x:fa[x]=fi(fa[x]);}
ve t[M<<2],res;
int solve(ve a,int k){
	for(auto e:a)set(e.u),set(e.v);
	for(auto e:a){
		int fx=fi(e.u),fy=fi(e.v),fY=fi(e.v+n);
		if(fx!=fY)t[k].push_back(e),fa[fx]=fY,fa[fy]=fi(e.u+n);
		if(fx==fy)return e.w;
	}
	return -1;
}
ve merge(ve a,ve b){
	ve r(a.size()+b.size());
	return merge(vl(a),vl(b),r.begin(),[&](edge x,edge y){return x.w>y.w;}),r;
}
void build(int k,int l,int r){
	if(l==r)return t[k].push_back(e[l]);
	build(lc,l,mid),build(rc,mid+1,r);
	solve(merge(t[lc],t[rc]),k);
}
ve qry(int x,int y,int k=1,int l=1,int r=m){
	if(l>y||r<x)return res;
	if(l>=x&&r<=y)return t[k];
	return merge(qry(x,y,lc,l,mid),qry(x,y,rc,mid+1,r));
}
signed main(){
	scanf("%d%d%d",&n,&m,&q);
	for(rgi i=1;i<=m;++i)scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
	build(1,1,m);
	while(q--)scanf("%d%d",&l,&r),printf("%d\n",solve(qry(l,r),0));
	return 0;
}