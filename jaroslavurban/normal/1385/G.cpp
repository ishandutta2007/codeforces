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
 
const int N=200010;
int r[2][N],c[2][N],a[N],b[N];
int n;
vector<pair<int,bool>>g[N];
bool vis[N];
vector<int>c1,c2;
void dfs(int i,bool col){
	if(vis[i])return;
	vis[i]=true;if(col)c1.push_back(i);else c2.push_back(i);
	for(auto e:g[i])dfs(e.first,e.second?col:!col);
}
int main(){
	cin.tie(0);cin.sync_with_stdio(0);
	int t;cin>>t;
	while(t--){
		cin>>n;
		for(int i=0;i<n;++i)g[i].clear();
		memset(r,-1,sizeof(r));
		memset(c,-1,sizeof(c));
		memset(vis,0,sizeof(vis));
		bool pos=true;
		for(int i=0;i<n;++i){
			int col;cin>>col;a[i]=col;
			if(~r[0][col]){
				if(~r[1][col])pos=false;
				c[1][col]=i;
				r[1][col]=1;
			}else{
				c[0][col]=i;
				r[0][col]=1;
			}
		}
		for(int i=0;i<n;++i){
			int col;cin>>col;b[i]=col;
			if(~r[0][col]){
				if(~r[1][col])pos=false;
				c[1][col]=i;
				r[1][col]=2;
			}else{
				c[0][col]=i;
				r[0][col]=2;
			}
		}
		if(!pos){cout<<-1<<endl;continue;}
		for(int i=0;i<n;++i){
			if(c[0][a[i]]!=i&&r[0][a[i]]==1)g[i].push_back({c[0][a[i]],0});
			if(c[0][a[i]]!=i&&r[0][a[i]]==2)g[i].push_back({c[0][a[i]],1});
			if(c[1][a[i]]!=i&&r[1][a[i]]==1)g[i].push_back({c[1][a[i]],0});
			if(c[1][a[i]]!=i&&r[1][a[i]]==2)g[i].push_back({c[1][a[i]],1});

			if(c[0][b[i]]!=i&&r[0][b[i]]==1)g[i].push_back({c[0][b[i]],1});
			if(c[0][b[i]]!=i&&r[0][b[i]]==2)g[i].push_back({c[0][b[i]],0});
			if(c[1][b[i]]!=i&&r[1][b[i]]==1)g[i].push_back({c[1][b[i]],1});
			if(c[1][b[i]]!=i&&r[1][b[i]]==2)g[i].push_back({c[1][b[i]],0});
			assert(g[i].size()==2||g[i].empty());
		}
		vector<int>r;
		for(int i=0;i<n;++i){
			if(a[i]==b[i])continue;

			c1.clear();c2.clear();
			if(!vis[i])dfs(i,0);
			if(c1.size()>c2.size())r.insert(r.end(),c2.begin(),c2.end());
			else r.insert(r.end(),c1.begin(),c1.end());
		}
		cout<<r.size()<<endl;
		for(auto cc:r)cout<<cc+1<<" ";
		cout<<endl;
	}
}