#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define get(x) scanf("%I64d",&x);
#define f(i,a,b) for(int i=a;i<b;i++)
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
ll n,m,x,y,mark[55],tvn,ans=1;
vector<int> g[55];
int dfs(int x){
	mark[x]=1;
	f(i,0,g[x].size()){
		if(mark[g[x][i]]==0)
			dfs(g[x][i]);
	}
}
int main(){
	cin>>n>>m;
	f(i,0,m){
		Get(x,y);
		g[x].pb(y);
		g[y].pb(x);
	}
	tvn=n;
	f(i,1,n+1){
		if(mark[i]==0){
			tvn--;
			dfs(i);
		}
	}
	f(i,0,tvn) ans*=2;
	cout<<ans;
}