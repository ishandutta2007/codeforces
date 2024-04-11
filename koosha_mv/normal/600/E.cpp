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
const int N=1e5+9;
int n,x,y,p,c[N],mx[N],a[N];
ll ans[N];
vector<int> g[N];
map<int,int> mark[N];
void add(int x,int an,int y){
	for(auto it:mark[y]){
		mark[an][it.F]+=it.S;
		p=mark[an][it.F];
		if(p==mx[x])
			ans[x]+=it.F;
		if(p>mx[x]){
			mx[x]=p;
			ans[x]=it.F;
		}
	}
}
void dfs(int x,int par){
	int m=0,an=0;
	f(i,0,g[x].size()){
		if(g[x][i]!=par){
			dfs(g[x][i],x);
			if(mark[a[g[x][i]]].size()>m){
		    	m=mark[a[g[x][i]]].size();
		    	an=g[x][i];
			}
		}
	}
	mx[x]=mx[an],a[x]=a[an];
	ans[x]=ans[an];
	if(g[x].size()==1 && x!=1)
	    a[x]=x;
	mark[a[x]][c[x]]++;
	if(mark[a[x]][c[x]]==mx[x])
		ans[x]+=c[x];
	if(mark[a[x]][c[x]]>mx[x]){
		mx[x]=mark[a[x]][c[x]];
		ans[x]=c[x];
	}
	f(i,0,g[x].size()){
		if(g[x][i]!=par && g[x][i]!=an){
			add(x,a[an],a[g[x][i]]);
			mark[a[g[x][i]]].clear();
		}
	}
}
int main(){
	cin>>n;
	f(i,1,n+1) gett(c[i]);
	f(i,1,n){
		Gett(x,y);
		g[x].pb(y);
		g[y].pb(x);
	}
	dfs(1,0);
	f(i,1,n+1) cout<<ans[i]<<" ";
}