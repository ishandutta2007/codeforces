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

	int n;
	cin >> n;
	string s;
	cin >> s;

	int gc = count(s.begin(), s.end(), 'G');
	int sol = 0;

	// bez?
	int y = 0;
	for (int i=0; i<n; i++) {
		y++;
		if (s[i] == 'S')
			y = 0;
		sol = max(sol, y);
	}

	// sa?
	for (int i=1; i<n; i++) {
		if (s[i] == 'S') {
			int j = i-1;
			while (j >= 0 && s[j] == 'G')
				j--;
			int k = i+1;
			while (k < n && s[k] == 'G')
				k++;

			int gg = k-j-2;

			if (gg == gc)
				sol = max(sol, gg);
			else
				sol = max(sol, gg + 1);
		}
	}

	cout << sol << '\n';

}