#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int lo[8];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;

	fill(lo, lo+8, 1123123);
	lo[0] = 0;

	while (n--) {
		int x, m = 0;
		cin >> x;
		string s;
		cin >> s;
		if (count(s.begin(), s.end(), 'A'))
			m += 4;
		if (count(s.begin(), s.end(), 'B'))
			m += 2;
		if (count(s.begin(), s.end(), 'C'))
			m += 1;

		lo[m] = min(lo[m], x);
	}

	int sol = 1123123;

	for (int i=0; i<8; i++)
		for (int j=0; j<8; j++)
			for (int k=0; k<8; k++) {
				if ((i | j | k) == 7) {
					sol = min(sol, lo[i] + lo[j] + lo[k]);
				}
			}

	if (sol == 1123123)
		sol = -1;
	cout << sol << '\n';
}