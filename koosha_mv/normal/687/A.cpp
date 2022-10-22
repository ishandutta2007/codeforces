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

int n,m,t,u1,u2,mark[N];
vector<int> v[2],g[N];
bool dist[N];

void dfs(int x){
	mark[x]=1;
	v[dist[x]].pb(x);
	f(i,0,g[x].size()){
		if(!mark[g[x][i]])
			dist[g[x][i]]=dist[x]^1,dfs(g[x][i]);
		if(mark[g[x][i]] && dist[x]==dist[g[x][i]]){
			cout<<-1;
			exit(0);
		}
	}
}

int main(){
	cin>>n>>m;
	f(i,0,m){
		Gett(u1,u2);
		g[u1].pb(u2);
		g[u2].pb(u1);
	}
	f(i,1,n+1)
		if(!mark[i])
			dfs(i);
	f(i,0,2){
		cout<<v[i].size()<<endl;
		f(j,0,v[i].size()) cout<<v[i][j]<<" "; cout<<endl;
	}
}