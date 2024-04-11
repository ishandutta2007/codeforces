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
const int N=3e5+9;
int n,k,x,y,cent,parc,mx=-1,sub[N],w[N];
vector<int> g[N];
vector<pair<int,int> > ans;
set<pair<int,int> > deg;
pair<int,int> p1,p2;
queue<int> q[N];
void found_centroid(int x,int par,int dist){
	sub[x]=w[x];
	f(i,0,g[x].size()){
		if(g[x][i]!=par){
			found_centroid(g[x][i],x,dist+1);
			sub[x]+=sub[g[x][i]];
		}
	}
	if(sub[x]>=k && dist>mx)
		mx=dist,cent=x,parc=par;
}
void solve(){
	while(deg.size()>1){
		p1=*deg.rbegin();
		deg.erase(p1);
		p2=*deg.rbegin();
		deg.erase(p2);
		ans.pb(mp(p1.S,p2.S));
		p1.F--,p2.F--;
		if(p1.F) deg.insert(p1);
		if(p2.F) deg.insert(p2);
	}
}
void dfs(int x,int par,int rt){
	if(w[x]) q[rt].push(x);
	f(i,0,g[x].size())
		if(g[x][i]!=par)
			dfs(g[x][i],x,rt);
}
int main(){
	Gett(n,k);
	f(i,1,n){
		Gett(x,y);
		g[x].pb(y);
		g[y].pb(x);
	}
	f(i,0,2*k){
		gett(x);
		w[x]=1;
	}
	found_centroid(1,0,0);
	f(i,0,g[cent].size()){
		if(g[cent][i]!=parc && sub[g[cent][i]])
			deg.insert(mp(sub[g[cent][i]],g[cent][i]));
	}
	if(parc!=0 && sub[cent]<2*k) deg.insert(mp(2*k-sub[cent],parc));
	solve();
	if(ans.size()<k){
		p1=*deg.rbegin();
		ans.pb(mp(p1.S,0));	
		q[0].push(cent);
	}
	f(i,0,g[cent].size()){
		dfs(g[cent][i],cent,g[cent][i]);
	}
	cout<<1<<endl<<cent<<endl;
	f(i,0,ans.size()){	
		cout<<q[ans[i].F].front()<<" "<<q[ans[i].S].front()<<" "<<cent<<endl;
		q[ans[i].F].pop();q[ans[i].S].pop();
	}
}