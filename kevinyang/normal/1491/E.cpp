#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
vector<set<int>>adj(200005);
vector<int>sz(200005);
vector<int>parent(200005);
bool ans = true;
vector<int>fib(51);
vector<int>nodes;
void dfs(int u, int p){
	sz[u] = 1;
	nodes.push_back(u);
	for(int nxt: adj[u]){
		if(nxt==p)continue;
		dfs(nxt,u);
		sz[u]+=sz[nxt];
	}
	parent[u] = p;
}
void f(int x, int idx){
	if(idx<=2)return;
	dfs(x,x);
	for(int i = 0; i<nodes.size(); i++){
		int nxt = nodes[i];
		if(nxt==x)continue;
		if(sz[nxt]==fib[idx-2]||sz[nxt]==fib[idx-1]){
			int u = parent[nxt];
			adj[u].erase(nxt);
			adj[nxt].erase(u);
			nodes.clear();
			if(sz[nxt]==fib[idx-2]){
				f(nxt,idx-2); f(u,idx-1);
			}
			else{
				f(nxt,idx-1); f(u,idx-2);
			}
			return;
		}
	}
	ans = false;
}
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n;
	fib[1] = 1;
	for(int i = 2; i<=50; i++){
		fib[i] = fib[i-1]+fib[i-2];
	}
	for(int i = 0; i<n-1; i++){
		int x,y;
		cin >> x >> y;
		adj[x].insert(y);
		adj[y].insert(x);
	}
	if(*lower_bound(fib.begin(),fib.end(),n)!=n){
		cout << "NO\n";
		return 0;
	}
	f(1,lower_bound(fib.begin(),fib.end(),n)-fib.begin());
	if(ans)cout << "YES\n";
	else cout << "NO\n";
	return 0;
}