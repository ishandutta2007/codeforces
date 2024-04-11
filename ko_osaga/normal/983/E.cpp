#include <bits/stdc++.h>
using namespace std;
using lint = long long;
const int MAXN = 200005;

int n, m, q;
int p[19][MAXN], din[MAXN], dout[MAXN], up[19][MAXN], piv;
int dep[MAXN], s[MAXN], e[MAXN];

vector<int> gph[MAXN];

bool sub(int x, int y){
	return din[x] <= din[y] && dout[y] <= dout[x];
}

void dfs(int x){
	din[x] = ++piv;
	up[0][x] = dep[x];
	for(auto &i : gph[x]){
		dep[i] = dep[x] + 1;
		dfs(i);
	}
	dout[x] = piv;
}

int anc(int x, int d){
	for(int i=0; i<19; i++){
		if((d >> i) & 1) x = p[i][x];
	}
	return x;
}

int lca(int s, int e){
	if(dep[s] < dep[e]) swap(s, e);
	s = anc(s, dep[s] - dep[e]);
	for(int i=18; i>=0; i--){
		if(p[i][s] != p[i][e]){
			s = p[i][s];
			e = p[i][e];
		}
	}
	if(s != e) return p[0][s];
	return s;
}

struct seg{
	vector<int> tree[530000];
	int lim;
	void init(){
		for(lim = 1; lim <= n; lim <<= 1);
		for(int i=1; i<=m; i++){
			for(int j=lim + din[s[i]]; j; j>>=1){
				tree[j].push_back(din[e[i]]);
			}
		}
		for(int i=1; i<530000; i++) sort(tree[i].begin(), tree[i].end());
	}
	bool query(int n, int s, int e){
		auto l = lower_bound(tree[n].begin(), tree[n].end(), s);
		return l != tree[n].end() && (*l <= e);
	}
	bool query(int sx, int ex, int sy, int ey){
		sx += lim;
		ex += lim;
		while(sx < ex){
			if(sx % 2 == 1){
				if(query(sx++, sy, ey)) return 1;
			}
			if(ex % 2 == 0){
				if(query(ex--, sy, ey)) return 1;
			}
			sx >>= 1;
			ex >>= 1;
		}
		if(sx == ex && query(sx, sy, ey)) return 1;
		return 0;
	}
}seg;

int getit(int x, int y){
	if(sub(x, y) || sub(y, x)) return 1;
	if(din[x] > din[y]) swap(x, y);
	int sx = din[x], ex = dout[x];
	int sy = din[y], ey = dout[y];
	if(seg.query(sx, ex, sy, ey)) return 1;
	return 2;
}

int main(){
	scanf("%d",&n);
	for(int i=2; i<=n; i++){
		scanf("%d",&p[0][i]);
		gph[p[0][i]].push_back(i);
	}
	for(int i=1; i<19; i++){
		for(int j=1; j<=n; j++) p[i][j] = p[i-1][p[i-1][j]];
	}
	dfs(1);
	scanf("%d",&m);
	for(int i=1; i<=m; i++){
		scanf("%d %d",&s[i],&e[i]);
		int l = lca(s[i], e[i]);
		up[0][s[i]] = min(up[0][s[i]], dep[l]);
		up[0][e[i]] = min(up[0][e[i]], dep[l]);
		if(din[s[i]] > din[e[i]]) swap(s[i], e[i]);
	}
	seg.init();
	for(int i=n; i; i--){
		for(auto &j : gph[i]) up[0][i] = min(up[0][i], up[0][j]);
	}
	for(int i=1; i<=n; i++){
		up[0][i] = anc(i, dep[i] - up[0][i]);
	}
	for(int i=1; i<19; i++){
		for(int j=1; j<=n; j++){
			up[i][j] = up[i-1][up[i-1][j]];
		}
	}
	int q; scanf("%d",&q);
	while(q--){
		int s, e;
		scanf("%d %d",&s,&e);
		int l = lca(s, e);
		if(dep[up[18][s]] > dep[l]) puts("-1");
		else if(dep[up[18][e]] > dep[l]) puts("-1");
		else{
			int ans = 0;
			for(int i=18; i>=0; i--){
				if(dep[up[i][s]] > dep[l]){
					ans += (1<<i);
					s = up[i][s];
				}
				if(dep[up[i][e]] > dep[l]){
					ans += (1<<i);
					e = up[i][e];
				}
			}
			ans += getit(s, e);
			printf("%d\n", ans);
		}
	}
}