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


struct SegTree {
	int n, N;
	vector<int> a;
	int build(int v, int l, int r, const vector<int>& b) {
		if (l == r) {
			a[v] = b[l];
			return a[v];
		}
		int m = (l + r) / 2;
		a[v] = max(build(2 * v, l, m, b), build(2 * v + 1, m + 1, r, b));
		return a[v];
	}
	SegTree(const vector<int>& b) {
		n = b.size(); 
		N = 4 * n + 10;
		a.assign(N, 0);
		build(1, 0, n - 1, b);
	}
	int get(int v, int tl, int tr, int l, int r) {
		if ((tr < l) || (tl > r))
			return 0;
		if ((tl >= l) && (tr <= r))
			return a[v];
		int tm = (tl + tr) / 2;
		return max(get(2 * v, tl, tm, l, r), get(2 * v + 1, tm + 1, tr, l, r));
	}
	int get(int l, int r) {
		return get(1, 0, n - 1, l, r);
	}
};

struct vertex {
	int l, r;
	double p;
	int a;
};

vector<vector<int> > g;
vector<int> pr;
vector<vertex> b;

vector<vector<double> > res;

bool operator<(const vertex& a, const vertex& b) {
	return (a.l < b.l) || ((a.l == b.l) && (a.r > b.r));
}

double get(const vector<double> a) {
	double ans = 1;
	for (int i = 0; i < a.size(); ++i)
		ans *= 1 - a[i];
	return 1 - ans;
}

double getRes(int pos, int add) {
	if (add <= 0)
		return 1.0;
	if (add >= res[pos].size())
		return 0;
	if (res[pos][add] > -0.5)
		return res[pos][add];
	double res1 = 1, res0 = 1;
	int need1 = b[pos].a + add - 1, need0 = b[pos].a + add;
	for (int i = 0; i < g[pos].size(); ++i) {
		int to = g[pos][i];
		res1 *= 1 - getRes(to, need1 - b[to].a);
		res0 *= 1 - getRes(to, need0 - b[to].a);
	}
	res1 = 1 - res1;
	res0 = 1 - res0;
	double ans = b[pos].p * res1 + (1 - b[pos].p) * res0;
	if (add == 1)
		ans = b[pos].p + (1 - b[pos].p) * res0;
	res[pos][add] = ans;
	return ans;
}

void solve() {
	int n, q;
	cin >> n >> q;
	vector<int> a(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	SegTree tr(a);
	b.resize(q + 1);
	for (int i = 0; i < q; ++i) {
		cin >> b[i].l >> b[i].r >> b[i].p;
		--b[i].l, --b[i].r;
	}
	b[q].l = 0, b[q].r = n - 1, b[q].p = 0;
	sort(b.begin(), b.end());
	g.resize(q + 1);
	pr.assign(q + 1, -1);
	int cur = 0;
	for (int i = 0; i < b.size(); ++i) {
		b[i].a = tr.get(b[i].l, b[i].r);
		if (i == 0)
			continue;
		while (!((b[i].l >= b[cur].l) && (b[i].r <= b[cur].r)))
			cur = pr[cur];
		g[cur].push_back(i);
		pr[i] = cur;
		cur = i;
	}
	res.assign(q + 1, vector<double>(q + 1, -1));
	double ans = b[0].a;
	for (int i = 1; i < q + 1; ++i) {
		ans += getRes(0, i);
	}
	printf("%0.12f\n", ans);
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