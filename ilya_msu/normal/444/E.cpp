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
#include<hash_map>

 
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

struct edge {
	int a, b, c;
	edge(int aa, int bb, int cc) : a(aa), b(bb), c(cc) {}
	edge() {}
};

bool operator<(const edge& a, const edge& b) {
	return a.c < b.c;
}

struct dsu {
	int n;
	vector<int> p;
	vector<int> r;
	dsu(int nn) {
		n = nn;
		p.resize(n);
		for (int i = 0; i < n; ++i)
			p[i] = i;
		r.assign(n, 1);
	}
	int find(int x) {
		if (x == p[x])
			return x;
		p[x] = find(p[x]);
		return p[x];
	}
	int unite(int x, int y) {
		int r1 = find(x), r2 = find(y);
		if (r[r1] < r[r2])
			swap(r1, r2);
		p[r2] = r1, r[r1] += r[r2];
		return r1;
	}
};

int main() {
	//ios_base::sync_with_stdio(0);
	//freopen("INPUT.TXT", "r", stdin);
	//freopen("OUTPUT.TXT", "w", stdout);
	int n;
	cin >> n;
	vector<edge> e(n - 1);
	for (int i = 0; i + 1 < n; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		e[i] = edge(a - 1, b - 1, c);
	}
	sort(e.begin(), e.end());
	vector<int> x(n);
	for (int i = 0; i < n; ++i)
		cin >> x[i];
	int down = 0, up = 10001;
	while(up - down > 1) {
		int val = (down + up) / 2;
		vector<int> w(n);
		for (int i = 0; i < n; ++i)
			w[i] = x[i];
		vector<int> sz(n, 1);
		vector<int> ans(n, 0);
		dsu t(n);
		for (int i = 0; i < e.size(); ++i) {
			int r1 = t.find(e[i].a), r2 = t.find(e[i].b);
			int r = t.unite(r1, r2);
			if (e[i].c >= val) {
				int e12 = min(sz[r1], w[r2]);
				int e21 = min(sz[r2], w[r1]);
				int e11 = min(min(ans[r1], w[r1] - e21), sz[r1] - e12);
				int e22 = min(min(ans[r2], w[r2] - e12), sz[r2] - e21);
				int res = e12 + e21 + e11 + e22;
				int w1 = w[r1] - e21 - e11, w2 = w[r2] - e12 - e22, a1 = ans[r1] - e11, a2 = ans[r2] - e22, sz1 = sz[r1] - e12 - e11, sz2 = sz[r2] - e21 - e22;
				//while ((w1 > 0) && (w2 == 0) && (a1 > 0) && (sz1 > 0) && (e21 > 0)) {
				//	//++w2;
				//	//++sz1;
				//	--e12;

				//	--a2;
				//	++e22;
				//	//--w2;
				//	--sz2;

				//	//--sz1;
				//	--a1;
				//	++e11;
				//	--w1;
				//}
				if (w2 == 0)
					res += min(a2, min(sz2, min(a1, w1)));
				if (w1 == 0)
					res += min(a1, min(sz1, min(a2, w2)));
				ans[r] = res;
				


				
			}
			w[r] = w[r1] + w[r2];
			sz[r] = sz[r1] + sz[r2];
		}
		if (ans[t.find(0)] == n)
			down = val;
		else
			up = val;
	}
	cout << down << "\n";
	return 0;
}