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

	int t;
	cin >> t;
	while (t--) {
		int n, f = 0;
		cin >> n;
		vector<int> a(2*n);
		for (int& x : a) {
			cin >> x;
			x = 2*x - 3;
			f += x;
		}
		if (f == 0) {
			cout << "0\n";
			continue;			
		}
		map<int, int> seen;
		seen[0] = 0;
		for (int i=n, z=0; i<2*n; i++) {
			z += a[i];
			if (!seen.count(z))
				seen[z] = i+1-n;
		}

		int sol = 2*n, z=0;
		if (seen.count(f)) {
			sol = seen[f];
		}

		for (int i=n-1; i>=0; i--) {
			z += a[i];
			if (seen.count(f - z))
				sol = min(sol, n-i + seen[f - z]);
		}
		cout << sol << '\n';
	}
}