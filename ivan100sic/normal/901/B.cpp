#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	vector<int> p(200, 0), q(200, 0);
	p[0] = 1;

	for (int i=1; i<=n; i++) {
		auto v = p;
		auto u = q;
		for (int i=1; i<200; i++) {
			u[i] = (u[i] + p[i-1]) % 2;
		}
		p = u;
		q = v;
	}

	cout << n << '\n';
	for (int i=0; i<=n; i++) {
		cout << p[i] << ' ';
	}
	cout << '\n';
	cout << n-1 << '\n';
	for (int i=0; i<n; i++) {
		cout << q[i] << ' ';
	}
	cout << '\n';
}