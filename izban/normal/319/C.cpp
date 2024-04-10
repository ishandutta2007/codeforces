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
const int mod = 1000000007;

int n, a[maxn], b[maxn];

bool reading() {
	if (!(cin >> n)) return 0;
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	for (int i = 0; i < n; i++) scanf("%d", &b[i]);
	return 1;
}

double intersect(pair<int, ll> a1, pair<int, ll> a2) {
	double res = (double)(a2.second - a1.second) / (a1.first - a2.first);
	return res;
}

ll fastsolve() {
	vector<ll> d(n + 1, 1e18);
	vector<double> o;
	vector<pair<int, ll> > v;

	d[0] = 0;
	d[1] = 0;
	v.push_back(make_pair(b[0], d[1]));
	for (int i = 2; i <= n; i++) {
		int j = lower_bound(o.begin(), o.end(), a[i - 1]) - o.begin();
		d[i] = v[j].second + 1LL * v[j].first * a[i - 1];
		
		pair<int, ll> l = make_pair(b[i - 1], d[i]);
		while (v.size() > 1 && intersect(l, v.back()) <= o.back()) {
			v.pop_back();
			o.pop_back();
		}
		o.push_back(intersect(l, v.back()));
		v.push_back(l);
	}
	return d[n];
}

ll slowsolve() {
	vector<ll> d(n + 1, 1e18);
	d[0] = 0;
	d[1] = 0;
	for (int i = 1; i < n; i++) {
		for (int j = i; j < n; j++) {
			d[j + 1] = min(d[j + 1], d[i] + 1LL * a[j] * b[i - 1]);
		}
	}
	return d[n];
}

void gen() {
	n = rand() % 50 + 1;
	a[0] = 1;
	for (int i = 1; i < n; i++) a[i] = a[i - 1] + rand() % 10 + 1;
	b[n - 1] = 0;
	for (int i = n - 2; i >= 0; i--) b[i] = b[i + 1] + rand() % 10 + 1;
}

void stress() {
	for (int it = 0; it < 10000; it++) {
		gen();
		int ans1 = fastsolve();
		int ans2 = slowsolve();
		if (ans1 != ans2) {
			cout << n << endl;
			for (int i = 0; i < n; i++) cout << a[i] << " \n"[i + 1 == n];
			for (int i = 0; i < n; i++) cout << b[i] << " \n"[i + 1 == n];
			cout << ans1 << " instead of " << ans2 << endl;
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

	while (reading()) cout << fastsolve() << endl;

	return 0;
}