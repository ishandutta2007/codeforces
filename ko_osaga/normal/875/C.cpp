#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;
const int MAXN = 200005;
const int mod = 1e9 + 7;
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
	void init(int _n){ scc.clear(); n = _n; }
	int NOT(int x){ return x >= n ? (x - n) : (x + n); }
	void add_edge(int x, int y){
		if((x >> 31) & 1) x = (~x) + n;
		if((y >> 31) & 1) y = (~y) + n;
		scc.add_edge(x, y), scc.add_edge(NOT(y), NOT(x));
	}
	bool satisfy(int *res){
		scc.get_scc(2*n);
		for(int i=0; i<n; i++){
			if(scc.comp[i] == scc.comp[NOT(i)]) return 0;
			if(scc.comp[i] < scc.comp[NOT(i)]) res[i] = 0;
			else res[i] = 1;
		}
		return 1;
	}
}twosat;

vector<int> v[MAXN];
int chk[MAXN];

int lcp(vector<int> &a, vector<int> &b){
	for(int i=0; i<a.size() && i<b.size(); i++){
		if(a[i] != b[i]) return i;
	}
	return min(a.size(), b.size());
}

int main(){
	int n, m;
	memset(chk, -1, sizeof(chk));
	scanf("%d %d",&n,&m);
	for(int i=0; i<n; i++){
		int x;
		scanf("%d",&x);
		v[i].resize(x);
		for(auto &j : v[i]) scanf("%d",&j);
		for(auto &j : v[i]) j--;
	}
	twosat.init(m);
	for(int i=n-2; i>=0; i--){
		int l = lcp(v[i], v[i+1]);
		if(l == v[i].size() || l == v[i+1].size()){
			if(v[i].size() > v[i+1].size()){
				puts("No");
				return 0;
			}
			continue;
		}
		if(v[i][l] < v[i+1][l]){
			twosat.add_edge(~v[i][l], ~v[i+1][l]);
		}
		else{
			twosat.add_edge(~v[i][l], v[i][l]);
			twosat.add_edge(v[i+1][l], ~v[i+1][l]);
		}
	}
	if(!twosat.satisfy(chk)){
		puts("No");
		return 0;
	}{
	vector<int> v;
	for(int i=0; i<m; i++){
		if(chk[i] == 1) v.push_back(i+1);
	}
	cout << "Yes" << endl << v.size() << endl;
	for(auto &i : v) printf("%d ", i);
	}
}