#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int N=300100;
int n,k;
int par[N],child[N];
vector<vector<int>>g,comp,gr,g2;

bool kahn(vector<vector<int>>g,vector<int>&res){
	int n=g.size();
	vector<int>incnt(n);
	for(int u=0;u<n;++u)
		for(auto v:g[u])
			++incnt[v];
	queue<int>q;
	for(int u=0;u<n;++u)if(!incnt[u])q.push(u);
	while(q.size()){
		int u=q.front();q.pop();
		res.push_back(u);
		for(auto v:g[u])if(!--incnt[v])q.push(v);
	}
	return res.size()==n;
}

int dfs(int u,int p){
	if(u==-1)return true;
	par[u]=p;
	comp[p].push_back(u);
	dfs(child[u],p);
}

main(){
	cin.tie(0);cin.sync_with_stdio(0);
	cin>>n>>k;
	memset(child,-1,sizeof(*child)*n);
	memset(par,-1,sizeof(*par)*n);
	g.resize(n);
	gr.resize(n);
	comp.resize(n);
	for(int i=0;i<n;++i){int p;cin>>p;if(p)g[p-1].push_back(i);}
	g2=g;
	for(int i=0;i<k;++i){
		int x,y;cin>>x>>y;--x;--y;
		child[x]=y;
		par[y]=x;
		g2[x].push_back(y);
	}
	vector<int>tmp;
	if(!kahn(g2,tmp)){cout<<"0\n";return 0;}
	for(int i=0;i<n;++i)if(par[i]==-1)dfs(i,i);
	for(int i=0;i<n;++i){
		for(auto v:g[i])if(par[v]!=par[i])gr[par[v]].push_back(par[i]);
	}
//	for(int i=0;i<n;++i){
//		if(par[i]==i){
//			cout<<i+1<<endl;
//			for(auto v:comp[i])cout<<v+1<<" ";
//			cout<<endl;
//			for(auto v:gr[i])cout<<v+1<<" ";
//			cout<<endl;
//			cout<<endl;
//		}
//	}
	tmp.clear();
	if(!kahn(gr,tmp)){cout<<"0\n";return 0;}
	reverse(tmp.begin(),tmp.end());
	for(int i=0;i<tmp.size();++i){
		for(auto v:comp[tmp[i]])cout<<v+1<<" ";
	}
	cout<<endl;
}