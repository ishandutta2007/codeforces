#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

typedef vector<vector<int>> vvi;

string resi(int n, vvi e, vvi f) {
	if (!n) return "";
	string s(n, 0), t(n, 0);
	for (int i=0; i<n; i++) {
		s[i] = 1;
		for (int j : e[i])
			s[i] &= 1-s[j];
		for (int j : f[i])
			s[i] &= 1-s[j];
	}
	for (int i=0; i<n; i++) {
		if (!s[i]) {
			t[i] = 1;
			for (int j : f[i])
				t[i] &= 1-s[j];
		}
	}
	vector<int> r(n);
	int n2 = 0;
	for (int i=0; i<n; i++)
		if (t[i])
			r[i] = n2++;
	vvi e2(n2), f2(n2);
	for (int i=0; i<n; i++) {
		for (int j : e[i]) {
			if (t[i] && t[j]) {
				e2[r[i]].push_back(r[j]);
				f2[r[j]].push_back(r[i]);
			}
		}
	}
	string s2 = resi(n2, e2, f2);
	for (int i=0; i<n; i++) {
		if (t[i] && s2[r[i]]) {
			s[i] = 1;
			for (int j : e[i]) {
				s[j] = 0;
			}
		}
	}
	return s;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n, m;
	cin >> n >> m;
	vvi e(n), f(n);
	while (m--) {
		int x, y;
		cin >> x >> y;
		x--, y--;
		e[x].push_back(y);
		f[y].push_back(x);
	}
	auto s = resi(n, e, f);
	vector<int> sol;
	for (int i=0; i<n; i++)
		if (s[i])
			sol.push_back(i+1);
	cout << sol.size() << '\n';
	for (int x : sol)
		cout << x << ' ';
	cout << '\n';
}