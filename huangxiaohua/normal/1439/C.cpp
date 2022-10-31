#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,op;
ll a[200500];

class SB{
	public:
	#define ls ((id<<1))
	#define rs (ls+1)
	#define md ((l+r)>>1)
	#define get() f[id]=f[ls]+f[rs]
	
	int x,y;
	ll res,w,cur,f[800500],t[800500],g[200500];
	
	void build(int id,int l,int r){
		if(l==r){g[l]=f[id]=a[l];return;}
		build(ls,l,md);build(rs,md+1,r);
		get();
	}
	
	void up(int id,int l,int r,ll w){
		g[l]=t[id]=w;f[id]=w*(r-l+1);
	}
	
	void upd(int id,int l,int r){
		up(ls,l,md,t[id]);up(rs,md+1,r,t[id]);t[id]=0;
	}
	
	void ass(int id,int l,int r){
		if(r<=y&&g[l]<=w){
			g[l]=t[id]=w;f[id]=w*(r-l+1);return;
		}
		if(g[r+1]>=w||l==r)return;
		if(t[id])upd(id,l,r);
		ass(ls,l,md);
		if(y>md)ass(rs,md+1,r);
		get();
	}
	
	void que(int id,int l,int r){
		if(x<=l){
			if(f[id]<=cur){
				cur-=f[id];res+=r-l+1;
				return;
			}
		}
		if(l==r)return;
		if(t[id])upd(id,l,r);
		if(x<=md&&g[r+1]<=cur)que(ls,l,md);
		que(rs,md+1,r);
	}
}sb;

int main(){
	scanf("%d%d",&n,&t);
	for(i=1;i<=n;i++)scanf("%lld",&a[i]);
	sb.build(1,1,n);
	while(t--){
		scanf("%d%d%d",&op,&sb.x,&sb.y);
		if(op==1){
			sb.w=sb.y;sb.y=sb.x;
			sb.ass(1,1,n);
		}
		else{
			sb.cur=sb.y;sb.res=0;sb.que(1,1,n);
			printf("%lld\n",sb.res);
		}
	}
}