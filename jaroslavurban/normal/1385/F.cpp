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
int n,k;
vector<int>g[N];
int cnte[N];
int main(){
	cin.tie(0);cin.sync_with_stdio(0);
	int t;cin>>t;
	while(t--){
		cin>>n>>k;
		for(int i=0;i<n;++i)g[i].clear();
		memset(cnte,0,sizeof(cnte));
		for(int i=0;i<n-1;++i){
			int u,v;cin>>u>>v;--u;--v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		if(k==1){cout<<n-1<<endl;continue;}
		int cnt=0,lu=-1,res=0;
		queue<pair<int,int>>q;
		for(int i=0;i<n;++i)if(g[i].size()==1&&++cnte[g[i][0]]==k)q.push({-++cnt,g[i][0]});
		lu=q.size()+1;
		while(q.size()&&-q.front().first<lu){
			int u=q.front().second;q.pop();
			res+=cnte[u]/k;
			if(cnte[u]>=k){
				int r=0;
				for(auto it=g[u].end()-1;r<cnte[u]/k*k&&it!=g[u].begin()-1;--it)if(g[*it].size()==1){
					g[*it].clear();
					g[u].erase(it);
					++r;
				}
				lu=cnt+q.size()+10;
				if(g[u].size()==1)++cnte[g[u][0]];
			}
			cnte[u]-=cnte[u]/k*k;
			if(g[u].size()>1)q.push({-++cnt,u});
			else if(g[u].size()==1&&cnte[g[u][0]]==k)q.push({-++cnt,g[u][0]});
		}
		cout<<res<<endl;
	}
}