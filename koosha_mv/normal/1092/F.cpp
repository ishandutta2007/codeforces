#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
ll mark3[200009],mark2[200009],x,y,n,mark1[200009],zarib[200009],v[200009],d,sum,mx=0;
vector<ll> g[200009];
ll dp1(ll x){
	ll ans=v[x];
	mark1[x]=1;
	f(i,0,g[x].size()){
		if(mark1[g[x][i]]==0)
			ans+=dp1(g[x][i]);}
	zarib[x]=ans;
	return ans;}
ll dfs1(ll x,ll dis){
	mark2[x]=1;
	f(i,0,g[x].size()){
		if(mark2[g[x][i]]==0){
			dfs1(g[x][i],dis+1);}}
	d+=v[x]*dis;}
ll dfs2(ll x,ll p){
	mark3[x]=1;
	f(i,0,g[x].size()){
		if(mark3[g[x][i]]==0)
			dfs2(g[x][i],p-zarib[g[x][i]]+(sum-zarib[g[x][i]]));}
	mx=max(mx,p);}
int main(){
	cin>>n;
	f(i,1,n+1) cin>>v[i],sum+=v[i];
	f(i,0,n-1){
		cin>>x>>y;
		g[x].push_back(y),g[y].push_back(x);}
	dp1(1);
	dfs1(1,0);
	dfs2(1,d);
	cout<<mx;
}