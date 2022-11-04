#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define int ll
// use unique(x) - removec consecutive items, returns vec.begin() + number of items
// for vector: sort(all(vec)); vec.erase(unique(all(vec)), vec.end());
// use iota(all(vec), 0) for filling a vector with 0,1,2...
// use fill(all(vec), 1) for filling a vector with 1,1,1...
// use rotate(vec.begin(), vec.begin() + 1, vec.end()) to rotate a vector | middle arg becomes first
// use merge(all(vec1), all(vec2), vec3.begin()) to merge 2 vectors, use vec3.resize(vec1.size() + vec2.size()) first
// ll pos = partition_point(all(vec), pred) - vec.begin(); bool pred(ll a){return a<3};
// print number in binary -> cout << bitset<20>(n);

const int N=500010;
int s[N][2];
int a[2*N];
int n;
vector<int>g[N];
bool vis[N];
bool dfs(int u,int p){
	if(vis[u])return false;
	vis[u]=true;
	bool pos=true;
	for(auto v:g[u])if(p!=v)pos&=dfs(v,u);
	return pos;
}
main(){
	cin.tie(0);cin.sync_with_stdio(0);
	cin>>n;
	for(int i=0;i<n;++i){
		cin>>s[i][0]>>s[i][1];
		a[--s[i][0]]=i;a[--s[i][1]]=i;
	}
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
	bool pos=true;
	int inter=0;
	for(int i=0;i<2*n;++i){
		if(s[a[i]][0]==i){
			while(!q.empty()&&q.top().first<i)q.pop();
			vector<pair<int,int>>p;
			while(!q.empty()&&q.top().first<s[a[i]][1]){
				p.push_back(q.top());q.pop();
			}
			for(auto v:p){
				++inter;
				g[v.second].push_back(a[i]);
				g[a[i]].push_back(v.second);
				q.push(v);
			}
			if(inter>=n-1)break;
			q.push({s[a[i]][1],a[i]});
		}
	}
	memset(vis,0,sizeof(vis));
	pos=dfs(0,0);
	for(int i=0;i<n;++i)if(!vis[i])pos=false;
	if(pos)cout<<"YES\n";
	else cout<<"NO\n";
}