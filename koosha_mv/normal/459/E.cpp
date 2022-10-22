#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define get(x) scanf("%I64d",&x);
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define S second
#define F first
const int N=3e5+9;
ll n,m,dp[N][2],x,y,z,ans;

vector<pair <ll,ll> > e[N];
int main(){
	cin>>n>>m;
	f(i,0,m){
		Get(x,y);
		get(z);
		e[z].pb(make_pair(y,x));
	}
	f(i,0,N){
		f(j,0,e[i].size())
			maxm(dp[e[i][j].F][1],dp[e[i][j].S][0]+1);
		f(j,0,e[i].size())
			maxm(dp[e[i][j].F][0],dp[e[i][j].F][1]);
	}
	f(i,1,n+1) maxm(ans,dp[i][0]);
	cout<<ans<<endl;
}