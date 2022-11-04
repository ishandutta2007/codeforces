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

int n,m;
const int N=100010;
set<int>lft,g[N];

main(){
	cin.tie(0);cin.sync_with_stdio(0);
	cin>>n>>m;
	for(int i=0;i<m;++i){
		int u,v;cin>>u>>v;--u;--v;
		g[u].insert(v);
		g[v].insert(u);
	}
	for(int i=0;i<n;++i)lft.insert(i);
	int comps=0;
	for(int i=0;i<n;++i)if(lft.count(i)){
		++comps;
		queue<int>q;q.push(i);lft.erase(i);
		while(q.size()){
			int u=q.front();q.pop();
			vector<int>neigh;
			for(auto v:lft)if(!g[u].count(v))neigh.push_back(v);
			for(auto uu:neigh){
				q.push(uu);
				lft.erase(uu);
			}
		}
	}
	cout<<comps-1<<endl;
}