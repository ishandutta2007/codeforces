#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
using pi = pair<int, int>;
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
const int MAXN = 400005;

int n, a, b;
vector<int> gph[MAXN];
int dep[MAXN];

pi dfs(int x, int p = -1){
	pi ret(0, x);
	for(auto &i : gph[x]){
		if(i != p){
			dep[i] = dep[x] + 1;
			auto w = dfs(i, x);
			w.first++;
			ret = max(ret, w);
		}
	}
	return ret;
}

int main(){
	int tc; scanf("%d",&tc);
	while(tc--){
		int va, vb;
		scanf("%d %d %d %d %d",&n,&va,&vb,&a,&b);
		for(int i=0; i<n-1; i++){
			int x, y;
			scanf("%d %d",&x,&y);
			gph[x].push_back(y);
			gph[y].push_back(x);
		}
		dep[va] = 0;
		int x = dfs(va).second;
		if(dep[vb] <= a){
			puts("Alice");
		for(int i=0; i<=n; i++) gph[i].clear();
			continue;
		}
		int d, y;
		tie(d, y) = dfs(x);
		a = min(a, d);
		b = min(b, d);
		if(2 * a  < d && b > 2 * a) puts("Bob");
		else puts("Alice");
		for(int i=0; i<=n; i++) gph[i].clear();
	}
}