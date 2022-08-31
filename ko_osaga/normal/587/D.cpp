#include <bits/stdc++.h>
typedef long long lint;
typedef long double llf;
using namespace std;
typedef pair<int, int> pi;


const int MAXN = 300005;
struct strongly_connected{
	vector<int> gph[MAXN];
	vector<int> rev[MAXN];
	vector<int> dfn;
	int comp[MAXN], piv;
	bool vis[MAXN];

	void clear(){
		for(int i=0; i<MAXN; i++){
			gph[i].clear();
			rev[i].clear();
		}
	}

	void add_edge(int s, int e){
		gph[s].push_back(e);
		rev[e].push_back(s);
	}

	void dfs(int x){
		vis[x] = 1;
		for(auto &i : gph[x]){
			if(!vis[i]) dfs(i);
		}
		dfn.push_back(x);
	}

	void rdfs(int x, int p){
		comp[x] = p;
		for(auto &i : rev[x]){
			if(!comp[i]) rdfs(i, p);
		}
	}

	void get_scc(int n){
		dfn.clear();
		memset(comp, 0, sizeof(comp));
		memset(vis, 0, sizeof(vis));
		piv = 0;
		for(int i=0; i<n; i++){
			if(!vis[i]) dfs(i);
		}
		reverse(dfn.begin(), dfn.end());
		for(auto &i : dfn){
			if(!comp[i]) rdfs(i, ++piv);
		}
	}
}scc;

struct twosat{
	strongly_connected scc;
	int n;
	bool res[MAXN];

	void init(int _n){
		scc.clear();
		n = _n;
		memset(res, 0, sizeof(res));
	}

	int NOT(int x){
		return x >= n ? (x - n) : (x + n);
	}

	void add_edge(int x, int y){
		if((x >> 31) & 1) x = (~x) + n;
		if((y >> 31) & 1) y = (~y) + n;
		scc.add_edge(x, y);
		scc.add_edge(NOT(y), NOT(x));
	}

	bool satisfy(){
		scc.get_scc(2*n);
		for(int i=0; i<n; i++){
			if(scc.comp[i] == scc.comp[NOT(i)]) return 0;
			if(scc.comp[i] < scc.comp[NOT(i)]) res[i] = 0;
			else res[i] = 1;
		}
		return 1;
	}
}twosat;

struct clause{ int s, e, x, pro, idx; };
vector<int> ans;
vector<clause> cls;
vector<pi> adj[50005];
int n, m, k, cnt;

bool trial(int x){
	ans.clear();
	for(int i=1; i<=n; i++) adj[i].clear();
	twosat.init(cnt + m * 2);
	for(auto &i : cls){
		if(i.x > x){
			twosat.add_edge(i.pro, ~i.pro);
		}
		adj[i.s].push_back(pi(i.pro, i.x));
		adj[i.e].push_back(pi(i.pro, i.x));
	}
	int p = cnt;
	for(int i=1; i<=n; i++){
		if(adj[i].empty()) continue;
		int q = p;
		twosat.add_edge(adj[i][0].first, q + 1);
		q++;
		for(int j=1; j<adj[i].size(); j++){
			twosat.add_edge(q, ~adj[i][j].first);
			twosat.add_edge(adj[i][j].first, q + 1);
			twosat.add_edge(q, q+1);
			q++;
		}
		p = q;
	}
	if(!twosat.satisfy()) return 0;
	for(auto &i : cls){
		if(i.pro < 0){
			if(!twosat.res[~i.pro]) ans.push_back(i.idx);
		}
		else{
			if(twosat.res[i.pro]) ans.push_back(i.idx);
		}
	}
	return 1;
}

struct edg{ int s, e, x, idx; };
int s[50005], e[50005], c[50005], x[50005];
int vis[50005], ok, ve[50005];
vector<pi> tv; 
vector<pi> gph[50005];
vector<edg> col[50005];

void dfs(int x, int c){
	if(vis[x]){
		if(vis[x] != c) ok = 0;
		return;
	}
	vis[x] = c;
	int enc = 0;
	for(auto &i : gph[x]){
		if(!ve[i.first]){
			ve[i.first] = 1;
			tv.push_back(pi(i.first, c));
			dfs(i.second, 3-c);
		}
	}
}

int main(){
	scanf("%d %d",&n,&m);
	vector<int> vc, vx;
	for(int i=0; i<m; i++){
		scanf("%d %d %d %d",&s[i],&e[i],&c[i],&x[i]);
		vc.push_back(c[i]);
		vx.push_back(x[i]);
	}
	sort(vc.begin(), vc.end());
	vc.resize(unique(vc.begin(), vc.end()) - vc.begin());
	sort(vx.begin(), vx.end());
	vx.resize(unique(vx.begin(), vx.end()) - vx.begin());
	k = vc.size();
	for(int i=0; i<m; i++){
		c[i] = lower_bound(vc.begin(), vc.end(), c[i]) - vc.begin() + 1;
		x[i] = lower_bound(vx.begin(), vx.end(), x[i]) - vx.begin() + 1;
		col[c[i]].push_back({s[i], e[i], x[i], i+1});
	}
	for(int i=1; i<=k; i++){
		map<int, int> mp;
		int p = 0;
		for(auto &j : col[i]){
			mp[j.s]++;
			mp[j.e]++;
			gph[j.s].push_back(pi(p, j.e));
			gph[j.e].push_back(pi(p, j.s));
			p++;
		}
		ok = 1;
		int ii = i;
		for(auto &i : mp){
			if(i.second > 2) ok = 0;
		}
		if(!ok){
			puts("No");
			return 0;
		}
		for(auto &i : mp){
			if(i.second == 2) continue;
			if(!vis[i.first]){
				tv.clear();
				dfs(i.first, 1);
				for(auto &j : tv){
					auto edg = col[ii][j.first];
					if(j.second % 2 == 0){
						cls.push_back({edg.s, edg.e, edg.x, ~cnt, edg.idx});
					}
					else{
						cls.push_back({edg.s, edg.e, edg.x, cnt, edg.idx});
					}
				}
				cnt++;
			}
		}
		for(auto &i : mp){
			if(!vis[i.first]){
				tv.clear();
				dfs(i.first, 1);
				for(auto &j : tv){
					auto edg = col[ii][j.first];
					if(j.second % 2 == 0){
						cls.push_back({edg.s, edg.e, edg.x, ~cnt, edg.idx});
					}
					else{
						cls.push_back({edg.s, edg.e, edg.x, cnt, edg.idx});
					}
				}
				cnt++;
			}
		}
		memset(ve, 0, sizeof(int) * p);
		for(auto &i : mp){
			vis[i.first] = 0;
			gph[i.first].clear();
		}
		if(!ok){
			puts("No");
			return 0;
		}
	}
	int s = 0, e = vx.size();
	while(s != e){
		int m = (s+e)/2;
		if(trial(m)) e = m;
		else s = m+1;
	}
	if(!trial(s)){
		puts("No");
		return 0;
	}
	puts("Yes");
	printf("%d %d\n", (s > 0 ? vx[s-1] : 0), ans.size());
	for(auto &i : ans){
		printf("%d ", i);
	}
}