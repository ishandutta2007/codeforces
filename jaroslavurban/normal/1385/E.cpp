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
int n,m;
vector<int>in[N],out[N];
bool vis[N];
int p[N];
int main(){
	cin.tie(0);cin.sync_with_stdio(0);
	int t;cin>>t;
	while(t--){
		cin>>n>>m;
		memset(vis,0,sizeof(vis));
		memset(p,0,sizeof(p));
		for(int i=1;i<=n;++i)in[i].clear();
		for(int i=1;i<=n;++i)out[i].clear();
		vector<pair<int,int>>e;
		for(int i=0;i<m;++i){
			int t,u,v;cin>>t>>u>>v;
			if(t){
				in[v].push_back(u);
				out[u].push_back(v);
			}
			e.push_back({u,v});
		}
		queue<int>q;
		for(int i=1;i<=n;++i)if(in[i].empty())q.push(i);
		int place=1;
		while(q.size()){
			int u=q.front();q.pop();
			vis[u]=true;
			p[u]=place++;
			for(auto v:out[u]){
				in[v].pop_back();
				if(in[v].empty())q.push(v);
			}
		}
		bool pos=true;
		for(int i=1;i<=n;++i)if(!vis[i])pos=false;
		if(!pos){cout<<"NO\n";continue;}
		cout<<"YES\n";
		for(auto ee:e)if(p[ee.first]<p[ee.second])cout<<ee.first<<" "<<ee.second<<endl;
			else cout<<ee.second<<" "<<ee.first<<endl;
	}

}