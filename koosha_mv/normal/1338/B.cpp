#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(ll i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);																																														
#define ops(x) cout<<x<<" !"<<endl;
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=2e5+9;
int t,n,x,y,barg[N],ans2,ans1=1,f,z,rt=1;
vector<int> g[N];
int count_barg(int x){
	int res=0;
	f(i,0,g[x].size())
		res+=barg[g[x][i]];
	return max(res,1);
}
void dfs(int x,int dist,int par){
	if(barg[x]){
		if(dist%2) f=1;
		else z=1;
	}
	f(i,0,g[x].size())
		if(g[x][i]!=par)
			dfs(g[x][i],dist+1,x);
}
int main(){
	cin>>n;ans2=n-1;
	f(i,1,n){
		Gett(x,y);
		g[x].pb(y);
		g[y].pb(x);
	}
	f(i,1,n+1) barg[i]=(g[i].size()==1);
	f(i,1,n+1){
		//cout<<i<<" : "<<count_barg(i)<<endl;
		ans2-=(count_barg(i)-1);
	}
	for(;barg[rt];rt++){}
	dfs(rt,0,0);
	if(z && f) ans1=3;
	cout<<ans1<<" "<<ans2;
}