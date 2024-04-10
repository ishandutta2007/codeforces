#include<bits/stdc++.h>
#define ll long long
#define eb emplace_back
using namespace std;
const int S=1<<15;
const int M=1e6+9;
int n;
vector<ll>p;
map<ll,ll>mp,vis;
ll s[23];
vector<ll>dp[S];
ll f1[23],f2[23];
int main(){
	cin>>n;
	for(int i=0;i<n;++i){
		int m;
		cin>>m;
		for(int j=1;j<=m;++j){
			ll x;
			cin>>x;
			mp[x]=i;
			p.eb(x);
			s[i]+=x;
		}
	}
	ll sum=0;
	for(auto o:p){
		sum+=o;
	}
	if(sum%n){
		puts("No");
		return 0;
	}
	sum/=n;
	for(auto o:p){
		if(!vis.count(o)){
			vector<ll>v;
			ll u=o;
			vis[u]=o;
			v.eb(u);
			ll x=mp[u];
			u=sum-(s[x]-u);
			bool bol=0;
			int y=o;
			while(u!=o){
				if(!mp.count(u)||(vis.count(u)&&vis[u]!=o)){
					bol=1;
					break;
				}
				vis[u]=o;
				v.eb(u);
				ll x=mp[u];
				u=sum-(s[x]-u);
				if(vis.count(u)&&vis[u]==o){
					y=u;
					break;
				}
			}
			int t=0;
			if(!bol){
				reverse(v.begin(),v.end());
				while(v.back()!=y)v.pop_back();
				bool flag=0;
				for(auto u:v){
					ll x=mp[u];
					if(t>>x&1)flag=1;
					t|=1<<x;
				}
				if(!flag){
					dp[t]=v;
 				}
			}
		}
	}
	for(int i=1;i<1<<n;++i){
		if(dp[i].size())continue;
		for(int j=i;j;j=(j-1)&i){
			if(dp[j].size()&&dp[i^j].size()){
				for(auto o:dp[j])dp[i].eb(o);
				for(auto o:dp[i^j])dp[i].eb(o);
				break;
			}
		}
	}
	if(dp[(1<<n)-1].size()){
		puts("Yes");
		for(auto o:dp[(1<<n)-1]){
			ll x=sum-(s[mp[o]]-o);
			f1[mp[x]]=x;
			f2[mp[x]]=mp[o]+1;
		}
		for(int i=0;i<n;++i)cout<<f1[i]<<" "<<f2[i]<<endl;
	}
	else puts("No");
	return 0;
}