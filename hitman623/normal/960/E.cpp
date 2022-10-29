#include <bits/stdc++.h>

#define int         unsigned int
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define mi          map<int,int>
#define mii         map<pii,int>
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x)       (int)x.size()
#define endl        '\n'
#define hell        1000000007
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int n,val[200005],dp[200005],c[200005],ans=0;
vi a[200005];
int mul(int A,int B){
	return (1LL*A*B)%hell;
}
void dfs(int node,int par){
	c[node]=1;
	int s=0;
	for(auto i:a[node]){
		if(i==par) continue;
		dfs(i,node);
		c[node]=(c[node]+c[i])%hell;
		s=(s+dp[i])%hell;
	}
	dp[node]=(mul(c[node],val[node])+hell-s)%hell;
}
void dfs2(int node,int par){
	ans=(ans+dp[node]+hell)%hell;
	for(auto i:a[node]){
		if(i==par) continue;
		int temp[]={dp[node],c[node],c[i],dp[i]};
		dp[node]=(dp[node]+hell-mul(c[i],val[node])+dp[i])%hell;
		c[node]=(c[node]+hell-c[i])%hell;
		c[i]=(c[i]+c[node])%hell;
		dp[i]=(dp[i]+hell-dp[node]+mul(c[node],val[i]))%hell;
		dfs2(i,node);
		dp[node]=temp[0],c[node]=temp[1],c[i]=temp[2],dp[i]=temp[3];
	}
}
void solve(){
	cin>>n;
	rep(i,1,n+1){
		cin>>val[i];
		val[i]=(val[i]+hell)%hell;
	}
	rep(i,0,n-1){
		int x,y;
		cin>>x>>y;
		a[x].pb(y);
		a[y].pb(x);
	}
	dfs(1,-1);
	dfs2(1,-1);
	cout<<(ans+hell)%hell<<endl;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t=1;
    // cin>>t;
	while(t--){
		solve();
	}
	return 0;
}