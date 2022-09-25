#include <iostream>
#include <string>
#include <map> 
#include <math.h>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#include <queue>
#include <sstream>
#include <deque>
#include <memory.h>


using namespace std;

#define ll long long
#pragma comment(linker, "/STACK:64000000")

const int maxn = 1 << 18;
const int inf = 1000000007;
const int mod = 1000000000 ;


int f[maxn];

int magic(int f0, int f1, int n) {
	if (n == 0) return f0;
	if (n == 1) return f1;
	return (1LL * f1 * f[n - 1] + 1LL * f0 * f[n - 2]) % mod;
}


int n, m;
int a[maxn], q[maxn], x1[maxn], x2[maxn], x3[maxn];

bool reading() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	for (int i = 0; i < m; i++) {
		scanf("%d%d%d", &q[i], &x1[i], &x2[i]);
		if (q[i] == 3) scanf("%d", &x3[i]);
	}
	return 1;
}

void print(vector<int> v) {
	for (int i = 0; i < v.size(); i++) cout << v[i] << endl;
}

vector<int> slowsolve() {
	vector<int> res;
	vector<int> A(n); for (int i = 0; i < n; i++) A[i] = a[i];
	for (int i = 0; i < m; i++) {
		if (q[i] == 1) {
			a[x1[i] - 1] = x2[i];
		}
		if (q[i] == 2) {
			int f0 = 1, f1 = 1, ans = 0;
			for (int j = x1[i] - 1; j <= x2[i] - 1; j++) {
				ans = (ans + (1LL * a[j] * f0 % mod)) % mod;
				int f2 = (f0 + f1) % mod;
				f0 = f1;
				f1 = f2;
			}
			res.push_back(ans);
		}
	}
	for (int i = 0; i < n; i++) a[i] = A[i];
	return res;
}

pair<int, int> t[2 * maxn];

void build(int v, int tl, int tr) {
	if (tl == tr) {
		t[v] = make_pair(a[tl], a[tr]);
		return;
	}
	int tm = (tl + tr) >> 1;
	build(v * 2, tl, tm);
	build(v * 2 + 1, tm + 1, tr);
	t[v].first = t[v * 2].first + magic(t[v * 2 + 1].first, t[v * 2 + 1].second, tm - tl + 1); if (t[v].first >= mod) t[v].first -= mod;
	t[v].second = t[v * 2].second + magic(t[v * 2 + 1].first, t[v * 2 + 1].second, tm - tl + 2); if (t[v].second >= mod) t[v].second -= mod;
}

void upd(int v, int tl, int tr, int x, int y) {
	if (tl == tr) {
		t[v] = make_pair(y, y);
		return;
	}
	int tm = (tl + tr) >> 1;
	if (x <= tm) upd(v * 2, tl, tm, x, y);
	else upd(v * 2 + 1, tm + 1, tr, x, y);
	t[v].first = t[v * 2].first + magic(t[v * 2 + 1].first, t[v * 2 + 1].second, tm - tl + 1); if (t[v].first >= mod) t[v].first -= mod;
	t[v].second = t[v * 2].second + magic(t[v * 2 + 1].first, t[v * 2 + 1].second, tm - tl + 2); if (t[v].second >= mod) t[v].second -= mod;
}

pair<int, int> get(int v, int tl, int tr, int l, int r) {
	if (l > r) return make_pair(0, 0);
	if (l == tl && r == tr) return t[v];
	int tm = (tl + tr) >> 1;
	pair<int, int> o1 = get(v * 2, tl, tm, l, min(r, tm));
	pair<int, int> o2 = get(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
	pair<int, int> o;
	o.first = o1.first + magic(o2.first, o2.second, max(0, tm - l + 1)); if (o.first >= mod) o.first -= mod;
	o.second = o1.second + magic(o2.first, o2.second, max(0, tm - l + 2)); if (o.second >= mod) o.second -= mod;
	return o;
}

vector<int> fastsolve() {
	vector<int> res;
	build(1, 0, n - 1);
	for (int i = 0; i < m; i++) {
		if (q[i] == 1) {
			upd(1, 0, n - 1, x1[i] - 1, x2[i]);
		}
		if (q[i] == 2) {
			res.push_back(get(1, 0, n - 1, x1[i] - 1, x2[i] - 1).first);
		}
	}
	return res;
}

void gen() {
	n = rand() % 30 + 1;
	m = rand() % 30 + 1;
	for (int i = 0; i < n; i++) a[i] = rand() % 10 + 1;
	for (int i = 0; i < m; i++) {
		q[i] = rand() % 2 + 1;
		x1[i] = rand() % n + 1;
		x2[i] = rand() % n + 1;
		if (x1[i] > x2[i]) swap(x1[i], x2[i]);
		x3[i] = rand() % n + 1;
	}
}

void stress() {
	for (int it = 0; it < 10000; it++) {
		gen();
		vector<int> a2 = fastsolve();
		vector<int> a1 = slowsolve();
		if (a1 != a2) {
			cout << n << " " << m << endl;
			for (int i = 0; i < n; i++) cout << a[i] << " \n"[i + 1 == n];
			for (int i = 0; i < m; i++) {
				cout << q[i] << " " << x1[i] << " " << x2[i];
				if (q[i] == 3) cout << " " << x3[i];
				cout << endl;
			}
			cout << endl;
			for (int i = 0; i < a1.size(); i++) cout << a1[i] << " \n"[i + 1 == a1.size()];
			for (int i = 0; i < a2.size(); i++) cout << a2[i] << " \n"[i + 1 == a2.size()];
			cout << it << endl;
			fastsolve();
			slowsolve();
			break;
		}
		cerr << it << endl;
	}
	exit(0);
}

void precalc() {
	f[0] = 1;
	f[1] = 1;
	for (int i = 2; i < maxn; i++) f[i] = (f[i - 1] + f[i - 2]) % mod;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	precalc();
	if (0) stress();
	if (reading()) print(fastsolve());

	return 0;
}