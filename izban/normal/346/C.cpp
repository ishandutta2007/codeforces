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
#include <cassert>
#include <ctime>


using namespace std;

#define ll long long
#pragma comment(linker, "/STACK:64000000")

const int maxn = 1 << 17;
const int inf = 1000000007;
const int mod = 1000000007;

int n, x[maxn], a, b;

bool reading() {
	if (!(cin >> n)) return 0;
	vector<int> v;
	for (int i = 0; i < n; i++) cin >> x[i], v.push_back(x[i]);
	cin >> a >> b;
	sort(v.begin(), v.end());
	n = 0;
	for (int i = 0; i < v.size(); i++) {
		if (!i || v[i] != v[i - 1]) x[n++] = v[i];
	}
	return 1;
}

int slowsolve() {
	vector<int> d(a - b + 1, inf);
	d[0] = 0;
	for (int i = 1; i <= a - b; i++) {
		d[i] = min(d[i], d[i - 1] + 1);
		for (int j = 0; j < n; j++) {
			if ((b + i) % x[j] <= i) d[i] = min(d[i], d[i - (b + i) % x[j]] + 1);
		}
	}
	return d[a - b];
}

void gen() {
	n = rand() % 100 + 1;
	for (int i = 0; i < n; i++) x[i] = rand() % 1000 + 1;
	b = rand() % 20000;
	a = b + rand() % 2000;
}

int fastsolve() {
	vector<int> mx(a - b + 1, 1), d(a - b + 1, inf);
	for (int i = 0; i < n; i++) {
		int cur = a - b;
		if (a % x[i] > a - b) continue;
		mx[cur] = max(mx[cur], a % x[i]);
		cur = cur - a % x[i] - 1;
		while (cur >= x[i] - 1) {
			mx[cur] = max(mx[cur], x[i] - 1);
			cur -= x[i];
		}
	}
	d[0] = 0;
	for (int i = a - b; i > 0; i--) mx[i - 1] = max(mx[i - 1], mx[i] - 1);
	for (int i = 1; i <= a - b; i++) {
		d[i] = d[i - mx[i]] + 1;
	}
	return d[a - b];
}

void stress(bool f) {
	if (!f) return;
	for (int it = 0; it < 10000; it++) {
		gen();
		int ans1 = fastsolve();
		int ans2 = slowsolve();
		if (ans1 != ans2) {
			cout << ans1 << " instead of " << ans2 << endl;
			cout << n << endl;
			for (int i = 0; i < n; i++) cout << x[i] << " \n"[i + 1 == n];
			cout << a << " " << b << endl;
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

	stress(0);

	while (reading())
		cout << fastsolve() << endl;

	return 0;
}