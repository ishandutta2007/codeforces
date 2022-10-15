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
const int INF = 1000 * 1000 * 1000 + 100;
const ll LINF = (ll)1000 * 1000 * 1000 * 1000 * 1000 * 1000;
const ll mod = 1000 * 1000 * 1000 + 7;
const ll N = 2000 * 1000 + 1;
//const int M = 10000000;

struct SegTree {
	int n;
	vector<int> a;
	SegTree(int nn) {
		n = nn;
		a.assign(4 * n + 10, INF);
	}
	void set(int v, int l, int r, int id, int val) {
		if (r < id)
			return;
		if (l > id)
			return;
		if (l == r) {
			a[v] = val;
			return;
		}
		int m = (l + r) / 2;
		set(2 * v, l, m, id, val);
		set(2 * v + 1, m + 1, r, id, val);
		a[v] = min(a[2 * v], a[2 * v + 1]);
	}
	void set(int id, int val) {
		set(1, 0, n - 1, id, val);
	}
	int get(int v, int tl, int tr, int l, int r) {
		if ((tr < l) || (tl > r))
			return INF;
		if ((tl >= l) && (tr <= r))
			return a[v];
		int m = (tl + tr) / 2;
		return min(get(2 * v, tl, m, l, r), get(2 * v + 1, m + 1, tr, l, r));		
	}
	int get(int l, int r) {
		return get(1, 0, n - 1, l, r);
	}
};

void solve() {
	int n, s, l;
	cin >> n >> s >> l;
	vector<int> a(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	SegTree res(n), val(n), nval(n);
	int bound = 0;
	for (int i = 0; i < n; ++i) {
		val.set(i, a[i]);
		nval.set(i, -a[i]);
		int upBound = a[i] + s, lowBound = a[i] - s;
		while ((val.get(bound, i) < lowBound) || (-nval.get(bound, i) > upBound))
			++bound;
		
		if (i - bound + 1 < l)
			continue;
		if (bound == 0)
			res.set(i, 1);
		else
			res.set(i, min(res.get(bound - 1, i - l) + 1, INF));
	}
	if (res.get(n - 1, n - 1) >= INF)
		cout << -1 << endl;
	else
		cout << res.get(n - 1, n - 1) << endl;
}



//#define LOCAL

int main() {
	//ios_base::sync_with_stdio(0);
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