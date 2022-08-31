#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
using lint = long long;
using pi = pair<int, int>;
const int MAXN = 200005;

lint solve(lint x, lint y, lint z){
	lint d1 = (x - y);
	lint d2 = y - z;
	lint d3 = x - z;
	return d1*d1+d2*d2+d3*d3;
}

int main(){
	int tc;
	scanf("%d",&tc);
	while(tc--){
		int n[3];
		vector<int> v[3];
		scanf("%d %d %d",&n[0],&n[1],&n[2]);
		for(int i=0; i<3; i++){
			v[i].resize(n[i]);
			for(int j=0; j<n[i]; j++){
				scanf("%d",&v[i][j]);
			}
			sort(all(v[i]));
		}
		lint ret = 9e18;
		for(int i=0; i<3; i++){
			for(int j=0; j<n[i]; j++){
				auto k1 = lower_bound(all(v[(i+1)%3]), v[i][j]);
				auto k2 = upper_bound(all(v[(i+1)%3]), v[i][j]);
				auto k3 = lower_bound(all(v[(i+2)%3]), v[i][j]);
				auto k4 = upper_bound(all(v[(i+2)%3]), v[i][j]);
				if(k1 != v[(i+1)%3].end() && k4 != v[(i+2)%3].begin()){
					ret = min(ret, solve(v[i][j], *prev(k4), *k1));
				}
				if(k3 != v[(i+2)%3].end() && k2 != v[(i+1)%3].begin()){
					ret = min(ret, solve(v[i][j], *prev(k2), *k3));
				}
			}
		}
		printf("%lld\n", ret);
	}
}

/*
int n, k;
vector<int> gph[MAXN];
vector<pi> deps;
int sz[MAXN];

void dfs(int x, int p, int d){
	sz[x] = 1;
	for(auto &i : gph[x]){
		if(i != p){
			dfs(i, x, d + 1);
			sz[x] += sz[i];
		}
	}
	deps.emplace_back(d, -(sz[x] - 1));
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
	k = n - k;
	lint ret = 1ll * deps[k - 1].first * (n - k);
	for(int i=0; i<k; i++){
		if(deps[i].first == deps[k - 1].first) ret -= deps[i].second;
	}
	cout << ret << endl;
}*/