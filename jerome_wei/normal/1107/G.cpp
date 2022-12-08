#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;ll a;
const int N=3e5+5;
ll delt[N],d[N],c[N];

struct SegT{
	ll t[N<<2],lzy[N<<2];
	inline void build(int x,int l,int r){
		int mid=(l+r)>>1;
		if(l==r){
			t[x]=-c[l-1]+a*(ll)(l-1);//L
			return ;
		}
		t[x]=min(t[x<<1],t[x<<1|1]);
		build(x<<1,l,mid),build(x<<1|1,mid+1,r);
	}
	inline void pushdown(int x,int l,int r){
		if(lzy[x]){
			t[x]+=lzy[x];
			if(l^r)lzy[x<<1]+=lzy[x],lzy[x<<1|1]+=lzy[x];
			lzy[x]=0;
		}
	}
	inline void modify(int x,int l,int r,int ql,int qr,ll val){
		pushdown(x,l,r);
		int mid=(l+r)>>1;
		if(ql<=l&&qr>=r){
			lzy[x]+=val;
			return;
		}
		if(ql<=mid)modify(x<<1,l,mid,ql,qr,val);
		if(qr>mid)modify(x<<1|1,mid+1,r,ql,qr,val);
		pushdown(x<<1,l,mid),pushdown(x<<1|1,mid+1,r);
		t[x]=min(t[x<<1],t[x<<1|1]);
	}
	inline ll qry(int x,int l,int r,int ql,int qr){
		pushdown(x,l,r);
		ll ans=1e18;
		if(ql<=l&&qr>=r)return t[x];
		int mid=(l+r)>>1;
		if(ql<=mid)ans=min(ans,qry(x<<1,l,mid,ql,qr));
		if(qr>mid)ans=min(ans,qry(x<<1|1,mid+1,r,ql,qr));
		return ans;
	}
}T;
ll stk[N];
int top;
int pos[N];
ll ans=0;

int main()
{
	scanf("%d%lld",&n,&a);
	for(int i=1;i<=n;i++){
		scanf("%lld%lld",&d[i],&c[i]);
		delt[i]=(ll)(d[i]-d[i-1])*(d[i]-d[i-1]);
	}
	for(int i=1;i<=n;i++){c[i]+=c[i-1];}
	T.build(1,1,n);
	for(int R=1;R<=n;R++){
		if(R>1){
			int rr=R-2;
			T.modify(1,1,n,R-1,R-1,delt[R]);
			while(top&&stk[top]<=delt[R]){
				int ll=pos[top-1]+1;
				T.modify(1,1,n,ll,rr,delt[R]-stk[top]);
				rr=pos[top-1];
				top--;
			}
			stk[++top]=delt[R];
			pos[top]=R-1;
		}
		ll ret=T.qry(1,1,n,1,R);
		ll Rsum=a*(ll)R-(ll)c[R];
		ans=max(ans,Rsum-ret);
	}
	printf("%lld\n",ans);
}
/*
10 8
1 16
23 27
26 2
32 21
38 50
51 53
62 79
77 97
94 18
100 5
---
6
*/