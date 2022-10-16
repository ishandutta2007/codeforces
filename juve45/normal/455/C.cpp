#include <bits/stdc++.h>
#define st first
#define nd second

using namespace std;

void debug_out() { cerr << endl; }
template<class T> ostream& prnt(ostream& out, T v) { out << v.size() << '\n'; for(auto e : v) out << e << ' '; return out;}
template<class T> ostream& operator<<(ostream& out, vector <T> v) { return prnt(out, v); }
template<class T> ostream& operator<<(ostream& out, set <T> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, map <T1, T2> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, pair<T1, T2> p) { return out << '(' << p.st << ' ' << p.nd << ')'; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << " " << H; debug_out(T...);}

#define dbg(...) cerr << #__VA_ARGS__ << " ->", debug_out(__VA_ARGS__)
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

const int N = 300100;
int nrc = 0;
int n, use[N], cc[N], m, q, a, b, op, d[N];
vector <int> v[N], c[N];

void unite (int x, int y) {
	// dbg(x, y, d[x], d[y]);
	// dbg(c[x]);
	// dbg(c[y]);
	if(c[x].size() < c[y].size()) 
		swap(x, y);

	int szx = d[x] / 2 + 1;
	int szy = d[y] / 2 + 1;
	
	d[x] = max({d[x], d[y], szx + szy});

	for(auto i : c[y]) {
		cc[i] = x;
		c[x].push_back(i);
	}
	// dbg(d[x]);
}

int maxx = 0, mnode;

void dfs(int node, int ant, int lvl) {
	if(lvl > maxx)
		maxx = lvl, mnode = node;

	for(auto i : v[node])
		if(i != ant)
			dfs(i, node, lvl + 1);
}

void diam(int node, int comp) {
	maxx = 0;
	dfs(node, -1, 1);
	// dbg(node, mnode, maxx);
	node = mnode;
	maxx = 0, mnode = -1;
	dfs(node, -1, 1);
	d[comp] = maxx;
}

void dfc(int node) {
	use[node] = 1;
	c[nrc].push_back(node);
	cc[node] = nrc;
	for(auto i : v[node])
		if(!use[i])
			dfc(i);
}

int main() {
	ios_base::sync_with_stdio(false);

	cin >> n >> m >> q;

	for(int i = 1; i <= m; i++) {
		 cin >> a >> b;
		 v[a].push_back(b);
		 v[b].push_back(a);
	}

	for(int i = 1; i <= n; i++)
		if(!use[i])
			nrc++, dfc(i);

	// dbg(c[1]);
	// dbg(c[2]);
	// dbg(c[3]);
	for(int i = 1; i <= nrc; i++) {
		// dbg(i);
		diam(c[i][0], i);
	}

	// dbg_v(d, n + 1);

	for(int i = 1; i <= q; i++) {
		cin >> op;
		if(op == 1) {
			cin >> a;
			cout << d[cc[a]] - 1 << '\n';
		} else {
			cin >> a >> b;
			if(cc[a] == cc[b]) continue;
			unite(cc[a], cc[b]);
		}
	}
}