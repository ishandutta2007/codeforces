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
const int lol = 320;

int n, m, q;
ll a[maxn], k[maxn], K[maxn], x[maxn];
ll sum[maxn];
char c[maxn];
vector<int> s[maxn];
vector<int> sp[maxn];

bool reading() {
	if (!(cin >> n >> m >> q)) return 0;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < m; i++) {
		cin >> K[i];
		for (int j = 0; j < K[i]; j++) {
			int x;
			cin >> x;
			s[i].push_back(x - 1);
		}
		sort(s[i].begin(), s[i].end());
	}
	for (int i = 0; i < q; i++) {
		cin >> c[i];
		if (c[i] == '?') {
			cin >> k[i];
		}
		if (c[i] == '+') {
			cin >> k[i] >> x[i];
		}
		k[i]--;
	}
	return 1;
}

void print(vector<ll> v) {
	for (int i = 0; i < v.size(); i++) cout << v[i] << endl;
}

vector<ll> fastsolve() {
	vector<ll> A(n);
	for (int i = 0; i < n; i++) A[i] = a[i];

	for (int i = 0; i < m; i++) {
		sum[i] = 0;
		for (int j = 0; j < K[i]; j++) sum[i] += a[s[i][j]];
	}
	for (int i = 0; i < n; i++) sp[i].clear();
	vector<ll> ans;
	vector<int> v;
	for (int i = 0; i < m; i++) if (K[i] > lol) v.push_back(i);
	vector<vector<int> > e(v.size(), vector<int>(m, 0));

	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < m; j++) if (1) {
			for (int k = 0; k < K[j]; k++) {
				if (binary_search(s[v[i]].begin(), s[v[i]].end(), s[j][k])) {
					e[i][j]++;
				}
			}
		}
		for (int j = 0; j < K[v[i]]; j++) {
			sp[s[v[i]][j]].push_back(i);
		}
	}

	vector<ll> add(m);
	for (int i = 0; i < q; i++) {
		if (c[i] == '+') {
			if (K[k[i]] > lol) add[k[i]] += x[i];
			else {
				for (int j = 0; j < v.size(); j++) sum[v[j]] += e[j][k[i]] * x[i];
				for (int j = 0; j < K[k[i]]; j++) a[s[k[i]][j]] += x[i];
			}
			//else 
		}
		if (c[i] == '?') {
			ll csum = 0;
			if (K[k[i]] > lol) {
				csum = sum[k[i]];
			} else {
				for (int j = 0; j < K[k[i]]; j++) csum += a[s[k[i]][j]];
			}
			for (int j = 0; j < v.size(); j++) {
				csum += add[v[j]] * e[j][k[i]];
			}
			ans.push_back(csum);
		}
	}
	for (int i = 0; i < n; i++) a[i] = A[i];
	return ans;
}

vector<ll> slowsolve() {
	vector<ll> ans;
	vector<ll> A(n);
	for (int i = 0; i < n; i++) A[i] = a[i];
	for (int i = 0; i < q; i++) {
		ll csum = 0;
		if (c[i] == '+') {
			for (int j = 0; j < K[k[i]]; j++) A[s[k[i]][j]] += x[i];
		}
		if (c[i] == '?') {
			for (int j = 0; j < K[k[i]]; j++) csum += A[s[k[i]][j]];
			ans.push_back(csum);
		}
	}
	return ans;
}

int Rand() {
	return (rand() << 15) + rand();
}

void gen() {
	n = Rand() % 1000 + 1;
	for (int i = 0; i < n; i++) a[i] = Rand() % 1000000 + 1;
	m = Rand() % 1000 + 1;
	int csum = 0;
	for (int i = 0; i < m; i++) {
		s[i].clear();
		vector<int> v;
		for (int j = 0; j < n; j++) if (rand() % 2) v.push_back(j);
		if (v.empty()) {
			i--;
			continue;
		}
		K[i] = v.size();
		for (int j = 0; j < K[i]; j++) s[i].push_back(v[j]);
		csum += K[i];
		if (csum > 10000) {
			m = i + 1;
			break;
		}
	}
	q = Rand() % 1000 + 1;
	for (int i = 0; i < q; i++) {
		c[i] = rand() % 2 ? '+' : '?';
		k[i] = rand() % m;
		if (c[i] == '+') {
			x[i] = rand() % 100000 - 50000;
		}
	}
}

void stress(bool f) {
	if (!f) return;
	for (int it = 0; it < 10000; it++) {
		gen();
		vector<ll> ans1 = fastsolve();
		vector<ll> ans2 = slowsolve();
		if (ans1 != ans2) {
			print(ans1);
			cout << "instead of" << endl;
			print(ans2);
			cout << "----" << endl;
			cout << n << " " << m << " " << q << endl;
			for (int i = 0; i < n; i++) cout << a[i] << " \n"[i + 1 == n];
			for (int i = 0; i < m; i++) {
				cout << K[i] << " ";
				for (int j = 0; j < K[i]; j++) cout << s[i][j] << " \n"[j + 1 == K[i]];
				if (!K[i]) cout << endl;
			}
			for (int i = 0; i < q; i++) cout << c[i] << " " << k[i] << " " << x[i] << endl;
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
	while (reading()) {
		print(fastsolve());
	}

	return 0;
}