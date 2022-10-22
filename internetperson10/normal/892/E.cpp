#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

vector<pair<pair<int, int>, pair<int, int>>> edges;
vector<pair<int, int>> ord_edges;
vector<vector<pair<int, int>>> combines;
vector<pair<int, int>> combine;
vector<pair<int, pair<int, int>>> nums;
map<int, vector<pair<int, int>>> treeset;

struct dsu {
	vector<int> par, siz;
	void init(int n) {
		par.resize(n+1);
		siz.resize(n+1);
		for(int i = 1; i <= n; i++) {
			par[i] = i;
			siz[i] = 1;
		}
	}
	int find(int i) {
		if(par[i] == i) return i;
		return par[i] = find(par[i]);
	}
	bool unite(int x, int y) {
		x = find(x); y = find(y);
		if(x == y) {
			return false;
		}
		if(siz[x] < siz[y]) swap(x, y);
		par[y] = x;
		siz[x] += siz[y];
		return true;
	}
};

struct dsu_comp {
	vector<int> par, siz, num, ant;
	int k = 1;
	void init(int n) {
		par.resize(n+1);
		siz.resize(n+1);
		num.resize(n+1);
		ant.resize(n+1);
		for(int i = 1; i <= n; i++) {
			par[i] = i;
			siz[i] = 1;
			num[i] = 0;
			ant[i] = 0;
		}
	}
	void reset() {
		for(int i = 1; i < k; i++) {
			int x = ant[i];
			par[i] = i;
			siz[i] = 1;
			num[x] = 0;
			ant[i] = 0;
		}
		k = 1;
	}
	int get(int i) {
		if(!num[i]) {
			ant[k] = i;
			num[i] = k;
			k++;
		}
		return num[i];
	}
	int find(int i) {
		if(par[i] == i) return i;
		return par[i] = find(par[i]);
	}
	int unite(int x, int y) {
		x = find(x); y = find(y);
		if(x == y) {
			return false;
		}
		if(siz[x] < siz[y]) swap(x, y);
		par[y] = x;
		siz[x] += siz[y];
		return true;
	}
	void print() {
		for(int i = 1; i < par.size(); i++) {
			cout << par[i] << ' ' << siz[i] << ' ' << num[i] << ' ' << ant[i] << '\n';
		}
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, m, q, conn, k = 0, x, ed;
	cin >> n >> m;
	conn = n-1;
	dsu uf;
	uf.init(n);
	edges.resize(m);
	ord_edges.resize(m);
	nums.resize(m+1);
	for(int i = 0; i < m; i++) {
		nums[i].first = -1;
	}
	for(int i = 0; i < m; i++) {
		cin >> edges[i].second.first >> edges[i].second.second >> edges[i].first.first;
		edges[i].first.second = i;
		ord_edges[i] = edges[i].second;
	}
	sort(edges.begin(), edges.end());
	for(int i = 0; conn; i++) {
		if(i > 0 && i < m) {
			if(edges[i].first.first > edges[i-1].first.first && combine.size()) {
				combines.push_back(combine);
				k++;
				for(int j = 0; j < combine.size(); j++) {
					if(uf.unite(combine[j].first, combine[j].second)){
						conn--;
					} 
				}
				vector<pair<int, int>>().swap(combine);
			}
		}
		else if(i == m) {
			combines.push_back(combine);
			k++;
			for(int j = 0; j < combine.size(); j++) {
				if(uf.unite(combine[j].first, combine[j].second)){
					conn--;
				} 
			}
			vector<pair<int, int>>().swap(combine);
		}
		if(!conn) break;
		auto p1 = edges[i].first, p2 = edges[i].second;
		int x = uf.find(p2.first), y = uf.find(p2.second);
		if(x != y) {
			combine.push_back({x, y});
			nums[p1.second] = {k, {x, y}};
		}
	}
	dsu_comp uf_comp;
	uf_comp.init(n);
	cin >> q;
	while(q--) {
		cin >> x;
		map<int, vector<pair<int, int>>>().swap(treeset);
		bool sad = false;
		for(int i = 0; i < x; i++) {
			cin >> ed;
			ed--;
			int xx = nums[ed].first, a = nums[ed].second.first, b = nums[ed].second.second;
			// cout << xx << ' ';
			if(xx == -1) sad = true;
			else treeset[xx].push_back({a, b});
		}
		for(auto v : treeset) {
			if(sad) break;
			uf_comp.reset();
			// cout << v.first << " uwu\n";
			for(auto p : v.second) {
				// cout << "Uniting " << p.first << ' ' << p.second << '\n';
				if(!uf_comp.unite(uf_comp.get(p.first), uf_comp.get(p.second))) {
					sad = true;
					// cout << "Boo hoo" << endl;
				}
				// uf_comp.print();
			}
		}
		if(sad) cout << "NO\n";
		else cout << "YES\n";
		// cout << endl;
	}
}