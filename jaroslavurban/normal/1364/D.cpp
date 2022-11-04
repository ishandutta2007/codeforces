#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
// use unique(x) - removec consecutive items, returns vec.begin() + number of items
// for vector: sort(all(vec)); vec.erase(unique(all(vec)), vec.end());
// use iota(all(vec), 0) for filling a vector with 0,1,2...
// use fill(all(vec), 1) for filling a vector with 1,1,1...
// use rotate(vec.begin(), vec.begin() + 1, vec.end()) to rotate a vector | middle arg becomes first
// use merge(all(vec1), all(vec2), vec3.begin()) to merge 2 vectors, use vec3.resize(vec1.size() + vec2.size()) first
// ll pos = partition_point(all(vec), pred) - vec.begin(); bool pred(ll a){return a<3};
// print number in binary -> cout << bitset<20>(n);

vector<vector<int>>g;
vector<bool>vis;
vector<bool>colored;
vector<int>par;
vector<bool>col;
vector<int>b;
vector<int>w;
int main(){
	int n,m,k;cin>>n>>m>>k;
	g.resize(n);
	vis.resize(n);
	col.resize(n);
	colored.resize(n);
	par.resize(n);
	for(int i=0;i<m;++i){
		int u,v;cin>>u>>v;
		--u;--v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	queue<int>q;
	vis[0]=true;
	par[0]=0;
	col[0]=0;
	q.push(0);
	int trouble,u;
	while(!q.empty()){
		u=q.front();q.pop();
//		cerr<<u<<endl;
		int c=!col[par[u]];
		trouble=-1;
		for(auto v:g[u]){
			if(colored[v]&&col[v]!=!c)trouble=v;
//			cerr<<vis[v]<<" "<<v<<endl;
			if(!vis[v]){
//				cerr<<"pushed: "<<v<<endl;
				q.push(v);
				par[v]=u;
				vis[v]=true;
			}
		}
//		cerr<<"t: "<<trouble<<endl;
		if(~trouble){break;}
//		cerr<<u<<endl;
		if(c)b.push_back(u);
		else w.push_back(u);
		col[u]=c;
		colored[u]=true;
	}
	if(k/2+k%2<=b.size()){
		cout<<1<<endl;
		for(int i=0;i<k/2+k%2;++i)cout<<b[i]+1<<" ";
		cout<<endl;
		return 0;
	}
	if(k/2+k%2<=w.size()){
		cout<<1<<endl;
		for(int i=0;i<k/2+k%2;++i)cout<<w[i]+1<<" ";
		cout<<endl;
		return 0;
	}
//	cerr<<k/2+k%2<<" "<<b.size()<<" "<<w.size()<<endl;
	cout<<2<<endl;
	vector<int>c;
	vector<int>c2;
//	cerr<<trouble<<endl;
	for(;u!=0;u=par[u])c.push_back(u);
	for(;trouble!=0;trouble=par[trouble])c2.push_back(trouble);
	c.push_back(0);
	c2.push_back(0);
	int sm=0;
	for(int i=c.size()-1,j=c2.size()-1;i>=0&&j>=0&&c[i]==c2[j];++sm,--i,--j){}
	cout<<c.size()-sm+c2.size()-sm+1<<endl;
	for(int i=0;i<c.size()-sm;++i)cout<<c[i]+1<<" ";
	cout<<c[c.size()-sm]+1<<" ";
	for(int i=c2.size()-1-sm;i>=0;--i)cout<<c2[i]+1<<" ";
	cout<<endl;

//	cerr<<u<<endl;
//	for(int i=0;i<c.size();++i)cerr<<c[i]<<" ";
//	cerr<<endl;
//	cerr<<trouble<<endl;
//	for(int i=0;i<c2.size();++i)cerr<<c2[i]<<" ";
//	cerr<<endl;
}