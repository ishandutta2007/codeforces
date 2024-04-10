#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;
//#define int ll
//#define endl '\n'
 
// use unique(x) - removec consecutive items, returns vec.begin() + number of items
// for vector: sort(all(vec)); vec.erase(unique(all(vec)), vec.end());
// use iota(all(vec), 0) for filling a vector with 0,1,2...
// use fill(all(vec), 1) for filling a vector with 1,1,1...
// use rotate(vec.begin(), vec.begin() + 1, vec.end()) to rotate a vector | middle arg becomes first
// print number in binary -> cout << bitset<20>(n);

 
const int N=500100;
set<int>w[N],b[N];
int n,m,color[N],vis[N],dist[N];
main(){
	cin.tie(0);cin.sync_with_stdio(0);
	cin>>n>>m;
	for(int i=0;i<m;++i){
		int u,v,c;cin>>u>>v>>c;--u;--v;
		if(c)w[v].insert(u);
		else b[v].insert(u);
	}
	memset(color,-1,sizeof(color));
	memset(dist,-1,sizeof(dist));
	queue<int>q;
	q.push(n-1);
	vis[n-1]=true;
	dist[n-1]=0;
	while(!q.empty()){
		int u=q.front();q.pop();
		for(auto it=w[u].begin();it!=w[u].end();++it)
			if(!vis[*it]){
				if(b[u].count(*it)||color[*it]==1){
					q.push(*it);
					vis[*it]=true;
					dist[*it]=dist[u]+1;
				}
				else color[*it]=0;
			}
		for(auto it=b[u].begin();it!=b[u].end();++it)
			if(!vis[*it]){
				if(-1==color[*it])color[*it]=1;
				else if(color[*it]==0){
					q.push(*it);
					vis[*it]=true;
					dist[*it]=dist[u]+1;
				}
			}
	}
	cout<<dist[0]<<endl;
	for(int i=0;i<n;++i)cout<<(color[i]==-1?0:color[i]);cout<<endl;
}