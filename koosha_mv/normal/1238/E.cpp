#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);																																														
#define ops cout<<"!"<<endl;
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int M=20;

int n,m,g[M][M],dp[(1<<M+1)+1],deg[M],ans[M][(1<<M)+1];
string s;

int dfs(int x,int mask){
	if(ans[x][mask]>=0) return ans[x][mask];
	ans[x][mask]=0;
	int c=mask;
	f(i,0,M){
		if(c%2 && i!=x){
			ans[x][mask]=g[x][i]+dfs(x,mask-(1<<i));
			return ans[x][mask];
		}
		c/=2;
	}
	return ans[x][mask];
}

int solve(int mask,int sz){
	int c=mask;
	if(dp[mask]>=-1e8) return dp[mask];
	dp[mask]=1e8;
	f(i,0,M){
		if(c%2){
			int anss=dfs(i,mask);
			anss=(deg[i]-anss*2)*-1;
			minm(dp[mask],solve(mask-(1<<i),sz-1)+anss*sz);
		}
		c/=2;
	}
	return dp[mask];
}

int main(){
	cin>>n>>m;
	cin>>s;
	f(i,0,n-1)
		if(s[i]!=s[i+1]){
			g[s[i]-'a'][s[i+1]-'a']++;
			g[s[i+1]-'a'][s[i]-'a']++;
			deg[s[i]-'a']++;
			deg[s[i+1]-'a']++;
		}
	f(i,1,(1<<M)) dp[i]=-1e9;
	f(i,0,M) f(j,0,(1<<M)) ans[i][j]=-1;
	cout<<solve((1<<M)-1,M);
}