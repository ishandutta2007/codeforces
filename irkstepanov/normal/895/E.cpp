#include <iostream>
#include <fstream>
#include <set>
#include <string>
#include <map>
#include <queue>
#include <algorithm>
#include <deque>
#include <memory.h>
#include <assert.h>
#include <cstring>
#include <cmath>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;
typedef pair<ll, ll> pll;

struct node {
	ld mean;
	ld add;
	ld mul;
	node() : mean(0), add(0), mul(1) {}
};

vector<node> t;

void push(int v) {
	t[v * 2].mean *= t[v].mul;
	t[v * 2].mul *= t[v].mul;
	t[v * 2].add *= t[v].mul;
	t[v * 2 + 1].mean *= t[v].mul;
	t[v * 2 + 1].mul *= t[v].mul;
	t[v * 2 + 1].add *= t[v].mul;
	t[v].mul = 1;
	t[v * 2].mean += t[v].add;
	t[v * 2].add += t[v].add;
	t[v * 2 + 1].mean += t[v].add;
	t[v * 2 + 1].add += t[v].add;
	t[v].add = 0;
}

void mul(int v, int tl, int tr, int l, int r, ld val) {
	if (tl == l && tr == r) {
		t[v].mean *= val;
		t[v].mul *= val;
		t[v].add *= val;
		return;
	}
	push(v);
	int tm = (tl + tr) >> 1;
	if (l <= tm) {
		mul(v * 2, tl, tm, l, min(r, tm), val);
	}
	if (r > tm) {
		mul(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, val);
	}
	t[v].mean = (t[v * 2].mean * (tm - tl + 1) + t[v * 2 + 1].mean * (tr - tm)) / (tr - tl + 1);
}

void add(int v, int tl, int tr, int l, int r, ld val) {
	if (tl == l && tr == r) {
		t[v].mean += val;
		t[v].add += val;
		return;
	}
	push(v);
	int tm = (tl + tr) >> 1;
	if (l <= tm) {
		add(v * 2, tl, tm, l, min(r, tm), val);
	}
	if (r > tm) {
		add(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, val);
	}
	t[v].mean = (t[v * 2].mean * (tm - tl + 1) + t[v * 2 + 1].mean * (tr - tm)) / (tr - tl + 1);
}

void build(int v, int tl, int tr, vector<ld>& a) {
	if (tl == tr) {
		t[v].mean = a[tl];
		return;
	}
	int tm = (tl + tr) >> 1;
	build(v * 2, tl, tm, a);
	build(v * 2 + 1, tm + 1, tr, a);
	t[v].mean = (t[v * 2].mean * (tm - tl + 1) + t[v * 2 + 1].mean * (tr - tm)) / (tr - tl + 1);
}

ld get(int v, int tl, int tr, int l, int r) {
	if (tl == l && tr == r) {
		return t[v].mean * (tr - tl + 1);
	}
	push(v);
	ld ans = 0;
	int tm = (tl + tr) >> 1;
	if (l <= tm) {
		ans += get(v * 2, tl, tm, l, min(r, tm));
	}
	if (r > tm) {
		ans += get(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
	}
	return ans;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

	//ifstream cin("input.txt");
    //ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

	int n, q;
	cin >> n >> q;
	vector<ld> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	t.resize(4 * n);
	build(1, 0, n - 1, a);

	while (q--) {
		int type;
		cin >> type;
		if (type == 2) {
			int l, r;
			cin >> l >> r;
			--l, --r;
			ld val = get(1, 0, n - 1, l, r);
			cout << fixed;
			cout.precision(20);
			cout << val << "\n";
		} else {
			int l1, r1, l2, r2;
			cin >> l1 >> r1 >> l2 >> r2;
			--l1, --r1, --l2, --r2;
			int x = r1 - l1 + 1;
			int y = r2 - l2 + 1;
			ld lf = get(1, 0, n - 1, l1, r1);
			ld rg = get(1, 0, n - 1, l2, r2);
			mul(1, 0, n - 1, l1, r1, ld(x - 1) / x);
			mul(1, 0, n - 1, l2, r2, ld(y - 1) / y);
			add(1, 0, n - 1, l1, r1, rg / y / x);
			add(1, 0, n - 1, l2, r2, lf / y / x);
		}
	}

}