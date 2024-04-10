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

const int N=200010,K=10;
int n,m,k,res;
vector<pair<int,int>>g[N],gr[N];
bool banned[K][K][K][K];
int perm[K];

void dfs(int pos){
	if(pos==k){
		for(int i=0;i<k;++i)
			for(int j=i;j<k;++j)
				if(banned[i][perm[i]][j][perm[j]])
					return;
	//	for(int i=0;i<k;++i)cerr<<perm[i]<<" ";cerr<<endl;
		++res;return;
	}
	for(int i=0;i<=pos;++i){
		perm[pos]=i;
		dfs(pos+1);
	}
}

main(){
	cin.tie(0);cin.sync_with_stdio(0);
	cin>>n>>m>>k;
	for(int i=0;i<m;++i){
		int u,v,w;cin>>u>>v>>w;--u;--v;
		g[u].push_back({w,v});
	}
	for(int i=0;i<n;++i)sort(g[i].begin(),g[i].end());
//	for(int i=0;i<n;++i)cerr<<g[i][g[i].size()-1].second<<endl;
	bool pos=1;
	for(int i=0;i<n;++i){
		if(!g[i].size())pos=0;
		for(int j=0;j<g[i].size();++j)
			gr[g[i][j].second].push_back({g[i].size()-1,j});
	}
	for(int i=0;i<n;++i){
		bool have[K][K]={};
		for(int j=0;j<gr[i].size();++j){
			int a=gr[i][j].first,b=gr[i][j].second;
			if(have[a][b])banned[a][b][a][b]=1;
			have[a][b]=1;
		}
		for(int a=0;a<k;++a)
			for(int b=0;b<k;++b)
				if(have[a][b])
					for(int c=0;c<k;++c)
						for(int d=0;d<k;++d)
							if(have[c][d]&&(a!=c||b!=d))
								banned[a][b][c][d]=1;
	}
	dfs(0);
	cout<<pos*res<<endl;
}