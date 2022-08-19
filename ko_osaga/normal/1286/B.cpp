#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
using lint = long long;
using pi = pair<lint, lint>;
const int MAXN = 2005;
const lint inf = 1e17;

int n, p[MAXN], c[MAXN], ans[MAXN];
vector<int> gph[MAXN];
int sz[MAXN];

void prec(int x){
	sz[x] = 1;
	for(auto &i : gph[x]){
		prec(i);
		sz[x] += sz[i];
	}
}

void dfs(int r, vector<int> v){
	ans[r] = v[c[r]];
	v.erase(v.begin() + c[r]);
	for(auto &i : gph[r]){
		vector<int> w;
		for(int j=0; j<sz[i]; j++){
			w.push_back(v.back());
			v.pop_back();
		}
		reverse(all(w));
		dfs(i, w);
	}
}

int main(){
	cin >> n;
	int root = 0;
	for(int i=1; i<=n; i++){
		cin >> p[i] >> c[i];
		if(p[i]) gph[p[i]].push_back(i);
		else root = i;
	}
	vector<int> cnd(n); iota(all(cnd), 1);
	prec(root);
	for(int i=1; i<=n; i++){
		if(sz[i] <= c[i]){
			puts("NO");
			return 0;
		}
	}
	dfs(root, cnd);
	puts("YES");
	for(int i=1; i<=n; i++) cout << ans[i] << " ";
}