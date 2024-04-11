#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;
const int mod = 1e9 + 7;
const int MAXN = 100005;

vector<int> gph[MAXN];
int n, sz[MAXN], par[MAXN];

void dfs(int x, int p = -1){
	sz[x] = 1;
	for(auto &i : gph[x]){
		if(i != p){
			par[i] = x;
			dfs(i, x);
			sz[x] += sz[i];
		}
	}
}

lint w[MAXN];

void Do(){
	for(int i=1; i<=n-1; i++){
		w[i] = 1ll * sz[i + 1] * (n - sz[i + 1]);
	}
	sort(w + 1, w + n);
	for(int i=1; i<=n-1; i++) w[i] %= mod;
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=0; i<n-1; i++){
			int s, e; scanf("%d %d",&s,&e);
			gph[s].push_back(e);
			gph[e].push_back(s);
		}
		dfs(1);
		int m; scanf("%d",&m);
		vector<int> v(m);
		for(int i=0; i<m; i++) scanf("%d",&v[i]);
		while(sz(v) < n-1) v.push_back(1);
		sort(all(v));
		lint ret = 1;
		for(int i=n-2; i<sz(v); i++) ret = ret * v[i] % mod;
		v[n - 2] = ret;
		v.resize(n-1);
		Do();
		ret = 0;
		for(int i=0; i<n-1; i++) ret += 1ll * v[i] * w[i + 1] % mod;
		cout << ret % mod << endl;
		for(int i=0; i<=n; i++) gph[i].clear();
	}
}