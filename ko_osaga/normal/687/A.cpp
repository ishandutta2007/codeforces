#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;
typedef vector<int> vi;

int n, m;
vector<int> gph[100005];
int v[100005];
bool bad;

void dfs(int x, int c){
	if(v[x]){
		if(v[x] != c) bad = 1;
		return;
	}
	v[x] = c;
	for(auto &i : gph[x]){
		dfs(i, 3-c);
	}
}

int main(){
	cin >> n >> m;
	for(int i=0; i<m; i++){
		int u, v;
		cin >> u >> v;
		gph[u].push_back(v);
		gph[v].push_back(u);
	}
	for(int i=1; i<=n; i++){
		if(!v[i]) dfs(i, 1);
	}
	if(bad){
		puts("-1");
	}
	else{
		printf("%d\n", count(v+1, v+n+1, 1));
		for(int i=1; i<=n; i++){
			if(v[i] == 1) printf("%d ", i);
		}
		printf("\n%d\n", count(v+1, v+n+1, 2));
		for(int i=1; i<=n; i++){
			if(v[i] == 2) printf("%d ", i);
		}
	}
}