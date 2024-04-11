#include <bits/stdc++.h>
using namespace std;
const int MAXL = 20;
const int MAXN = 300005;
using lint = long long;
using pi = pair<int, int>;

struct point{
	int x, y, idx;
	bool operator<(const point &p)const{
		return pi(x, y) < pi(p.x, p.y);
	}
}a[MAXN];

struct namu{
	vector<int> gph[MAXN];
	int depth[MAXL][MAXN];
	int n, vtx[MAXN];
	int cpar[MAXN], cdep[MAXN];
	void add_edge(int x, int y){
		gph[x].push_back(y);
		gph[y].push_back(x);
	}
	int sz[MAXN], msz[MAXN], vis[MAXN];
	vector<int> dfn;
	void dfs(int x, int p){
		sz[x] = 1;
		dfn.push_back(x);
		msz[x] = 0;
		for(auto &i : gph[x]){
			if(i != p && !vis[i]){
				dfs(i, x);
				sz[x] += sz[i];
				msz[x] = max(msz[x], sz[i]);
			}
		}
	}
	int get_center(int x){
		dfn.clear();
		dfs(x, 0);
		int n = dfn.size();
		pi ret(1e9, 0);
		for(auto &i : dfn){
			int csz = max(msz[i], n - sz[i]);
			ret = min(ret, pi(csz, i));
		}
		return ret.second;
	}
	void fill_depth(int x, int p, int d, int pos){
		depth[pos][x] = d;
		for(auto &i : gph[x]){
			if(i != p && !vis[i]){
				fill_depth(i, x, d + 1, pos);
			}
		}
	}
	void Do(){
		for(int i=1; i<=n; i++){
			sort(gph[i].begin(), gph[i].end());
			gph[i].resize(unique(gph[i].begin(), gph[i].end()) - gph[i].begin());
		}
		queue<pi> que;
		que.emplace(1, 0);
		while(!que.empty()){
			int x, p;
			tie(x, p) = que.front();
			que.pop();
			x = get_center(x);
			vis[x] = 1;
			cpar[x] = p;
			cdep[x] = (p ? (cdep[p] + 1) : 0);
			fill_depth(x, 0, 0, cdep[x]);
			for(auto &i : gph[x]){
				if(!vis[i]){
					que.emplace(i, x);
				}
			}
		}
	}
}namu[2];

struct quer{
	int v1, v2, idx, t;
};

int aux[MAXN];
int n, q, ret[MAXN];
vector<quer> query[MAXN];

void Make1(int num){
	sort(a, a + n);
	for(int i=0; i<n; ){
		int e = i;
		while(e < n && a[e].x == a[i].x && a[e].y - a[i].y == e - i) e++;
		namu[num].n++;
		for(int j=i; j<e; j++){
			namu[num].vtx[a[j].idx] = namu[num].n;
		}
		i = e;
	}
}

void Make2(int num){
	sort(a, a + n);
	for(int i=1; i<n; i++){
		if(a[i].x == a[i-1].x && a[i-1].y + 1 == a[i].y){
			int l = namu[num].vtx[a[i-1].idx];
			int r = namu[num].vtx[a[i].idx];
			namu[num].add_edge(l, r);
		}
	}
}


int main(){
	map<pi, int> mp;
	scanf("%d",&n);
	for(int i=0; i<n; i++){
		scanf("%d %d",&a[i].x,&a[i].y);
		mp[pi(a[i].x, a[i].y)] = i;
		a[i].idx = i;
	}
	Make1(0);
	for(int i=0; i<n; i++) swap(a[i].x, a[i].y);
	Make1(1);
	for(int i=0; i<n; i++) swap(a[i].x, a[i].y);
	Make2(1);
	for(int i=0; i<n; i++) swap(a[i].x, a[i].y);
	Make2(0);
	for(int i=0; i<n; i++) swap(a[i].x, a[i].y);
	namu[0].Do();
	namu[1].Do();
	int q;
	memset(ret, 0x3f, sizeof(ret));
	scanf("%d",&q);
	vector<int> prnt;
	for(int i=0; i<q; i++){
		int t, x, y; scanf("%d %d %d",&t,&x,&y);
		int v = mp[pi(x, y)];
		x = namu[0].vtx[v];
		y = namu[1].vtx[v];
		for(int j = x; j != 0; j = namu[0].cpar[j]){
			query[j].push_back({x, y, i, t});
		}
		if(t == 2) prnt.push_back(i);
	}
	memset(aux, 0x3f, sizeof(aux));
	for(int i=1; i<=n; i++){
		for(auto &j : query[i]){
			if(j.t == 1){
				for(int k = j.v2; k != 0; k = namu[1].cpar[k]){
					aux[k] = min(aux[k], namu[0].depth[namu[0].cdep[i]][j.v1] + namu[1].depth[namu[1].cdep[k]][j.v2]);
				}
			}
			else{
				for(int k = j.v2; k != 0; k = namu[1].cpar[k]){
					ret[j.idx] = min(ret[j.idx], aux[k] + namu[0].depth[namu[0].cdep[i]][j.v1] + namu[1].depth[namu[1].cdep[k]][j.v2]);
				}
			}
		}
		for(auto &j : query[i]){
			if(j.t == 1){
				for(int k = j.v2; k != 0; k = namu[1].cpar[k]) aux[k] = 1e9;
			}
		}
	}
	for(auto &i : prnt){
		if(ret[i] > 1e8) ret[i] = -1;
		printf("%d\n", ret[i]);
	}
}