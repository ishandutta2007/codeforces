#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
ll n,x,y,mark1[200009],dp[200009],mark2[200009],mn=1e18,cost[200009],j;
vector<pair<ll,ll> > g[200009];
int dfs1(int x){
	int ans=0;mark1[x]=1;
	f(i,0,g[x].size()){
		if(mark1[g[x][i].first]==0)
			ans+=dfs1(g[x][i].first)+g[x][i].second;
	}
	return ans;
}
int dfs2(int x){
	mark2[x]=1;
	f(i,0,g[x].size()){
		if(mark2[g[x][i].first]==0){
			cost[g[x][i].first]=cost[x]-(g[x][i].second*2-1);
			dfs2(g[x][i].first);
		}
	}
	mn=min(mn,cost[x]);
}
int main(){
	cin>>n;
	f(i,0,n-1){
		cin>>x>>y;//scanf("%I64d%I64d",&x,&y);
		g[x].push_back(make_pair(y,0));
		g[y].push_back(make_pair(x,1));}
	cost[1]=dfs1(1);dfs2(1);
	cout<<mn<<endl;
	f(i,1,n+1)
		if(cost[i]==mn)
			cout<<i<<" ";
}