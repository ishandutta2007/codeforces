#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<string, lint> pi;
const int mod = 1e9 + 7;

const int MAXN = 500005;
struct disj{
	int pa[MAXN], sz[MAXN];
	void init(int n){
		for(int i=0; i<=n; i++){
			pa[i] = i;
			sz[i] = 1;
		}
	}
	int find(int x){
		return pa[x] = (pa[x] == x ? x : find(pa[x]));
	}
	bool uni(int p, int q){
		p = find(p);
		q = find(q);
		if(p == q) return 0;
		pa[q] = p;
		sz[p] += sz[q];
		return 1;
	}
}disj;
int n, m, k;
vector<int> gph[200005];
vector<int> dfn;

void dfs(int x, int p){
	dfn.push_back(x);
	for(auto &i : gph[x]){
		if(i != p){dfs(i, x);
			dfn.push_back(x);
		}
	}
}

int main(){
	cin >> n >> m >> k;
	disj.init(n);
	for(int i=0; i<m; i++){
		int s, e;
		scanf("%d %d",&s,&e);
		if(disj.uni(s, e)){
			gph[s].push_back(e);
			gph[e].push_back(s);
		}
	}
	dfs(1, 0);
	int s = 0;
	int l = (2 * n + k - 1) / k;
	for(int i=0; i<k; i++){
		int ok = dfn.size() - (k - i);
		ok = min(ok, s + l - 1);
		printf("%d ", ok - s + 1);
		for(int j=s; j<=ok; j++){
			printf("%d ",dfn[j]);
		}
		s = ok + 1;
		puts("");
	}
	
}