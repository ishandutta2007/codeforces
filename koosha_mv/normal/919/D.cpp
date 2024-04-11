#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
const int N=3e5+9;
ll dp[N][33],n,m,x,y,mark[N],mark2[N],ans;string s;
vector<int> g[N];
int dfs(int x){
	if(mark[x]==1){
		if(mark2[x]==1){
			cout<<-1;exit(0);
		}
		return 0;
	}
	mark[x]=1;mark2[x]=1;
	f(i,0,g[x].size()){
		dfs(g[x][i]);
		f(j,0,32){
			dp[x][j]=max(dp[x][j],dp[g[x][i]][j]+(int(s[x]-'a')==j));
		}
	}
	maxm(dp[x][(s[x]-'a')],1ll);
	mark2[x]=0;
}
int main(){
	cin>>n>>m;
	cin>>s;
	f(i,0,m){
		cin>>x>>y;g[x-1].pb(y-1);
	}
	f(i,0,n)
		dfs(i);
	f(i,0,n){
		f(j,0,32)
			maxm(ans,dp[i][j]);
	}
	cout<<ans;
}