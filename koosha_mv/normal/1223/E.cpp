#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
ll q,n,k,x,y,w,dp[500009][2],mark[500009];
vector<pair<ll, ll> > g[500017];
// 0 : k    1:k-1 saaaaaaaaaaaaaaaaaaaaaaalllllllllllllllllllllllllllllllam
int dfs(ll x){
	vector<pair<ll,ll> > ad;
	mark[x]=1;dp[x][0]=0;dp[x][1]=0;
	f(i,0,g[x].size()){
		if(mark[g[x][i].second]==0){
			dfs(g[x][i].second);
			ad.push_back(make_pair(dp[g[x][i].second][1]+g[x][i].first-dp[g[x][i].second][0],i));
		}
	}
	sort(ad.begin(), ad.end());
	f(i,0,ad.size()){
		if(ad.size()-1-i<k && ad[i].first>0){
			dp[x][0]+=dp[g[x][ad[i].second].second][1]+g[x][ad[i].second].first;
		}
		else{
			dp[x][0]+=dp[g[x][ad[i].second].second][0];
		}
		if(ad.size()-1-i<k-1 && ad[i].first>0){
			dp[x][1]+=dp[g[x][ad[i].second].second][1]+g[x][ad[i].second].first;
		}
		else{
			dp[x][1]+=dp[g[x][ad[i].second].second][0];
		}
	}
}
int main(){
	cin>>q;
	while(q--){
		f(i,0,n+1) mark[i]=0;
		cin>>n>>k;
		f(i,0,n+1) g[i].clear();
		f(i,0,n-1){
			scanf("%I64d%I64d%I64d", &x, &y, &w);
			g[x].push_back(make_pair(w,y));
			g[y].push_back(make_pair(w,x));
		}
		dfs(1);
		cout<<dp[1][0]<<endl;}
}