#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define ROF(i,b,a) for(int i=a;i>=b;--i)
#define lc k<<1
#define rc lc|1
#define mid ((l+r)>>1)
using namespace std;
typedef long long ll;
const int N=2.5e5+7,inf=1e9;
int T,n,a[N];
struct node{
	int mn[N<<2];
	void build(int k,int l,int r){
		mn[k]=inf;
		if(l!=r)build(lc,l,mid),build(rc,mid+1,r);
	}
	void upd(int x,int v,int k=1,int l=1,int r=n){
		if(l>x||r<x)return;
		if(l==r)return void(mn[k]=v);
		upd(x,v,lc,l,mid),upd(x,v,rc,mid+1,r),mn[k]=min(mn[lc],mn[rc]);
	}
	int qry(int x,int y,int k=1,int l=1,int r=n){
		if(l>y||r<x)return inf;
		if(l>=x&&r<=y)return mn[k];
		return min(qry(x,y,lc,l,mid),qry(x,y,rc,mid+1,r));
	}
}t1,t2;
int mx[N],cx,mn[N],cn,dp[N];
void solve(){
	scanf("%d",&n),t1.build(1,1,n),t2.build(1,1,n);
	FOR(i,1,n)scanf("%d",a+i);
	mx[cx=1]=1,mn[cn=1]=1;
	t1.upd(1,0),t2.upd(1,0);
	FOR(i,2,n){
		while(cx&&a[mx[cx]]>a[i]){
			t1.upd(cx--,inf);
		}
		while(cn&&a[mn[cn]]<a[i]){
			t2.upd(cn--,inf);
		}
		int lx=mn[cn],lm=mx[cx];
		mn[++cn]=mx[++cx]=i;
		int ix=upper_bound(mx,mx+cx,lx)-mx;
		int im=upper_bound(mn,mn+cn,lm)-mn;
		if(lx>lm)dp[i]=1+min(t2.qry(im,n),dp[lx]);
		else dp[i]=1+min(t1.qry(ix,n),dp[lm]);
		t1.upd(cx,dp[i]),t2.upd(cn,dp[i]);
	}
	printf("%d\n",dp[n]);
}
int main(){
	for(scanf("%d",&T);T--;)solve();
	return 0;
}