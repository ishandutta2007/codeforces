#include<bits/stdc++.h>
using namespace std;
#define py puts("Yes");
#define pn puts("No");
#define N 300005
#define ls (k<<1)
#define rs (k<<1|1)
#define mid (l+r>>1)
#define int long long
int val[N<<2],dp[N],T,n,a[N],i,j,b[N],k,st[N],hd;
void modify(int k,int l,int r,int x,int y){
	if(l==r){val[k]=y;return ;}
	if(x<=mid)modify(ls,l,mid,x,y);
	else modify(rs,mid+1,r,x,y);
	val[k]=max(val[ls],val[rs]);
}
int mx(int k,int l,int r,int x,int y){
	if(x<=l&&r<=y)return val[k];
	if(r<x||y<l)return -1e16;
	return max(mx(ls,l,mid,x,y),mx(rs,mid+1,r,x,y));
}
signed main(){
	scanf("%lld",&n);
	for(i=1;i<=n;++i)scanf("%lld",&a[i]);
	for(i=1;i<=n;++i)scanf("%lld",&b[i]);
	for(i=1;i<=n;++i){
		modify(1,1,n,i,dp[i-1]+b[i]);
		while(hd&&a[st[hd]]>a[i])modify(1,1,n,i,max(mx(1,1,n,i,i),mx(1,1,n,st[hd],st[hd])-b[st[hd]]+b[i])),modify(1,1,n,st[hd],-1e16),--hd;
		st[++hd]=i;
		dp[i]=mx(1,1,n,1,i);
	}cout<<dp[n];
}