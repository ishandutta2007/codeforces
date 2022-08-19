#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;

vector<int> gph[100005];
vector<int> col[100005];
int dfn[100005], piv, par[100005], sz[100005];
int a[100005];

void dfs(int x, int p){
	dfn[x] = ++piv;
	par[x] = p;
	sz[x] = 1;
	for(auto &i : gph[x]) if(i != p) dfs(i, x), sz[x] += sz[i];
}

bool same(int s, int e){
	if(s > e) return 1;
	e++;
	int k = a[s];
	return (lower_bound(col[k].begin(), col[k].end(), e) - lower_bound(col[k].begin(), col[k].end(), s))
		== (e - s);
}

int main(){
	int n;
	scanf("%d",&n);
	for(int i=0; i<n-1; i++){
		int s, e;
		scanf("%d %d",&s,&e);
		gph[s].push_back(e);
		gph[e].push_back(s);
	}
	dfs(1, 0);
	for(int i=1; i<=n; i++){
		scanf("%d",&a[dfn[i]]);
		col[a[dfn[i]]].push_back(dfn[i]);
	}
	for(int i=1; i<=100000; i++) sort(col[i].begin(), col[i].end());
	for(int i=1; i<=n; i++){
		int ok = 1;
		for(auto &j : gph[i]){
			if(j != par[i]){
				if(!same(dfn[j], dfn[j] + sz[j] - 1)){
					ok = 0;
				}
			}
			else{
				if(!same(1, dfn[i] - 1) || !same(dfn[i] + sz[i], n)){
					ok = 0;
				}
				if(dfn[i] + sz[i] != n+1 && a[dfn[i] - 1] != a[dfn[i] + sz[i]]){
					ok = 0;
				}
			}
		}
		if(ok){
			printf("YES\n%d", i);
			return 0;
		}
	}
	puts("NO");
}