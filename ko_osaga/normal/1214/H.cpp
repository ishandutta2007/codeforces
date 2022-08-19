#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
using namespace std;
using lint = long long;
typedef pair<int, int> pi;
const int MAXN = 200005;

int n, k;
vector<int> gph[MAXN];
int par[MAXN], dep[MAXN], col[MAXN];


namespace Ontak{
	int a[200005], chk[200005];
lint val[200005], mat;
	bool vis[200005];
	int aux[200005];
	vector<int> dfn;

	void dfs3(int x, int p){
		for(auto &i : gph[x]){
			if(i == p || vis[i]) continue;
			dfs3(i, x);
			if(aux[i]) aux[x] = 1;
		}
	}

	void dfs2(int x, int p, lint h, vector<pi> &v){
		h += val[a[x]];
		v.push_back(pi(h, x));
		for(auto &i : gph[x]){
			if(i == p || vis[i]) continue;
			dfs2(i, x, h, v);
		}
	}

	void solve(int r){
		for(auto &i : dfn) aux[i] = 0;
		set<lint> s;
		s.insert(val[a[r]]);
		for(auto &i : gph[r]){
			if(vis[i]) continue;
			vector<pi> sack;
			dfs2(i, r, val[a[r]], sack);
			for(auto &i : sack){
				if(s.find(mat - i.first + val[a[r]]) != s.end()){
					aux[i.second] = 1;
				}
			}
			for(auto &i : sack){
				s.insert(i.first);
			}
		}
		reverse(gph[r].begin(), gph[r].end());
		s.clear();
		s.insert(val[a[r]]);
		for(auto &i : gph[r]){
			if(vis[i]) continue;
			vector<pi> sack;
			dfs2(i, r, val[a[r]], sack);
			for(auto &i : sack){
				if(s.find(mat - i.first + val[a[r]]) != s.end()){
					aux[i.second] = 1;
				}
			}
			for(auto &i : sack){
				s.insert(i.first);
			}
		}
		dfs3(r, -1);
		for(auto &i : dfn) if(aux[i]) chk[i] = 1;
	}

	int msz[200005], sz[200005];

	void dfs(int x, int p){
		dfn.push_back(x);
		msz[x] = 0;
		sz[x] = 1;
		for(auto &i : gph[x]){
			if(i == p || vis[i]) continue;
			dfs(i, x);
			msz[x] = max(msz[x], sz[i]);
			sz[x] += sz[i];
		}
	}

	int get_center(int x){
		dfn.clear();
		dfs(x, -1);
		int cur = 1e9, pos = -1;
		for(auto &i : dfn){
			int w = max((int)dfn.size() - sz[i], msz[i]);
			if(w < cur){
				cur = w;
				pos = i;
			}
		}
		return pos;
	}

	bool solve(){
		 mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
		for(int i=1; i<=n; i++) a[i] = col[i];
		for(int i=1; i<=k; i++){
			val[i] += uniform_int_distribution<long long>(0ll, 1ll << 32)(rng);
			val[i] <<= 32; 
			val[i] += uniform_int_distribution<long long>(0ll, 1ll << 32)(rng);
			mat += val[i];
		}
		queue<int> que;
		que.push(1);
		while(!que.empty()){
			int x = que.front();
			que.pop();
			x = get_center(x);
			solve(x);
			vis[x] = 1;
			for(auto &i : gph[x]){
				if(!vis[i]) que.push(i);
			}
		}
		for(int i=1; i<=n; i++) if(chk[i]) return 1;
		return 0;
	}
}

pi far(int x, int p){
	pi ret(0, x);
	for(auto &i : gph[x]){
		if(i != p && !col[i]){
			par[i] = x;
			dep[i] = dep[x] + 1;
			auto j = far(i, x);
			j.first++;
			ret = max(ret, j);
		} 
	}
	return ret;
}

void increasing(int x, int p){
	for(auto &i : gph[x]){
		if(i != p && !col[i]){
			col[i] = col[x] + 1;
			if(col[i] > k) col[i] = 1;
			increasing(i, x);
		}
	}
}

void decreasing(int x, int p){
	for(auto &i : gph[x]){
		if(i != p && !col[i]){
			col[i] = col[x] - 1;
			if(col[i] <= 0) col[i] = k;
			decreasing(i, x);
		}
	}
}

int main(){
	scanf("%d %d",&n,&k);
	for(int i=1; i<n; i++){
		int s, e; scanf("%d %d",&s,&e);
		gph[s].push_back(e);
		gph[e].push_back(s);
	}
	int s = far(1, 0).second;
	int d, t;
	tie(d, t) = far(s, 0);
	if(d + 1 < k){
		puts("Yes");
		for(int i=1; i<=n; i++){
			printf("%d ", (i - 1) % k + 1);
		}
		puts("");
		return 0;
	}
	if(k == 2){
		puts("Yes");
		for(int i=1; i<=n; i++){
			printf("%d ", dep[i] % 2 + 1);
		}
		puts("");
		return 0;
	}
	vector<int> pth = {t};
	for(int i=t; i!=s; i=par[i]){
		pth.push_back(par[i]);
	}
	for(int i=0; i<sz(pth); i++){
		col[pth[i]] = i % k + 1;
	}
	for(int i=0; i<sz(pth); i++){
		auto tmp = far(pth[i], -1);
		if(tmp.first == 0) continue;
		if(tmp.first + min(sz(pth) - i, i + 1) >= k){
			puts("No");
			return 0;
		}
		if(sz(pth) - i >= i + 1){
			decreasing(pth[i], -1);
		}
		else{
			increasing(pth[i], -1);
		}
	}
	if(!Ontak::solve()){
		puts("Yes");
		for(int i=1; i<=n; i++) printf("%d ", col[i]);
	}
	else puts("No");
}