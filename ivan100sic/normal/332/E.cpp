#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

string s, p, sol;
int k, n, m;
string cols[2005], part[2005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	getline(cin, s);
	getline(cin, p);
	cin >> k;
	n = s.size();
	m = p.size();
	for (int i=0; i<n; i++) {
		cols[i % k] += s[i];
	}

	// for (int i=0; i<k; i++)
	// 	cerr << "col " << cols[i] << '\n';

	sol = "x";
	for (int y=0; y<=n-n%k; y++) {
		int x = (m - y*(n/k)) / (n/k+1);

		// cerr << "maybe " << x << ' ' << y << '\n';

		if ((m - y*(n/k)) % (n/k+1) || x < 0 || x > n%k)
			continue;

		// cerr << "trying " << x << ' ' << y << '\n';
		
		fill(part, part+x+y, "");
		for (int i=0; i<m; i++) {
			part[i % (x+y)] += p[i];
		}

		// for (int i=0; i<x+y; i++)
			// cerr << "part " << part[i] << '\n';

		string curr(k, '0');
		int j = x+y-1;

		for (int i=k-1; i>=0 && j >= 0; i--) {
			if (part[j] == cols[i]) {
				curr[i]++;
				j--;
			}
		}

		if (j == -1) {
			sol = min(sol, curr);
		}
	}

	if (sol == "x")
		sol = "0";
	cout << sol << '\n';
}