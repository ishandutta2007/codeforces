#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define get(x) scanf("%I64d",&x);
#define Gett(x,y) scanf("%d%d",&x,&y);
#define gett(x) scanf("%d",&x);
#define f(i,a,b) for(int i=a;i<b;i++)
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define S second
#define F first
const int N=1010;
int n,x,y,h[N],tedad[N],ans[N],k,a[N];
vector<int> g[N];
void dfs(int x,int pr){
	vector<int> v;
	f(i,0,g[x].size()){
		if(g[x][i]!=pr)
			dfs(g[x][i],x);
	}
	f(i,0,g[x].size()){
		if(g[x][i]!=pr && ans[g[x][i]]==-1){
			v.pb(g[x][i]);
		}
	}
	for(int i=1;i<v.size();i+=2){
		cout<<" ? "<<v[i]<<" "<<v[i-1]<<endl;
		cin>>k;
		ans[v[i]]=ans[v[i-1]]=1;
		if(k==v[i]) ans[v[i]]=0;
		if(k==v[i-1]) ans[v[i-1]]=0;
	}
	if(v.size()%2==1 && x!=1){
		cout<<" ? "<<v[v.size()-1]<<" "<<pr<<endl;
		cin>>k;
		ans[v[v.size()-1]]=1,ans[x]=1;
		if(k==v[v.size()-1]) ans[v[v.size()-1]]=0,ans[x]=0;
		if(k==x) ans[x]=0;
	}
	if(v.size()%2==1 && x==1){
		cout<<" ? "<<v[v.size()-1]<<" "<<x<<endl;
		cin>>k;
		ans[v[v.size()-1]]=0;
		if(k==1) ans[v[v.size()-1]]=1;
	}
}
int solve(int x,int pr){
	a[x]=1;
	f(i,0,g[x].size()){
		if(g[x][i]!=pr){
			solve(g[x][i],x);
			a[x]=(a[x] && a[g[x][i]]);
		}
	}
	if(a[x]==1 && ans[x]<1){
		cout<<" ! "<<x<<endl;
		exit(0);
	}
	a[x]=(a[x] && ans[x]);
}
int main(){
	cin>>n;
	f(i,1,n){
		cin>>x>>y;
		g[x].pb(y);
		g[y].pb(x);
	}
	fill(ans,ans+N,-1);
	dfs(1,0);
	solve(1,0);
}