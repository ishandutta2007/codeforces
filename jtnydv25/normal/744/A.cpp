#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sd(x) scanf("%d", &(x))
#define pb push_back
const int N = 1005;
int C[N], vis[N], cmp = 0, special[N], component_size[N], scmp[N];
vector<int> con[N];
void dfs(int s){
	vis[s] = 1; C[s] = cmp; component_size[cmp] ++;
	if(special[s]) scmp[cmp] = 1;
	for(int v : con[s]){
		if(!vis[v]) dfs(v);
	}
}
int getcmp(int n){
	for(int i = 1; i <= n; i++){
		if(!vis[i]){ ++ cmp; dfs(i);}
	}
}
inline ll C2(int n){ return (n * 1ll * (n - 1)) >> 1;}
int main(){
	int n, m, k, u, v;
	sd(n), sd(m), sd(k);
	for(int i = 1; i <= k; i++){
		sd(u); special[u] = 1;
	}
	for(int i = 1; i <= m; i++){
		sd(u), sd(v);
		con[u].pb(v); con[v].pb(u);
	}
	getcmp(n);
	ll finaledge = 0;
	int x = 0, y = 0;
	for(int i = 1; i <= cmp; i++){
		if(scmp[i]){
			finaledge += C2(component_size[i]);
			y = max(y, component_size[i]);
		}
		else x += component_size[i];
	}
	cerr << x << " " << y << endl;
	finaledge += x * 1ll * y + C2(x);
	cout << finaledge - m ;
}