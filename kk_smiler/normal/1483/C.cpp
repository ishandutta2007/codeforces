#include <bits/stdc++.h>
using namespace std;
int T,n,m,p,k,a[300010],pre[300010];
long long mx[1200010],tag[12000010],dp[300010],b[300010];
void build(int l,int r,int t){
	mx[t]=tag[t]=0;
	if(l==r) return;
	int mid=(l+r)>>1;
	build(l,mid,t<<1);
	build(mid+1,r,t<<1|1);
}
void add(int t,long long c){
	mx[t]+=c,tag[t]+=c;
}
void pushdown(int t){
	add(t<<1,tag[t]),add(t<<1|1,tag[t]);
	tag[t]=0;
}
void cg(int a,int l,int r,int t,long long c){
	if(l==r){
		mx[t]=c;
		return;
	}
	int mid=(l+r)>>1;
	pushdown(t);
	if(a<=mid) cg(a,l,mid,t<<1,c);
	else cg(a,mid+1,r,t<<1|1,c);
	mx[t]=max(mx[t<<1],mx[t<<1|1]);
}
void add(int ll,int rr,int l,int r,int t,long long c){
	if(ll<=l&&r<=rr) return add(t,c);
	int mid=(l+r)>>1;
	pushdown(t);
	if(ll<=mid) add(ll,rr,l,mid,t<<1,c);
	if(mid<rr) add(ll,rr,mid+1,r,t<<1|1,c);
	mx[t]=max(mx[t<<1],mx[t<<1|1]);
}
long long qry(int ll,int rr,int l,int r,int t){
	if(ll<=l&&r<=rr) return mx[t];
	int mid=(l+r)>>1;
	pushdown(t);
	if(rr<=mid) return qry(ll,rr,l,mid,t<<1);
	if(mid<ll) return qry(ll,rr,mid+1,r,t<<1|1);
	return max(qry(ll,rr,l,mid,t<<1),qry(ll,rr,mid+1,r,t<<1|1));
}
void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	build(0,n,1);
	dp[0]=0;
	cg(0,0,n,1,dp[0]);
	for(int i=1;i<=n;i++){
		scanf("%lld",&b[i]);
		add(i-1,i-1,0,n,1,b[i]);
		pre[i]=i-1;
		while(pre[i]&&a[pre[i]]>a[i]){
			add(pre[pre[i]],pre[i]-1,0,n,1,b[i]-b[pre[i]]);
			pre[i]=pre[pre[i]];
		}
		dp[i]=qry(0,i-1,0,n,1);
		cg(i,0,n,1,dp[i]);
	}
	printf("%lld\n",dp[n]);
}
int main(){
	if(0) scanf("%d",&T);
	else T=1;
	while(T--) solve();
}