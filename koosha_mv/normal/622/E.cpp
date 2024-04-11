#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define get(x) scanf("%I64d",&x);
#define Gett(x,y) scanf("%d%d",&x,&y);
#define gett(x) scanf("%d",&x);
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define S second
#define F first
#define mp make_pair
const int N=5e5+99;
int n,x,y,ans,a[N],cnt;
vector<int> g[N];
void dfs(int x,int par,int dist){
	f(i,0,g[x].size()){
		if(g[x][i]!=par)
			dfs(g[x][i],x,dist+1);
	}
	if(g[x].size()==1) a[cnt]=dist,cnt++;
}
int solve(int x){
	cnt=0;
	dfs(x,1,1);
	sort(a,a+cnt);
	f(i,1,cnt)
		maxm(a[i],a[i-1]+1);
}
int main(){
	cin>>n;
	f(i,1,n){
		Gett(x,y);
		g[x].pb(y);
		g[y].pb(x);
	}
	f(i,0,g[1].size()){
		solve(g[1][i]);
		maxm(ans,a[cnt-1]);
	}
	cout<<ans;
}