#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<lint, lint> pi;
const int mod = 1e9 + 7;

int n;
vector<int> gph[200005];
int col[200005];

void dfs(int x, int p, int c){
	int cur = 1;
	for(auto &j : gph[x]){
		if(p == j) continue;
		while(cur == c || cur == col[x]) cur++;
		col[j] = cur;
		dfs(j, x, col[x]);
		cur++;
	}
}

int main(){
	scanf("%d",&n);
	for(int i=0; i<n-1; i++){
		int s, e;
		scanf("%d %d",&s,&e);
		gph[s].push_back(e);
		gph[e].push_back(s);
	}
	col[1] = 1;
	dfs(1, 0, 1);
	printf("%d\n", *max_element(col+1, col+n+1));
	for(int i=1; i<=n; i++) printf("%d ", col[i]);
}