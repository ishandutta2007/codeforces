#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:64000000")
#define _USE_MATH_DEFINES
#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<algorithm>
#include<cmath>
#include<set>
#include<queue>
#include<sstream>
#include<utility>
#include<map>
#include<ctime>
 
using std::pair;
using std::stringstream;
using std::next_permutation;
using std::sqrt;
using std::priority_queue;
using std::sort;
using std::stack;
using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::min;
using std::max;
using std::set;
using std::swap;
using std::random_shuffle;
using std::queue;
using std::sin;
using std::cos;
using std::make_pair;
using std::cos;
using std::cerr;
using std::map;
using std::clock;
 
 
typedef long long ll; 
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
const long double PI = 3.14159265358979323846;  
const double eps = 1e-12;
const int INF = 1000 * 1000 + 100;
const int mod = 1000 * 1000 * 1000 + 7;
int n, m;
vector<vector<int> > g;
vector<int> used;
vector<int> d;
vector<int> p;
vector<vector<int> > v;
vector<int> ind;
vector<vector<int> > gg;
vector<int> tin, tout;
int timer = 0;
vector<vector<int> > up;
vector<int> d2;
int l;

void dfs2(int pos, int pr = 0) {
	tin[pos] = ++timer;
	up[pos][0] = pr;
	if (pos)
		d2[pos] = d2[pr] + (v[pos].size() > 1);
	for (int i = 1; i <= l; ++i)
		up[pos][i] = up[up[pos][i - 1]][i - 1];
	for (int i = 0; i < gg[pos].size(); ++i) {
		int to = gg[pos][i];
		if (to != pr)
			dfs2(to, pos);
	}
	tout[pos] = ++timer;
}

bool upper (int a, int b) {
	return tin[a] <= tin[b] && tout[a] >= tout[b];
}

int lca (int a, int b) {
	if (upper (a, b))  return a;
	if (upper (b, a))  return b;
	for (int i = l; i >= 0; --i)
		if (!upper(up[a][i], b))
			a = up[a][i];
	return up[a][0];
}

void dfs(int pos, int pr = -1) {
	used[pos] = true;
	p[pos] = pr;
	if (pr != -1)
		d[pos] = d[pr] + 1;
	for (int i = 0; i < g[pos].size(); ++i) {
		int to = g[pos][i];
		if (to == pr)
			continue;
		if (!used[to])
			dfs(to, pos);
		else {
			if (ind[pos] != -1)
				continue;
			int ppos = pos;
			vector<int> cycle;
			//cycle.push_back(to);
			//cycle.push_back(pos);
			while (d[to] < d[ppos]) {
				cycle.push_back(ppos);
				ppos = p[ppos];
			}
			while (d[to] > d[ppos]) {
				cycle.push_back(to);
				to = p[to];
			}
			while (to != ppos) {
				cycle.push_back(ppos);
				ppos = p[ppos];
				cycle.push_back(to);
				to = p[to];
			}
			cycle.push_back(to);
			v.push_back(cycle);
			for (int i = 0; i < cycle.size(); ++i)
				ind[cycle[i]] = v.size() - 1;
		}
	}
}


int pow(int n) {
	ll res = 1;
	ll a = 2;
	while (n) {
		if (n & 1) {
			res = (res * a) % mod;
		}
		a = (a * a) % mod;
		n >>= 1;
	}
	return res;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> n >> m;
	ind.assign(n, -1);
	g.resize(n);
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		--a;
		--b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	used.assign(n, 0);
	d.resize(n);
	d[0] = 0;
	p.resize(n);
	dfs(0);
	for (int i = 0; i < n; ++i) {
		if (ind[i] == -1) {
			ind[i] = v.size();
			v.push_back(vector<int> (1, i));
		}
	}
	gg.resize(v.size());
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < g[i].size(); ++j) {
			if (ind[i] != ind[g[i][j]])
				gg[ind[i]].push_back(ind[g[i][j]]);
		}
	}
	tin.resize(gg.size()), tout.resize (gg.size()), up.resize(gg.size());
	l = 1;
	while ((1<<l) <= gg.size())  ++l;
	for (int i = 0; i < gg.size(); ++i)  
		up[i].resize(l+1);
	d2.resize(gg.size());
	d2[0] = 0;
	dfs2(0);
	int q;
	cin >> q;
	for (int i = 0; i < q; ++i) {
		int a, b;
		cin >> a >> b;
		--a;
		--b;
		int aa = ind[a];
		int bb = ind[b];
		int c = lca(aa, bb);
		int res = d2[aa] + d2[bb] - 2 * d2[c];
		if (v[c].size() > 1)
			++res;
		cout << pow(res) << endl;
	}

	return 0;
}