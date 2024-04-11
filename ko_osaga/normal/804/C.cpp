#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;
const int mod = 1e9 + 7;

vector<int> gph[300005];
vector<int> col[300005];
int chk[300005];
int n, m;

void dfs(int x, int p){
	set<int> s;
	for(auto &i : col[x]){
		if(chk[i]) s.insert(chk[i]);
	}
	int q = 1;
	for(auto &i : col[x]){
		if(!chk[i]){
			while(s.find(q) != s.end()) q++;
			chk[i] = q;
			q++;
		}
	}
	for(auto &i : gph[x]){
		if(i != p){
			dfs(i, x);
		}
	}
}

int main(){
	scanf("%d %d",&n,&m);
	for(int i=1; i<=n; i++){
		int x;
		scanf("%d",&x);
		col[i].resize(x);
		for(auto &j : col[i]) scanf("%d", &j);
	}
	for(int i=1; i<n; i++){
		int s, e;
		scanf("%d %d",&s,&e);
		gph[s].push_back(e);
		gph[e].push_back(s);
	}
	dfs(1, -1);
	for(int i=1; i<=m; i++) if(!chk[i]) chk[i] = 1;
	printf("%d\n", *max_element(chk + 1, chk + m + 1));
	for(int i=1; i<=m; i++) printf("%d ", chk[i]);
}