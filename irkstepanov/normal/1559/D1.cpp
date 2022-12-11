#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;

bool valid(const pii& a, const pii& b) {
	//cout << "!" << a.first << " " << a.second << " !! " << b.first << " " << b.second << endl;
	//cout << "RES " << (a.first != b.first && a.second != b.second) << endl;
	return a.first != b.first && a.second != b.second;
}

struct Solver {
	map<int, set<int> > rows;
	map<int, set<int> > cols;
	set<int> big, small;

	void add(int x, int y) {
		if (rows.count(x) && rows[x].count(y)) {
			return;
		}
		if (!rows.count(x)) {
			rows[x].insert(y);
			small.insert(x);
		} else {
			rows[x].insert(y);
			if (sz(rows[x]) == 2) {
				small.erase(x);
				big.insert(x);
			}
		}

		cols[y].insert(x);
	}

	void del(int x, int y) {
		if (!rows.count(x) || !rows[x].count(y)) {
			return;
		}
		if (sz(rows[x]) == 1) {
			rows.erase(x);
			small.erase(x);
		} else {
			rows[x].erase(y);
			if (sz(rows[x]) == 1) {
				big.erase(x);
				small.insert(x);
			}
		}

		cols[y].erase(x);
		if (cols[y].empty()) {
			cols.erase(y);
		}
	}

	Solver(map<pii, int>& a) {
		for (auto it : a) {
			int x = it.first.first, y = it.first.second;
			add(x, y);
		}
	}

	bool get(pii& res1, pii& res2) {
		if (sz(rows) == 1 || sz(cols) == 1) {
			return false;
		}
		if (!big.empty()) {
			int x = *big.begin();
			set<int>::iterator it = rows[x].begin();
			pii p1 = {x, *it};
			++it;
			pii p2 = {x, *it};
			pii p3;
			if (!small.empty()) {
				x = *small.begin();
			} else {
				x = *(++big.begin());
			}
			p3 = {x, *rows[x].begin()};
			if (valid(p1, p2)) {
				res1 = p1, res2 = p2;
			} else if (valid(p1, p3)) {
				res1 = p1, res2 = p3;
			} else if (valid(p2, p3)) {
				res1 = p2, res2 = p3;
			} else {
				assert(false);
			}
			return true;
		}

		int y1 = (cols.begin())->first;
		int y2 = (--cols.end())->first;
		int x1 = *cols[y1].begin();
		int x2 = *cols[y2].begin();
		res1 = {x1, y1};
		res2 = {x2, y2};
		assert(valid(res1, res2));
		return true;
	}

};

void solve(vector<vector<int> >& g, vector<int>& compId, vector<vector<int> >& lst) {
	int n = sz(g);
	compId.assign(n, -1);
	int cc = 0;
	for (int i = 0; i < n; ++i) {
		if (compId[i] != -1) {
			continue;
		}
		lst.pb(vector<int>());
		queue<int> q;
		q.push(i);
		compId[i] = cc;
		lst[cc].pb(i);

		while (!q.empty()) {
			int v = q.front();
			q.pop();
			for (int to : g[v]) {
				if (compId[to] == -1) {
					compId[to] = cc;
					lst[cc].pb(to);
					q.push(to);
				}
			}
		}
		++cc;
	}
}

int main() {

	ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt", "r", stdin);

    int n, m1, m2;
    cin >> n >> m1 >> m2;

    vector<vector<int> > g1(n), g2(n);
    while (m1--) {
    	int u, v;
    	cin >> u >> v;
    	--u, --v;
    	g1[u].pb(v);
    	g1[v].pb(u);
    }
    while (m2--) {
    	int u, v;
    	cin >> u >> v;
    	--u, --v;
    	g2[u].pb(v);
    	g2[v].pb(u);
    }

    vector<int> c1, c2;
    vector<vector<int> > a1, a2;
    solve(g1, c1, a1);
    solve(g2, c2, a2);

   	map<pii, int> lst;
   	for (int i = 0; i < n; ++i) {
   		pii p = {c1[i], c2[i]};
   		//cout << "!" << p.first << " " << p.second << endl;
   		lst[p] = i;
   	}

   	vector<pii> ans;
   	Solver solver(lst);
   	pii res1, res2;

   	while (solver.get(res1, res2)) {
   		
   		int x = res1.first;
   		int y = res1.second;
   		int z = res2.first;
   		int t = res2.second;

   		ans.pb({lst[res1], lst[res2]});

   		if (sz(a1[x]) < sz(a1[z])) {
   			swap(x, z);
   		}
   		for (int v : a1[z]) {
   			pii pp = {c1[v], c2[v]};
   			solver.del(pp.first, pp.second);
   			lst.erase(pp);
   			pp.first = x;
   			solver.add(pp.first, pp.second);
   			lst[pp] = v;
   			c1[v] = x;
   			a1[x].pb(v);
   		}
   		a1[z].clear();

   		if (sz(a2[y]) < sz(a2[t])) {
   			swap(y, t);
   		}
   		for (int v : a2[t]) {
   			pii pp = {c1[v], c2[v]};
   			solver.del(pp.first, pp.second);
   			lst.erase(pp);
   			pp.second = y;
   			solver.add(pp.first, pp.second);
   			lst[pp] = v;
   			c2[v] = y;
   			a2[y].pb(v);
   		}
   		a2[t].clear();

   		/*for (auto it : lst) {
   			cout << "!" << it.first.first << " " << it.first.second << endl;
   		}
   		cout << endl;*/
   	}

   	cout << sz(ans) << "\n";
   	for (int i = 0; i < sz(ans); ++i) {
   		cout << ans[i].first + 1 << " " << ans[i].second + 1 << "\n";
   	}

}