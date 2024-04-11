#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
#define pb push_back
typedef pair<int,int> pii;
ll n,k,x,y,z,dp[1000001][2],ans=0;
vector<pair<ll,ll> > g[100009];
inline bool cmp(pii x,pii y)
{
	if(x.first!=y.first)
		return x.first>y.first;
	return x.second>y.second;
}
void dfs(ll x,ll par){
	vector <pair<ll,ll> > v;ll sum=0,mx=0,j=0;
	f(i,0,g[x].size()){
		if(g[x][i].first!=par){
			dfs(g[x][i].first,x);
			v.pb(make_pair(dp[g[x][i].first][1]+g[x][i].second,i));
		}
	}
	
	sort(v.begin(),v.end(),cmp);
	f(i,0,min(k-1,(ll)(v.size())))
		sum+=v[i].first;
 
	dp[x][1]=sum;
	f(i,0,v.size()){
		j=0;
		if(i<k-1){
			j=sum-v[i].first+dp[g[x][v[i].second].first][0]+g[x][v[i].second].second;
			if(v.size()>k-1){
				j+=v[k-1].first;
			}
		}
		else
			j=sum+dp[g[x][v[i].second].first][0]+g[x][v[i].second].second;
		mx=max(mx,j);
	}
	dp[x][0]=max(mx,dp[x][1]);
}
int main(){
	cin>>n>>k;
	f(i,1,n){
		cin>>x>>y>>z;
		g[x].pb(make_pair(y,z));
		g[y].pb(make_pair(x,z));}
	dfs(0,-1);
	cout<<max(dp[0][0],dp[0][1]);
}