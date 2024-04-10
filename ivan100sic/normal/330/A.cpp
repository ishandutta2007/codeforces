#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n, m;
	cin >> n >> m;
	vector<string> a(n);
	for (auto& s : a)
		cin >> s;

	vector<int> r(n, 0), c(m, 0);
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			if (a[i][j] == 'S')
				r[i] = c[j] = 1;
		}
	}
	int z = 0;
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			if (r[i] + c[j] < 2)
				z++;
		}
	}
	cout << z << '\n';
}