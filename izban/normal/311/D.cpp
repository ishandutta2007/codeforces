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

const int maxn = 1 << 17;
const int inf = 1000000007;
const int mod = 95542721;
const int lol = 48;

struct magic {
	int d, sum[lol];
};

int n, m;
int a[maxn], q[maxn], l[maxn], r[maxn];
vector<magic> t;

void reading() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i], a[i] %= mod;
	cin >> m;
	for (int i = 0; i < m; i++) cin >> q[i] >> l[i] >> r[i];
}

magic merge(const magic &a, const magic &b) {
	magic res;
	res.d = 0;
	for (int i = 0; i < lol; i++) {
		res.sum[i] = a.sum[i] + b.sum[i];
		if (res.sum[i] >= mod) res.sum[i] -= mod;
	}
	return res;
}

void push(int v, int tl, int tr) {
	if (t[v].d % lol) {
		magic a = t[v];
		for (int i = 0; i < lol; i++) t[v].sum[i] = a.sum[(i + t[v].d) % lol];
		if (tl != tr) {
			t[v * 2].d += t[v].d;
			t[v * 2 + 1].d += t[v].d;
		}
	}
	t[v].d = 0;
}

void build(int v, int tl, int tr) {
	if (tl == tr) {
		t[v].sum[0] = a[tl];
		for (int i = 1; i < lol; i++) t[v].sum[i] = 1LL * t[v].sum[i - 1] * t[v].sum[i - 1] % mod * t[v].sum[i - 1] % mod;
		return;
	}
	int tm = (tl + tr) >> 1;
	build(v * 2, tl, tm);
	build(v * 2 + 1, tm + 1, tr);
	t[v] = merge(t[v * 2], t[v * 2 + 1]);
}

int get(int v, int tl, int tr, int l, int r) {
	push(v, tl, tr);
	if (l > r) return 0;
	if (l == tl && r == tr) return t[v].sum[0];
	int tm = (tl + tr) >> 1;
	int res = 0;
	res += get(v * 2, tl, tm, l, min(r, tm));
	res += get(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
	if (res >= mod) res -= mod;
	t[v] = merge(t[v * 2], t[v * 2 + 1]);
	return res;
}

void upd(int v, int tl, int tr, int l, int r) {
	push(v, tl, tr);
	if (l > r) return;
	if (l == tl && r == tr) {
		t[v].d += 1;
		push(v, tl, tr);
		return;
	}
	int tm = (tl + tr) >> 1;
	upd(v * 2, tl, tm, l, min(r, tm));
	upd(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
	t[v] = merge(t[v * 2], t[v * 2 + 1]);
}

vector<int> fastsolve() {
	vector<int> ans;
	t.clear();
	//t.resize(2 * maxn);
	t.resize(4 * n);
	build(1, 0, n - 1);
	for (int i = 0; i < m; i++) {
		if (q[i] == 1) {
			ans.push_back(get(1, 0, n - 1, l[i] - 1, r[i] - 1));
		} 
		if (q[i] == 2) {
			upd(1, 0, n - 1, l[i] - 1, r[i] - 1);
		}
	}
	return ans;
}

void write(vector<int> v) {
	for (int i = 0; i < v.size(); i++) cout << v[i] << endl;
}

vector<int> slowsolve() {
	vector<int> ans, b(n);
	for (int i = 0; i < n; i++) b[i] = a[i];
	for (int i = 0; i < m; i++) {
		if (q[i] == 1) {
			int cur = 0;
			for (int j = l[i] - 1; j < r[i]; j++) cur = (cur + b[j]) % mod;
			ans.push_back(cur);
		}
		if (q[i] == 2) {
			for (int j = l[i] - 1; j < r[i]; j++) b[j] = 1LL * b[j] * b[j] % mod * b[j] % mod;
		}
	}
	return ans;
}

void gen() {
	n = rand() % 10 + 1;
	for (int i = 0; i < n; i++) a[i] = rand() % 1000000000 + 1;
	m = rand() % 10 + 1;
	for (int i = 0; i < m; i++) {
		q[i] = rand() % 2 + 1;
		l[i] = rand() % n + 1;
		r[i] = rand() % n + 1;
		if (l[i] > r[i]) swap(l[i], r[i]);
	}
}

void stress() {
	for (int it = 0; it < 10000; it++) {
		gen();
		vector<int> v1 = fastsolve();
		vector<int> v2 = slowsolve();
		if (v1 != v2) {
			cout << n << endl;
			for (int i = 0; i < n; i++) cout << a[i] << " \n"[i + 1 == n];
			write(v1);
			write(v2);
			cout << it << endl;
			break;
		}
		cerr << it << endl;
	}
	exit(0);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    
	if (0) stress();

	reading();
	write(fastsolve());
	/*int n = 7*7*7, i = 1;
	while (n != 7) {
		n = 1LL * n * n % mod * n % mod;
		i++;
	}
	cout << i << endl;*/
	/*int n = 8, a[8] = {0};
	for (int i = 0; i < n; i++) a[i] = i;

	for (int it = 0; it < lol; it++) {
		for (int i = 0; i < n; i++) cout << a[i] << " \n"[i == n - 1];
		for (int i = 0; i < n; i++) a[i] = 1LL * a[i] * a[i] % mod * a[i] % mod;
	}*/

	return 0;
}