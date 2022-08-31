#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
using lint = long long;
using pi = pair<int, int>;
const int MAXN = 800005;
const int mod = 1e9 + 7;

struct strongly_connected{
	vector<vector<int>> gph;

	void init(int n){
		gph.clear();
		gph.resize(n);
	}

	void add_edge(int s, int e){
		gph[s].push_back(e);
	}

	vector<int> val, comp, z, cont;
	int Time, ncomps;
	template<class G, class F> int dfs(int j, G& g, F f) {
		int low = val[j] = ++Time, x; z.push_back(j);
		for(auto e : g[j]) if (comp[e] < 0)
			low = min(low, val[e] ?: dfs(e,g,f));

		if (low == val[j]) {
			do {
				x = z.back(); z.pop_back();
				comp[x] = ncomps;
				cont.push_back(x);
			} while (x != j);
			f(cont); cont.clear();
			ncomps++;
		}
		return val[j] = low;
	}
	template<class G, class F> void scc(G& g, F f) {
		int n = sz(g);
		val.assign(n, 0); comp.assign(n, -1);
		Time = ncomps = 0;
		for(int i=0; i<n; i++) if (comp[i] < 0) dfs(i, g, f);
	}

	int piv;
	void get_scc(int n){
		scc(gph, [&](vector<int> &v){});
		for(int i=0; i<n; i++){
			comp[i] = ncomps - comp[i];
		}
		piv = ncomps;
	}
}scc;

char buf[MAXN];
bool vis[MAXN];
vector<int> gph[MAXN];

void dfs(int x){
	vis[x] = 1;
	for(auto &i : gph[x]){
		if(!vis[i]) dfs(i);
	}
}

int main(){
	int n, m; scanf("%d %d",&n,&m);
	auto g = [&](int x, int y){
		return x*m+y;
	};
	vector<string> v(n);
	int foo = n*m;
	for(int i=0; i<n; i++){
		scanf("%s", buf);
		v[i] = buf;
	}
	vector<int> a(m);
	for(int i=0; i<m; i++) scanf("%d",&a[i]);
	for(int i=0; i<m; i++){
		a[i] = -a[i];
		for(int j=0; j<n; j++){
			if(v[j][i] == '#'){
				a[i]++;
				foo++;
			}
		}
	}
	scc.init(foo);
	for(int i=0; i<n-1; i++){
		for(int j=0; j<m; j++){
			scc.add_edge(g(i, j), g(i+1, j));
		}
	}
	int piv = n*m;
	vector<int> idx;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(v[i][j] == '#'){
				int vtx = piv++;
				scc.add_edge(g(i, j), vtx);
				if(j-1>=0) scc.add_edge(vtx, g(i, j-1));
				if(j+1<m) scc.add_edge(vtx, g(i, j+1));
				scc.add_edge(vtx, g(max(i-1, 0), j));
				a[j]--;
				if(a[j] < 0){
					idx.push_back(vtx);
				}
			}
		}
	}
	assert(foo == piv);
	scc.get_scc(piv);
	for(auto &v : idx){
		v = scc.comp[v];
	}
	sort(all(idx));
	for(int i = 0; i < piv; i++){
		for(auto &j : scc.gph[i]){
			if(scc.comp[i] != scc.comp[j]){
				assert(scc.comp[i] < scc.comp[j]);
				gph[scc.comp[i]].push_back(scc.comp[j]);
			}
		}
	}
	int ret = 0;
	for(auto &v : idx){
		if(vis[v]) continue;
		dfs(v);
		ret++;
	}
	cout << ret << endl;
}