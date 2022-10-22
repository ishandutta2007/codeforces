#include<bits/stdc++.h>
#define seg int k=1,int l=0,int r=n
#define lc k<<1
#define rc lc|1
#define mid ((l+r)>>1)
#define lson lc,l,mid
#define rson rc,mid+1,r
#define FOR(i,a,b) for(int i=a,i##i=b;i<=i##i;++i)
using namespace std;
typedef long long ll;
const int N=2e5+7;
int n,T,x,L,R,K,p[N],mn[N<<2];
ll la;
void chp(int x,int w,seg){
	if(l==r)mn[k]=p[x]=w;
	else x>mid?chp(x,w,rson):chp(x,w,lson),mn[k]=min(mn[lc],mn[rc]);
}
int find(int x,seg){
	if(l==r)return l;
	return mn[lc]<x?find(x,lson):find(x,rson);
}
int sl[N],sr[N];
map<int,int>rt[N];
int ls[N<<6],rs[N<<6],C;
struct node{
	ll k,b;
	ll val(int t){return t*k+b;}
	node operator+(node x)const{return {k+x.k,b+x.b};}
	node operator*(ll x)const{return {k*x,b*x};}
}su[N<<6],ad[N<<6];
void add(int x,int y,node v,int kl,int&k,int l=1,int r=n){
	if(l>y||r<x)return void(k=kl);
	if(!k)k=++C,su[k]=su[kl],ad[k]=ad[kl];
	if(l>=x&&r<=y)return ls[k]=ls[kl],rs[k]=rs[kl],void(ad[k]=ad[k]+v);
	su[k]=su[k]+v*(min(r,y)-max(l,x)+1);
	add(x,y,v,ls[kl],ls[k],l,mid),add(x,y,v,rs[kl],rs[k],mid+1,r);
}
node qry(int x,int y,int k,int l=1,int r=n){
	if(l>y||r<x||!k)return {0,0};
	if(l>=x&&r<=y)return su[k]+ad[k]*(r-l+1);
	return qry(x,y,ls[k],l,mid)+qry(x,y,rs[k],mid+1,r)+ad[k]*(min(r,y)-max(l,x)+1);
}
inline void ins(int x,int l,int r){
	int h=(*prev(rt[x].end())).second;
	add(l,r,{1,1-T},h,rt[x][T]);
	if(!sl[x])sl[x]=l,sr[x]=r;
	else sl[x]=min(sl[x],l),sr[x]=max(sr[x],r);
}
void work(int l,int r){
	while(r>=l&&r){
		int k=find(r);
		ins(k,max(p[k]+1,l),r),r=p[k];
	}
}
signed main(){
	scanf("%d",&n);
	FOR(i,0,n)rt[i][0]=0;
	for(T=1;T<=n;++T){
		scanf("%d%d%d%d",&x,&L,&R,&K);
		x=(x+la)%(n+1),L=(L+la)%T+1,R=(R+la)%T+1,K=(K+la)%(n+1);
		if(L>R)swap(L,R);
		chp(x,T),work(sl[x],sr[x]);
		int h=(*prev(rt[x].end())).second;
		add(sl[x],sr[x],{-1,T-1},h,rt[x][T]);
		sl[x]=sr[x]=0,ins(!x,T,T);
		printf("%lld\n",la=qry(L,R,(*prev(rt[K].upper_bound(R))).second).val(R));
	}
	return 0;
}