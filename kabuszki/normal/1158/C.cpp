
//Karol Kaszuba

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;
typedef double D;
typedef long double LD;
typedef vector<PII> VII;
typedef unordered_set<int> USI;
typedef unordered_set<LL> USLL;

#define FOR(i,x,y) for(auto i=(x);i<=(y);++i)
#define REP(i,x) FOR(i,0,(x)-1)
#define FORD(i,x,y) for(auto i=(x);i>=(y);--i)
#define VAR(i,c) __typeof(c) i=(c)
#define FORE(i,c) for(VAR(i,(c).begin());i!=(c).end();++i)
#define SIZE(c) (int)((c).size())
#define ALL(c) (c).begin(),(c).end()
#define PB push_back
#define EB emplace_back
#define IN insert
#define ER erase
#define MP make_pair
#define ST first
#define ND second
#define IOSYNC ios_base::sync_with_stdio(0)
#define FREOPEN(f) freopen(f, "r", stdin),freopen(f, "w", stdout)

/*
struct Edge{
  int v; 
};

struct Vertex{
  vector<Edge> kr;
  int t; 
  int s; 
};

struct Graf{
  vector<Vertex> g;
  Graf(int n=0): g(n){}
  void AddEdge(int p,int k){Edge e; e.v=k; g[p].kr.PB(e);}
  vector<int> vis;
  Graf *nowy;
  void SccDfs(int v,int numer, bool sortuj){
    g[v].s=1; if (!sortuj) vis[v]=numer;
    for(auto it : g[v].kr) if (!g[it.v].s) SccDfs(it.v,numer,sortuj);
      else if (!sortuj && numer > vis[it.v])
        nowy->AddEdge(g[it.v].t,(vis[it.v]=numer));
    if (sortuj) vis.PB(v); else g[v].t=numer;
  }
  //dla kazdego wierzcholka obliczamy numer silnie spojej skladowej,
  //do ktorej on nalezy, numer ten jest w polu t,
  //zwracamy graf prosty SCC, posortowany topologicznie
  Graf Scc(){
    Graf gt(SIZE(g)),res(SIZE(g)),*tab[]={this, >};
    gt.nowy=&res; gt.vis.resize(SIZE(g)); vis.clear();
    REP(i,SIZE(g)) gt.vis[i]=-1;
    REP(i,SIZE(g)) for(auto it : g[i].kr) gt.AddEdge(it.v,i);
    REP(i,2){
      for (auto& it : tab[i]->g) it.s = 0;
      int l_sklad=0,v;
      FORD(j,SIZE(g)-1,0)
        if (!tab[i]->g[v=(i?vis[j]:j)].s) tab[i]->SccDfs(v,l_sklad++,1-i);
      if (i) res.g.resize(l_sklad);
    }
    REP(i,SIZE(g)) g[i].t=gt.g[i].t;
    return res;
  }
};
*/

////////////////

const int N = 500005;
int n, ind[N], low[N], onstack[N], last, n2, t[N];
VI adj[N], st;

void go(int v) {
	ind[v] = low[v] = ++last;
	st.PB(v);
	onstack[v] = 1;
	for (auto w : adj[v]) {
		if (!ind[w]) {
			go(w);
			low[v] = min(low[v], low[w]);
		} else if (onstack[w]) {
			low[v] = min(low[v], low[w]);
		}
	}
	if (low[v] == ind[v]) {
		++n2;
		for (int w = -1; w != v; ) {
			w = st.back();
			st.pop_back();
			onstack[w] = 0;
			t[w] = n2;
		}
	}
}

void scc() {
	last = n2 = 0;
	st.clear();
	REP(i, n)
		ind[i] = onstack[i] = t[i] = low[i] = 0;
	REP(i, n) if (!ind[i]) go(i);
	REP(i, n) t[i] = n2 + 1 - t[i];
}




///////////////////



bool sprawdz(VII v) {
	set<PII> secik;
	for (auto p : v) {
		while (true) {
			auto it = secik.lower_bound({p.ST, 0});
			if (it != secik.end() && it->first < p.ND) {
				if (it->ND > p.ND) return false; 
			} else break;
		}
	}
	return true;
}

void jebaj() {
	cin >> n;
	VI nex(n);
	VII v;
	REP(i, n) {
		cin >> nex[i];
		if (nex[i] != -1) v.EB(i, nex[i] - 1);
	}
	sort(ALL(v), [](const PII& a, const PII& b) {
		return a.ND - a.ST < b.ND - b.ST;
	});
	
	if (!sprawdz(v)) {
		cout << "-1\n";
		return;
	}
	
	set<int> starty;
	REP(i, n) starty.IN(i);
	REP(i, n) adj[i].clear();
	
	
	for (auto p : v) {
		int l = p.ST, r = p.ND;
		while (true) {
			auto it = starty.lower_bound(l + 1);
			if (it == starty.end()) break;
			if (*it <= l || *it >= r) break;
			adj[*it].PB(l);
			starty.erase(it);
		}
		if (r != n) adj[l].PB(r);
	}
	
	scc();
	set<int> secik;
	REP(i, n) secik.IN(t[i]);
	if (SIZE(secik) != n) {
		cout << "-1\n";
		return;
	}
	REP(i, n) cout << t[i] << " "; cout << "\n";
	
}

int main() {
	IOSYNC;
	int t;
	cin >> t;
	while(t--) jebaj();
	return 0;
}