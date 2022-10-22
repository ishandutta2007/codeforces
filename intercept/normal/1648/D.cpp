#include<bits/stdc++.h>
#define eb emplace_back
#define fi first
#define se second
#define ll long long
#define pii pair<int,int>
using namespace std;
const int M=5e5+9;
int n,q;
vector<pii>L[M],R[M];
ll p[3][M];
int mi[M<<2];
ll ans=-(1ll<<60),dp[M],s[M],t[M];
void update(int now,int l,int r,int x,int y,int k){
	if(x<=l&&r<=y){
		mi[now]=min(mi[now],k);
		return;
	}
	int mid=l+r>>1;
	if(x<=mid)update(now<<1,l,mid,x,y,k);
	if(y>mid)update(now<<1|1,mid+1,r,x,y,k);
}
void solve(int now,int l,int r){
	if(l==r){
		if(mi[now]!=0x3f3f3f3f){
			ans=max(ans,p[0][l]-p[1][l-1]+p[1][l]+p[2][n]-p[2][l-1]-mi[now]);
			dp[l]=max(dp[l],p[0][l]-p[1][l-1]-mi[now]);
		}
		ans=max(ans,dp[l]+p[2][n]+p[1][l]-p[2][l-1]);
		return;
	}
	mi[now<<1]=min(mi[now],mi[now<<1]);
	mi[now<<1|1]=min(mi[now],mi[now<<1|1]);
	int mid=l+r>>1;
	solve(now<<1,l,mid);
	vector<pii>e;
	for(int i=l;i<=r;++i){
		for(auto o:L[i]){
			if(o.fi>r)R[r].eb(i,o.se),e.eb(i,o.se);
		}
	}
	if(mi[now]!=0x3f3f3f3f)R[r].eb(l,mi[now]),e.eb(l,mi[now]);
	s[mid]=dp[mid];
	t[mid]=p[0][mid]-p[1][mid-1];
	for(int i=mid-1;i>=l;--i)s[i]=max(dp[i],s[i+1]),t[i]=max(p[0][i]-p[1][i-1],t[i+1]);
	ll rex=-(1ll<<60);
	for(int i=r;i>mid;--i){
		for(auto o:R[i]){
			if(o.fi>mid+1)continue;
			int x=max(o.fi-1,l);
			rex=max(rex,s[x]-o.se);
			if(o.fi>mid)continue;
			int y=max(o.fi,l);
			rex=max(rex,t[y]-o.se);
		}
		dp[i]=max(dp[i],rex);
	}
	while(e.size())e.pop_back(),R[r].pop_back();
	solve(now<<1|1,mid+1,r);
}
int main(){
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;++i)dp[i]=-(1ll<<60);
	memset(mi,0X3f,sizeof(mi));
	for(int i=0;i<3;++i){
		for(int j=1;j<=n;++j)scanf("%lld",&p[i][j]),p[i][j]+=p[i][j-1];
	}
	for(int i=1;i<=q;++i){
		int l,r,k;
		scanf("%d%d%d",&l,&r,&k);
		update(1,1,n,l,r,k);
		L[l].eb(r,k);
		R[r].eb(l,k);
	}
	solve(1,1,n);
	printf("%lld\n",ans);
	return 0;
}
/*
1
6

3 3 4 1 3 3

3 4 1 3 3 3




*/