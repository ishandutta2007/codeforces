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

struct SegTree {
	int n, sz;
	vector<ll> col, sum, add;
	void build(int v, int l, int r) {
		if (l == r) {
			col[v] = l;
			return;
		}
		int m = (l + r) / 2;
		col[v] = 0;
		build(2 * v, l, m);
		build(2 * v + 1, m + 1, r);
	}
	SegTree(int nn) {
		n = nn;
		sz = 4 * n + 10;
		col.resize(sz);
		sum.assign(sz, 0);
		add.assign(sz, 0);
		build(1, 1, n);
	}
	void update(int v, int tl, int tr, ll x) {
		if (col[v] > 0) {
			add[v] += abs(x - col[v]);
			sum[v] += abs(x - col[v]) * (tr - tl + 1);
		}
		else {
			int m = (tl + tr) / 2;
			update(2 * v, tl, m, x);
			update(2 * v + 1, m + 1, tr, x);
			sum[v] = sum[2 * v] + sum[2 * v + 1] + add[v] * (tr - tl + 1);
		}
		col[v] = -1;
	}
	void update(int v, int tl, int tr, int l, int r, ll x) {
		if ((tl >= l) && (tr <= r)) {
			update(v, tl, tr, x);
			col[v] = x;
			return;
		}
		if (col[v] > 0) {
			col[2 * v + 1] = col[2 * v] = col[v];
			col[v] = 0;
		}
		int m = (tl + tr) / 2;
		if (r <= m) {
			update(2 * v, tl, m, l, r, x);
		}
		else {
			if (l > m) {
				update(2 * v + 1, m + 1, tr, l, r, x);
			}
			else {
				update(2 * v, tl, m, l, m, x);
				update(2 * v + 1, m + 1, tr, m + 1, r, x);
			}
		}	
		sum[v] = sum[2 * v] + sum[2 * v + 1] + add[v] * (tr - tl + 1);
		col[v] = 0;
	}
	void update(int l, int r, ll x) {
		update(1, 1, n, l, r, x);
	}
	ll getSum(int v, int tl, int tr, int l, int r) {
		if ((tl == l) && (tr == r)) 
			return sum[v];
		int m = (tl + tr) / 2;
		if (r <= m)
			return getSum(2 * v, tl, m, l, r) + add[v] * (r - l + 1);
		if (l > m)
			return getSum(2 * v + 1, m + 1, tr, l, r) + add[v] * (r - l + 1);
		return getSum(2 * v, tl, m, l, m) + getSum(2 * v + 1, m + 1, tr, m + 1, r) + add[v] * (r - l + 1);
	}
	ll getSum(int l, int r) {
		return getSum(1, 1, n, l, r);
	}
};

int main() {
	//ios_base::sync_with_stdio(0);
	//freopen("INPUT.TXT", "r", stdin);
	//freopen("OUTPUT.TXT", "w", stdout);
	int n, m;
	cin >> n >> m;
	SegTree tr(n);
	for (int i = 0; i < m; ++i) {
		int type;
		cin >> type;
		if (type == 1) {
			int l, r, x;
			cin >> l >> r >> x;
			tr.update(l, r, x);
		}
		else {
			int l, r;
			cin >> l >> r;
			cout << tr.getSum(l, r) << "\n";
		}
	}


	return 0;
}