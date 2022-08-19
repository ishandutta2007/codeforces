#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
using lint = long long;
using pi = pair<int, int>;
const int MAXN = 200005;

int n, k;
vector<int> gph[MAXN];
vector<lint> deps;
int sz[MAXN];

void dfs(int x, int p, int d){
	sz[x] = 1;
	for(auto &i : gph[x]){
		if(i != p){
			dfs(i, x, d + 1);
			sz[x] += sz[i];
		}
	}
	deps.push_back(d - sz[x] + 1);
}

int main(){
	scanf("%d %d",&n,&k);
	for(int i=1; i<n; i++){
		int s, e; scanf("%d %d",&s,&e);
		gph[s].push_back(e);
		gph[e].push_back(s);
	}
	dfs(1, 0, 0);
	sort(all(deps));
	reverse(all(deps));
	cout << accumulate(deps.begin(), deps.begin() + k, 0ll) << endl;
}