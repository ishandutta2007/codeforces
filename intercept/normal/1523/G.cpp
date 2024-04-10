#include<bits/stdc++.h> 
#define eb emplace_back
using namespace std;
const int M=1e5+9;
int n,m,sz=0;
int ans[M];
int L[M],R[M],rt[M],ls[M*250],rs[M*250],val[M*250];
vector<int>g[M];
void update(int&rt,int l,int r,int x,int v){
	if(!rt)rt=++sz,val[rt]=1e9;
	val[rt]=min(val[rt],v);
	if(l==r)return;
	int mid=l+r>>1;
	x<=mid?update(ls[rt],l,mid,x,v):update(rs[rt],mid+1,r,x,v);
}
int query(int&rt,int l,int r,int x,int y){
	if(!rt)rt=++sz,val[rt]=1e9;
	if(x<=l&&r<=y)return val[rt];
	int mid=l+r>>1,rex=1e9;
	if(x<=mid)rex=min(rex,query(ls[rt],l,mid,x,y));
	if(y>mid)rex=min(rex,query(rs[rt],mid+1,r,x,y));
	return rex;
}
void add(int l,int r,int id){
	for(int i=r;i<=n;i+=i&-i)update(rt[i],1,n,l,id);
}
int ask(int l,int r,int rex=1e9){
	for(int i=r;i;i-=i&-i)rex=min(rex,query(rt[i],1,n,l,r));
	return rex;
}
int solve(int l,int r){
	int id=ask(l,r);
	if(id>m)return 0;
	return solve(l,L[id]-1)+solve(R[id]+1,r)+R[id]-L[id]+1;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i){
		scanf("%d%d",&L[i],&R[i]);
		g[R[i]-L[i]+1].eb(i);
	}
	for(int T=n;T>=1;--T){
		for(auto id:g[T])add(L[id],R[id],id);
		ans[T]=solve(1,n);
	}
	for(int i=1;i<=n;++i)printf("%d\n",ans[i]);
	return 0;
}