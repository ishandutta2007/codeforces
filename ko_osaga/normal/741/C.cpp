#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;

vector<int> gph[200005];
int vis[200005];
int n, a[100005], b[100005];

void dfs(int x, int c){
	if(vis[x]) return;
	vis[x] = c;
	for(auto &i : gph[x]){
		dfs(i, 3-c);
	}
}

int main(){
	cin >> n;
	for(int i=1; i<=n; i++){
		gph[2*i-1].push_back(2*i);
		gph[2*i].push_back(2*i-1);
	}
	for(int i=0; i<n; i++){
		scanf("%d %d",&a[i],&b[i]);
		gph[a[i]].push_back(b[i]);
		gph[b[i]].push_back(a[i]);
	}
	for(int i=1; i<=2*n; i++){
		if(!vis[i]) dfs(i, 1);
	}
	for(int i=0; i<n; i++){
		printf("%d %d\n", vis[a[i]], vis[b[i]]);
	}
}