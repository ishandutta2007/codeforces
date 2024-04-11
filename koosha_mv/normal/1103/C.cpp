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
#define ops(x) cout<<x<<" !"<<endl
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define Add(x,y) x=(x+y)%mod
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=5e5+99;

int n,m,k,u,v,c,p,h[N],par[N],path[N],mark[N],vis[N],cycle[N][3];
vector<int> g[N];

void dfs(int x,int dist){
	int io=0,son=0;
	h[x]=dist;
	mark[x]=1;
	if(!c) path[dist]=x;
	if(dist+1>=n/k+(n%k>0)) c=1;
	f(i,0,g[x].size())
		if(!mark[g[x][i]])
			par[g[x][i]]=x,dfs(g[x][i],dist+1),son++;
	if(son==0)
		f(i,0,3)
			f(j,0,3)
				if(i!=j && h[g[x][i]]>h[g[x][j]] && (h[g[x][i]]-h[g[x][j]])%3!=1 && !io)
					cycle[p][0]=g[x][j],cycle[p][1]=x,cycle[p][2]=g[x][i],io=1,p++;
}
void case1(){
	cout<<"PATH"<<endl<<(n+k-1)/k<<endl;
	f(i,0,(n+k-1)/k)
		cout<<path[i]<<" ";
}
void case2(){
	cout<<"CYCLES"<<endl;
	f(i,0,k){
		vector<int> ans;
		ans.pb(cycle[i][1]);
		ans.pb(cycle[i][2]);
		for(int u=par[cycle[i][2]];u!=cycle[i][0];u=par[u])
			ans.pb(u);
		ans.pb(cycle[i][0]);
		cout<<ans.size()<<endl;
		print(ans,ans.size());
	}
}

int main(){
	cin>>n>>m>>k;
	f(i,0,m){
		Gett(u,v);
		g[u].pb(v);
		g[v].pb(u);
	}
	dfs(1,0);
	if(c) case1();
	else case2();
}