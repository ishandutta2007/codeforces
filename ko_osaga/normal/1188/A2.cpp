#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
using lint = long long;
using pi = pair<int, int>;

int n;
struct edge{int s, e, x;};
vector<edge> edg;
vector<pi> gph[MAXN];
int par[MAXN], pae[MAXN], din[MAXN];
int rt = -1, piv;

void dfs(int x, int p){
	din[x] = ++piv;
	for(auto &i : gph[x]){
		if(i.second == p) continue;
		par[i.second] = x;
		pae[i.second] = i.first;
		dfs(i.second, x);
	}
}

void remPath(int x, int v){
	while(x != rt){
		pae[x] += v;
		x = par[x];
	}
}

pi solve(int x, int p){
	if(x != rt && gph[x].size() == 1) return pi(x, x);
	pi ans(n + 1, 0);
	for(auto &i : gph[x]){
		if(i.second == p) continue;
		pi r = solve(i.second, x);
		if(din[ans.first] > din[r.first]) ans.first = r.first;
		if(din[ans.second] < din[r.second]) ans.second = r.second;
		if(r.first == r.second){
			int w = pae[i.second];
			remPath(i.second, -w);
			edg.push_back({r.first, rt, -w});
		}
		else{
			int s = r.first;
			int e = r.second;
			int w = pae[i.second];
			remPath(i.second, -w);
			edg.push_back({s, e, w/2});
			edg.push_back({s, rt, -w/2});
			edg.push_back({e, rt, -w/2});
		}
	}
	return ans;
}

int main(){
	cin >> n;
	for(int i=0; i<n-1; i++){
		int s, e, x; scanf("%d %d %d",&s,&e,&x);
		gph[s].emplace_back(x, e);
		gph[e].emplace_back(x, s);
	}
	for(int i=1; i<=n; i++){
		if(gph[i].size() == 2){
			if(gph[i][0].first != gph[i][1].first){
				puts("NO");
				return 0;
			}
		}
	}
	din[n + 1] = n + 1;
	for(int i=1; i<=n; i++){
		if(gph[i].size() == 1){
			rt = i;
			break;
		}
	}
	dfs(rt, -1);
	solve(rt, -1);
	printf("YES\n%d\n", edg.size());
	for(auto &i : edg){
		printf("%d %d %d\n", i.s, i.e, -i.x);
	}
}