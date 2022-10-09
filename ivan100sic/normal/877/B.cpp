#include <bits/stdc++.h>
using namespace std;

int a[5005], b[5005], n;
string s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> s;
	n = s.size();

	for (int i=0; i<n; i++) {
		a[i+1] += a[i];
		b[i+1] += b[i];
		if (s[i] == 'a') {
			a[i+1]++;
		} else {
			b[i+1]++;
		}
	}


	/*

	for (int i=0; i<=n; i++) {
		cerr << a[i] << ' ' << b[i] << '\n';
	}

	*/

	int sol = 0;

	for (int i=0; i<=n; i++) {
		for (int j=i; j<=n; j++) {
			int bl = b[i];
			int am = a[j] - a[i];
			int br = b[n] - b[j];

			int sve = bl + am + br;

			// cerr << sve << '\n';

			sol = max(sol, n - sve);	
		}
	}

	cout << sol;
}