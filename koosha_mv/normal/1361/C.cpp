#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
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

const int N=(1<<21);

int n,mx=20,r,a[N],b[N],t[N],mark[N];
vector<int> ans,tour,adj[N];
vector<pair<int,pair<int,int> > > pairs;
set<pair<int,int> > g[N];

int mat(int x){return (x%2? x+1:x-1);}
void add_edge(int u,int v,int an){
	g[u].insert(mp(v,an)),g[v].insert(mp(u,an));
	if(u>v) swap(u,v),an=mat(an);
	pairs.pb(mp(u,mp(v,an)));
}
void dfs(int x){
	mark[x]=1;
	f(i,0,adj[x].size())
		if(!mark[adj[x][i]])
			dfs(adj[x][i]);
}
void eulor(int x){
	pair<int,int> u,p;
	while(g[x].size()){
		u=*g[x].begin(),p=u,p.F=x;
		g[x].erase(u);
		g[u.F].erase(p);
		eulor(u.F);
	}
	tour.pb(x);
}
bool check(int x){
	fill(mark,mark+(1<<x),0);
	f(i,1,2*n+1) b[i]=a[i]%(1<<x);
	f(i,0,(1<<x)) adj[i].clear();
	f(i,1,n+1) adj[b[i*2-1]].pb(b[i*2]),adj[b[i*2]].pb(b[i*2-1]);
	f(i,0,(1<<x))
		if(adj[i].size()%2)
			return 0;
	f(i,0,(1<<x))
		if(adj[i].size()){
			dfs(i);
			f(j,i,(1<<x))
				if(adj[j].size() && !mark[j])
					return 0;
			break;
		}
	return 1;
}
int Get(int x,int y){
	int l=-1,r=pairs.size()-1,mid;
	while(l+1<r){
		mid=(l+r)/2;
		if(pairs[mid].F<x || (pairs[mid].F==x && pairs[mid].S.F<y) || (pairs[mid].F==x && pairs[mid].S.F==y && t[mid]==1)) l=mid;
		else r=mid;
	}
	t[r]=1;
	return pairs[r].S.S;
}
void solve(int x){
	f(i,1,2*n+1) b[i]=a[i]%(1<<x);
	f(i,1,n+1)
		add_edge(b[i*2-1],b[i*2],i*2-1);
	
	f(i,0,(1<<x)){
		if(g[i].size()){
			eulor(i);
			break;
		}
	}
	sort(pairs.begin(),pairs.end());
	f(i,0,tour.size()-1){
		int u=Get(min(tour[i],tour[i+1]),max(tour[i],tour[i+1]));
		if(tour[i]>tour[i+1])
			cout<<mat(u)<<" "<<u<<" ";
		else
			cout<<u<<" "<<mat(u)<<" ";
	}
}
int main(){
	cin>>n;
	f(i,1,n+1)
		Gett(a[i*2-1],a[i*2]);
	f_(q,20,0)
		if(check(q)){ mx=q; break; }
	cout<<mx<<'\n';
	solve(mx);
	print(ans,ans.size());
}