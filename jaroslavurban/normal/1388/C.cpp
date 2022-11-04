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

const int N=100010;
int n,m;
int p[N],h[N];
vector<int>g[N];
bool pos;

pair<int,int> dfs(int u,int pa){//total, minh
	int minh=0,total=p[u];
	for(auto v:g[u])if(v!=pa){
		auto r=dfs(v,u);
		total+=r.first;
		minh+=r.second;
	}
	if(total%2!=abs(h[u])%2||abs(h[u])>total){
		//cerr<<u<<" "<<total<<" "<<h[u]<<endl;
		pos=false;
	}
	int reph=(total+h[u])/2;
	if(reph<minh){
		//cerr<<u<<" reph "<<reph<<" "<<minh<<endl;
		pos=false;
	}
	return {total,reph};
}


main(){
	cin.tie(0);cin.sync_with_stdio(0);
	int tc;cin>>tc;
	while(tc--){
		cin>>n>>m;
		pos=true;
		for(int i=0;i<n;++i)cin>>p[i];
		for(int i=0;i<n;++i)cin>>h[i];
		for(int i=0;i<n;++i)g[i].clear();
		for(int i=0;i<n-1;++i){
			int u,v;cin>>u>>v;--u;--v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		dfs(0,0);
		if(pos)cout<<"YES\n";
		else cout<<"NO\n";
	}
}