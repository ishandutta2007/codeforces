#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define is_bit(x,y) (x%(1<<(y+1))>=(1<<y))
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);																																														
#define ops(x) cout<<x<<" !"<<endl;
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define Add(x,y) x=(x+y)%mod;
#define lst(x) x[x.size()-1]
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=5e5+99;

int n,m,t,u,v,c,deg[N],mark[N],fr[N][2];
set<pair<int,int> > s;
pair<int,int> ans[N];
vector<int> g[N];

void kill(){
	cout<<"DEAD";
	exit(0);
}
void add(int x){
	s.erase(mp(deg[x],x));
	s.insert(mp(deg[x]+1,x));
	deg[x]++;
}
void find_topo_sort(){
	while(s.size()){
		pair<int,int> u=*s.rbegin();
		s.erase(u);
		v=u.S;
		if(u.F<0) kill();
		mark[v]=++c;
		f(i,0,g[v].size())
			if(!mark[g[v][i]])
				add(g[v][i]);
	}
}
void do_it(){
	f(i,0,m){
		u=min(mark[fr[i][0]],mark[fr[i][1]]);
		ans[i]=mp(u,i+1);
	}
}

int main(){
	cin>>n>>m;
	f(i,1,n+1) cin>>deg[i];
	f(i,0,m){
		Gett(u,v);
		fr[i][0]=u,fr[i][1]=v;
		g[u].pb(v);
		g[v].pb(u);
		deg[u]--,deg[v]--;
	}
	f(i,1,n+1)
		s.insert(mp(deg[i],i));
	find_topo_sort();
	do_it();
	sort(ans,ans+m);
	cout<<"ALIVE"<<endl;
	f_(i,m-1,0) cout<<ans[i].S<<" ";
}