/*
                                                  
  _|_|                              _|  _|    _|  
_|    _|  _|  _|_|  _|_|_|_|        _|  _|  _|    
_|    _|  _|_|          _|          _|  _|_|      
_|    _|  _|          _|      _|    _|  _|  _|    
  _|_|    _|        _|_|_|_|    _|_|    _|    _|  
                                                                                                    
*/ 
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<vector>
#include<queue>
#include<set>
#include<map>
//#define ls (rt<<1)
//#define rs (rt<<1|1)
#define vi vector<int>
#define pb push_back
#define mk make_pair
#define pii pair<int,int>
#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;i++)
#define fi first
#define se second
typedef long long ll;
using namespace std;
const int maxn=1e5+1000;
vi side[maxn],edge[maxn];
int u[maxn];
pii c[maxn];
int dfn[maxn],low[maxn],idx,stk[maxn],top,size[maxn],scc[maxn],scc_cnt;
void tarjan(int u){
	dfn[u]=low[u]=++idx;stk[++top]=u;
	for(int i=0;i<side[u].size();i++){
		int v=side[u][i];
		if(!dfn[v])tarjan(v),low[u]=min(low[u],low[v]);
		else if(!scc[v])low[u]=min(low[u],dfn[v]);
	}
	if(dfn[u]==low[u]){
		int x;scc_cnt++;
		do{
			x=stk[top--];
			scc[x]=scc_cnt;
			size[scc_cnt]++;
		}while(dfn[x]!=low[x]);
	}
}
map<pii,int>ck;
int in[maxn];
int main(){
	ios::sync_with_stdio(0);
	int n,m,h;cin>>n>>m>>h;
	rep(i,1,n)cin>>u[i];
	rep(i,1,m){
		int a,b;
		cin>>a>>b;c[i]=mk(a,b);
		if((u[a]+1)%h==u[b])
		side[b].pb(a);
		if((u[b]+1)%h==u[a])
		side[a].pb(b);
	}
	rep(i,1,n)if(!dfn[i])tarjan(i);
	rep(i,1,n){
		for(int j=0;j<side[i].size();j++){
			int v=side[i][j];
			if(!ck[mk(scc[i],scc[v])]&&scc[i]!=scc[v]){ck[mk(scc[i],scc[v])]=1;edge[scc[i]].pb(scc[v]);in[scc[v]]++;}
		}
	}
	
	int mi=1e9,loc=0;
	rep(i,1,scc_cnt)if(!in[i]&&size[i]<mi){mi=size[i],loc=i;}
	cout<<mi<<endl;
	rep(i,1,n)if(scc[i]==loc)cout<<i<<' ';
	return 0;
}