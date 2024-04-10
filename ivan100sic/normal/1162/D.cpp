#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m;
int u[200005], v[200005];

vector<pair<int, int>> rot(int x) {
	vector<pair<int, int>> z(m);
	for (int i=0; i<m; i++) {
		int p = (u[i] + x) % n;
		int q = (v[i] + x) % n;
		if (p > q)
			swap(p, q);
		z[i] = {p, q};
	}
	sort(z.begin(), z.end());
	return z;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=0; i<m; i++) {
		cin >> u[i] >> v[i];
	}
	auto baza = rot(0);
	for (int i=1; i<n; i++) {
		if (n % i == 0) {
			auto tmp = rot(i);
			if (baza == tmp) {
				cout << "Yes\n";
				return 0;
			}
		}
	}
	cout << "No\n";
}