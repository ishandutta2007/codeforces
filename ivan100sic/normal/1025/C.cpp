#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

vector<int> potez(vector<int> a, int k) {
	reverse(a.begin(), a.begin()+k);
	reverse(a.begin()+k, a.end());
	return a;
}

set<vector<int>> ric;
queue<vector<int>> q;

void test() {
	vector<int> v(7);
	iota(v.begin(), v.end(), 0);
	q.push(v);
	while (!q.empty()) {
		auto v = q.front(); q.pop();
		for (int i=1; i<7; i++) {
			auto u = potez(v, i);
			if (ric.count(u) == 0) {
				ric.insert(u);
				q.push(u);
			}
		}
	}

	for (auto u : ric) {
		for (int x : u)
			cerr << x << ' ';
		cerr << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	test();

	string s;
	cin >> s;
	string p = s + s;
	int n = s.size();

	int sol = 1, niz = 1;

	for (int i=1; i<2*n; i++) {
		if (p[i] != p[i-1])
			niz++;
		else
			niz = 1;

		sol = max(sol, niz);
	}
	cout << min(sol, n) << '\n';
}