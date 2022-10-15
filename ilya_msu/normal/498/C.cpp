#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:256000000")
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
#include<functional>




using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef pair<char, char> pcc;
typedef pair<double, double> pdd;

#define show(x) cerr << x
#define debug(x) show(#x << ": " << (x) << endl)

const long double PI = 3.14159265358979323846;
const long double gammama = 0.57721566490153286060;
const long double eps = 1e-5;
const int INF = 1000 * 1000 * 1000 + 1;
const ll LINF = (ll)1000 * 1000 * 1000 * 1000 * 1000 * 1000;
const ll mod = 1000 * 1000 * 1000 + 7;
const ll N = 1001;
//const int M = 10000000;


int sz0, sz1;
vector < vector<int> > g;
vector<int> mt;
vector<char> used;

bool kun(int v) {
	if (used[v])  return false;
	used[v] = true;
	for (int i = 0; i < g[v].size(); ++i) {
		int to = g[v][i];
		if (mt[to] == -1 || kun(mt[to])) {
			mt[to] = v;
			return true;
		}
	}
	return false;
}

int getMatch(const vector<vector<int> > g) {
	int res = 0;
	mt.assign(sz1, -1);
	for (int v = 0; v < sz0; ++v) {
		used.assign(sz0, false);
		if (kun(v))
			++res;
	}
	return res;
}

vector<vector<int> > getGraph(const vector<int>& c, const vector<pii>& ed) {
	int n = c.size();
	vector<int> sum0(1, 0), sum1(1, 0);
	int s = 0;
	for (int i = 0; i < n; i += 2) {
		s = s + c[i];
		sum0.push_back(s);
	}
	s = 0;
	for (int i = 1; i < n; i += 2) {
		s = s + c[i];
		sum1.push_back(s);
	}
	vector<vector<int> > res(sz0);
	for (int i = 0; i < ed.size(); ++i) {
		int id0 = ed[i].first / 2, id1 = ed[i].second / 2;
		for (int j0 = sum0[id0]; j0 < sum0[id0 + 1]; ++j0) {
			for (int j1 = sum1[id1]; j1 < sum1[id1 + 1]; ++j1) {
				res[j0].push_back(j1);
			}
		}
	}
	return res;
}

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	vector<pii> ed(m);
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	for (int i = 0; i < m; ++i) {
		cin >> ed[i].first >> ed[i].second;
		--ed[i].first, --ed[i].second;
		if (ed[i].first & 1)
			swap(ed[i].first, ed[i].second);
	}
	set<int> pr;
	for (int i = 0; i < n; ++i) {
		int x = a[i];
		for (int d = 2; d * d <= x; ++d) {
			if (x % d == 0) {
				while (x % d == 0)
					x /= d;
				pr.insert(d);
			}
		}
		if (x != 1)
			pr.insert(x);
	}
	ll res = 0;
	for (set<int>::iterator it = pr.begin(); it != pr.end(); ++it) {
		vector<int> c(n);
		int p = *it;
		sz0 = 0, sz1 = 0;
		for (int i = 0; i < n; ++i) {
			int x = a[i];
			while (x % p == 0) {
				x /= p;
				++c[i];
			}
			if (i & 1)
				sz1 += c[i];
			else
				sz0 += c[i];
		}
		
		g = getGraph(c, ed);
		res += getMatch(g);
	}
	cout << res << endl;
}

//#define LOCAL

int main() {
	ios_base::sync_with_stdio(0);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	solve();


#ifdef LOCAL
	cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif	
	return 0;
}