#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
#define eb emplace_back
#define ll long long
#define ma make_pair
using namespace std;
const int mod=1e9+7;
const int M=2e5+9;
int q,k;
int dp[32][2][2][2],p[32][2][2][2];
void add(pii&x,pii y){
	x.fi=(x.fi+y.fi)%mod;
	x.se=(x.se+y.se)%mod;
}
pii dfs(int st,bool ux,bool uy,bool uk,int x,int y){
	if(st==-1)return ma(0,1);
	if(dp[st][ux][uy][uk]!=-1)return ma(dp[st][ux][uy][uk],p[st][ux][uy][uk]);
	pii ans=ma(0,0);
	int lx=ux?(x>>st&1):1;
	int ly=uy?(y>>st&1):1;
	int lk=uk?(k>>st&1):1;
	for(int i=0;i<=lx;++i){
		for(int j=0;j<=ly;++j){
			if(uk&&(i^j)>lk)continue;
			auto o=dfs(st-1,ux&(i==lx),uy&(j==ly),uk&((i^j)==lk),x,y);
			o.fi=(o.fi+1ll*o.se*((i^j)<<st)%mod)%mod;
			add(ans,o);
		}
	}
	dp[st][ux][uy][uk]=ans.fi;
	p[st][ux][uy][uk]=ans.se;
	return ans;
}
ll solve(int x,int y){
	if(x==-1||y==-1)return 0;
	memset(dp,-1,sizeof(dp));
	memset(p,-1,sizeof(p));
	auto o=dfs(30,1,1,1,x,y);
	return (o.fi+o.se)%mod;
}
int main(){
	cin>>q;
	while(q--){
		int lx,ly,rx,ry;
		cin>>lx>>ly>>rx>>ry>>k;
		lx--;ly--;
		rx--;ry--;
		k--;
		ll ans=(solve(ry,rx)-solve(ry,lx-1))-(solve(ly-1,rx)-solve(ly-1,lx-1));
		ans=(ans%mod+mod)%mod;
		cout<<ans<<"\n";
	}
	return 0;
}