#include<bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int,int>
#define ll long long
#define eb emplace_back
using namespace std;
const int mod=998244353;
const int M=3e5+9;
int n,t;
int g[M],c[M],s[M],e[M];
ll d[M],dp[M];
map<int,int>mp;
void split(int x){
	auto it=prev(mp.upper_bound(x));
	mp[x]=it->se;
}
void cover(int l,int r,int v){
	if(l==r)return;
	split(l);
	split(r);
	for(auto it=mp.find(l);it->fi<r;it=mp.erase(it));
	mp[l]=v;
}
int get(int x){
	return prev(mp.upper_bound(x))->se;
}
int main(){
	scanf("%d%d",&n,&t);
	for(int i=1;i<=n;++i)scanf("%d%d",&g[i],&c[i]);
	for(int i=2;i<=n;++i){
		scanf("%lld",&d[i]);
		d[i]+=d[i-1];
	}
	for(int i=1;i<=n;++i){
		s[i]=((-d[i]-c[i])%t+t)%t;
		e[i]=((1ll*g[i]-d[i]-c[i])%t+t)%t;
	}
	mp[0]=mp[t]=n+1;
	for(int i=n;i>=1;--i){
		int j=get(s[i]);
		if(j==n+1)dp[i]=0;
		else dp[i]=dp[j]+(s[j]-s[i]+t)%t;
		if(s[i]<e[i]){
			cover(0,s[i],i);
			cover(e[i],t,i);
		}
		else cover(e[i],s[i],i);
	}
	ll ans=1ll<<60;
	for(auto o:mp){
		int x=o.fi,y=o.se;
		if(x==t)continue;
		if(y>n)ans=0;
		else {
			x=mp.upper_bound(x)->fi-1;
			ans=min(ans,dp[y]+(s[y]-x+t)%t);
		}
	}
	ans+=d[n];
	printf("%lld\n",ans);
	return 0;
}