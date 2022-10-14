#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
const ll mod = 1000000007ll;
struct dsu {
	vi r, p, val;
	void init(int n) {
		r.assign(n, 1);
		p.assign(n, 1);
		val.assign(n, 1);
		for (int i = 0; i < n; i++)
			p[i] = i;
	}
	int par(int i) {
		if (i == p[i])
			return i;
		return p[i] = par(p[i]);
	}
	void unite(int i, int j) {
		i = par(i), j = par(j);
		if (i == j)
			return;
		if (r[i] < r[j])
			swap(i, j);
		p[j] = i;
		r[i] += r[i] == r[j];
	}
	void maxset(int i, ll x) {
		i = par(i);
		val[i] = max(val[i], x);
	}
	int get(int i) {
		i = par(i);
		return val[i];
	}
};
int main() {
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	int n, m;
	vi a;
	cin >> n >> m;
	vvi mat;
	mat.resize(n, vi(m));
	for (auto &i : mat) {
		for (auto &j : i) {
			cin >> j;
			a.pb(j);
		}
	}
	sort(all(a));
	a.erase(unique(all(a)), a.end());
	for (auto &i : mat)
		for (auto &j : i)
			j = lower_bound(all(a), j) - a.begin();
	vvi res(a.size());
	vi rowmax(n, 0);
	vi colmax(m, 0);
	vi p(a.size(), -1);
	dsu d;
	d.init(n * m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int v = mat[i][j];
			if (p[v] != -1 && p[v] / m == i) {
				d.unite(p[v], i * m + j);
			}
			p[v] = i * m + j;
		}
	}
	p.assign(a.size(), -1);
	for (int j = 0; j < m; j++) {
		for (int i = 0; i < n; i++) {
			int v = mat[i][j];
			if (p[v] != -1 && p[v] % m == j) {
				d.unite(p[v], i * m + j);
			}
			p[v] = i * m + j;
		}
	}


	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			res[mat[i][j]].pb(i*m + j);
	vvi ans(n, vi(m, 0));
	for(int i = 0; i < a.size(); i++) {
		for(auto j : res[i]) {
			d.maxset(j, rowmax[j/m]+1);
			d.maxset(j, colmax[j%m]+1);
		}
		for(auto j : res[i]) {
			ans[j/m][j%m] = d.get(j);
			rowmax[j/m] = max(rowmax[j/m], (ll)d.get(j));
			colmax[j%m] = max(colmax[j%m], (ll)d.get(j));
		}
	}
	for(auto & i : ans) {
		for(auto &j : i)
			cout << j << " ";
		cout << "\n";
	}
}