#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:128000000")
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
#include<cstdio>
#include<cassert>

#define show(x) cerr << x
#define debug(x) show(#x << ": " << (x) << endl)

using namespace std; 
 
typedef long long ll; 
typedef pair<ll, ll> pll;
typedef pair<long double, long double> pdd;

typedef pair<int, int> pii;
const long double PI = 3.14159265358979323846;  
const long double gammama = 0.57721566490153286060;
//const long double eps = 1e-5;
const int INF = 1000 * 1000 * 1000 + 10;
const int N = 100 * 1000 + 10;
const int MOD = 1000 * 1000 * 1000 + 7;
const ll LINF = (ll)1000 * 1000 * 1000 * 1000 * 1000 * 1000;

struct edge {
	int a, b, c;
	edge(int aa, int bb, int cc) : a(aa), b(bb), c(cc) {}
};

bool operator<(const edge& a, const edge& b) {
	return a.c < b.c;
}

int get(const vector<string>& a, const vector<string>& b) {
	int n = a.size();
	int m = a[0].size();
	int res = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (a[i][j] != b[i][j])
				++res;
	return res;
}

struct dsu {
	int n;
	vector<int> p, d;
	dsu(int nn) {
		n = nn;
		p.resize(n);
		for (int i = 0; i < n; ++i)
			p[i] = i;
		d.assign(n, 1);
	}
	int find(int pos) {
		if (p[pos] == pos)
			return pos;
		int r = find(p[pos]);
		p[pos] = r;
		return r;
	}
	bool eq(int p1, int p2) {
		return (find(p1) == find(p2));
	}
	void unite(int p1, int p2) {
		int r1 = find(p1), r2 = find(p2);
		if (d[r1] < d[r2]) {
			p[r1] = r2;
			d[r2] += d[r1];
		}
		else {
			p[r2] = r1;
			d[r1] += d[r2];
		}
	}
};

vector<int> pr;
vector<vector<int> > g;
vector<pii> order;
void dfs(int pos) {
	order.push_back(pii(pos, pr[pos]));
	for (int i = 0; i < g[pos].size(); ++i) {
		int to = g[pos][i];
		if (to == pr[pos])
			continue;
		pr[to] = pos;
		dfs(to);
	}

}

int main() {
	//ios_base::sync_with_stdio(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m, k, w;
	cin >> n >> m >> k >> w;
	vector<vector<string> > lev(k, vector<string>(n));
	for (int i = 0; i < k; ++i) {
		for (int j = 0; j < n; ++j)
			cin >> lev[i][j];
	}
	vector<edge> e;
	for (int i = 0; i < k; ++i)
		for (int j = 0; j < i; ++j)
			e.push_back(edge(i, j, min(m * n, w * get(lev[i], lev[j]))));
	sort(e.begin(), e.end());
	dsu tr(k);
	int res = m * n;
	g.resize(k);
	for (int i = 0; i < e.size(); ++i) {
		if (tr.eq(e[i].a, e[i].b))
			continue;
		res += e[i].c;
		tr.unite(e[i].a, e[i].b);
		if (e[i].c < m * n) {
			g[e[i].a].push_back(e[i].b);
			g[e[i].b].push_back(e[i].a);
		}
	}
	pr.assign(k, -1);
	for (int i = 0; i < k; ++i) 
		if (pr[i] == -1)
			dfs(i);
	cout << res << endl;
	for (int i = 0; i < k; ++i)
		cout << order[i].first + 1 << " " << order[i].second + 1 << "\n";
	

	return 0;
}