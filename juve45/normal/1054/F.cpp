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

const int N = 4010;
int n, val[2 * N];

struct BipartiteMatcher {
	int n, m;
	vector<vector<int>> G;
	vector<int> L, R, Viz, coverL, coverR, use;
 
	BipartiteMatcher(int _n, int _m) {
		n = _n;
		m = _m;
		G.resize(n);
		use.resize(n);
		L.resize(n, -1);
		R.resize(m, -1);
		coverL.resize(n, 0);
		coverR.resize(m, 0);
		Viz.resize(n);
	}
 
	void AddEdge(int a, int b) {
		G[a].push_back(b);
	}
 
	bool Match(int node) {
		if(Viz[node]) 
			return false;
		Viz[node] = true;
	
		for(auto vec : G[node]) {
			if(R[vec] == -1 || Match(R[vec])) {
				L[node] = vec;
				R[vec] = node;
				return true;
			}
		}
 
		return false;
	}
	void Solve() {
		bool ok = true;
		while(ok) {
			ok = false;
			fill(Viz.begin(), Viz.end(), 0);
			for(int i = 0; i < L.size(); ++i)
				if(L[i] == -1)
					ok |= Match(i);
		}
	}

	void dfs(int node) {
		use[node] = 1;
		for(auto i : G[node])
			if(R[i] != -1 && use[R[i]] == 0) {
				coverR[i] = 1;
				dfs(R[i]);
			}
	}

	void VertexCover() {

		for(int i = 0; i < n; i++)
			if(L[i] == -1 && !use[i])
				dfs(i);
		for(int i = 0; i < n; i++)
			if(use[i] == 0)
				coverL[i] = 1;
	}
};

int x[N], y[N];
vector <int> coords;
map <int, int> mp;
vector <int> vx[N], vy[N];
set <int> sx, sy;
vector <pair<int, pair<int, int> > > segx, segy;

int main() {
	ios_base::sync_with_stdio(false);

	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> x[i] >> y[i];
		sx.insert(x[i]);
		sy.insert(y[i]);
		coords.push_back(x[i]);
		coords.push_back(y[i]);
	}

	sort(coords.begin(), coords.end());
	for(int i = 0; i < coords.size(); i++) {
		if(mp[coords[i]]) continue;
		int k = mp.size();
		mp[coords[i]] = k + 1;
	}
	for(auto i : mp)
		val[i.nd] = i.st;
	// dbg(mp);

	for(int i = 1; i <= n; i++) {
		x[i] = mp[x[i]];
		y[i] = mp[y[i]];
		// dbg(i, x[i], y[i]);
		vx[x[i]].push_back(y[i]);
		vy[y[i]].push_back(x[i]);
	}

	// int szx = 0, szy = 0;
	for(int i = 1; i <= 2 * n; i++) {
		sort(vx[i].begin(), vx[i].end());
		sort(vy[i].begin(), vy[i].end());
		for(int j = 0; j + 1 < vx[i].size(); j++)
			segx.push_back({i, {vx[i][j], vx[i][j + 1]}});

		for(int j = 0; j + 1 < vy[i].size(); j++)
			segy.push_back({i, {vy[i][j], vy[i][j + 1]}});
	}

	BipartiteMatcher bm(segx.size(), segy.size());

	for(int i = 0; i < segx.size(); i++)
		for(int j = 0; j < segy.size(); j++)
			if(segx[i].st > segy[j].nd.st && segx[i].st < segy[j].nd.nd && 
				 segy[j].st > segx[i].nd.st && segy[j].st < segx[i].nd.nd ) {
				// dbg(i, j);
				bm.AddEdge(i, j);
			}
	bm.Solve();
	int match = 0;
	for(auto j : bm.L) match += (j != -1);
	bm.VertexCover();
	// dbg(match);
	// dbg(bm.coverL);
	// dbg(bm.coverR);	
		
	int cx = 0, cy = 0;
	vector <tuple<int, int, int, int> > ansL, ansR;
	for(int i = 0; i <= 4 * n; i++) {
		if(!vx[i].empty()) {
			// dbg(i);
			int last = vx[i][0];
			for(int j = 0; j + 1 < vx[i].size(); j++, cx++)
				if(bm.coverL[cx]) {
					ansL.push_back({i, last, i, vx[i][j]});
					last = vx[i][j + 1];
				}
			ansL.push_back({i, last, i, vx[i].back()});
		}

		if(!vy[i].empty()) {
			int last = vy[i][0];				
			for(int j = 0; j + 1 < vy[i].size(); j++, cy++) 
				if(bm.coverR[cy]) {
					ansR.push_back({last, i, vy[i][j], i});
					last = vy[i][j + 1];
				}
			ansR.push_back({last, i, vy[i].back(), i});
		}
	}
	// dbg(coords);
	// dbg(mp);
	// dbg_v(val, 6);

	// assert(ansL.size() + ansR.size() == match + sx.size() + sy.size());
	cout << ansR.size() << '\n';
	for(auto i : ansR) {
		cout << val[get<0>(i)] << ' ';
		cout << val[get<1>(i)] << ' ';
		cout << val[get<2>(i)] << ' ';
		cout << val[get<3>(i)] << ' ';
		cout << '\n';
	}
	cout << ansL.size() << '\n';
	for(auto i : ansL) {
		cout << val[get<0>(i)] << ' ';
		cout << val[get<1>(i)] << ' ';
		cout << val[get<2>(i)] << ' ';
		cout << val[get<3>(i)] << ' ';
		cout << '\n';
	}


	// cout << ansL << '\n';
	// cout << ansR << '\n';
}