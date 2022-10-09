#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

// KRAJ TEMPLATE KODA

int c[6];
int n;
bool ok[100005][6];

int hall[64], rem[64];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	string s;
	cin >> s;
	for (char x : s)
		c[x-'a']++;

	n = s.size();
	for (int i=0; i<n; i++)
		fill(ok[i], ok[i]+6, true);

	int q;
	cin >> q;
	while (q--) {
		int x;
		cin >> x;
		x--;
		string s;
		cin >> s;
		fill(ok[x], ok[x]+6, false);
		for (char y : s)
			ok[x][y-'a'] = true;
	}

	for (int mask=0; mask<64; mask++) {
		for (int j=0; j<n; j++) {
			bool k = 0;
			for (int i=0; i<6; i++)
				if (mask & (1 << i))
					if (ok[j][i]) {
						k = 1;
						break;
					}
			if (k)
				hall[mask]++;
		}

		rem[mask] = 0;
		for (int i=0; i<6; i++)
			if (mask & (1 << i))
				rem[mask] += c[i];
	}

	string p;

	for (int i=0; i<n; i++) {
		bool k = 0;
		int grane = 0;
		for (int j=0; j<6; j++)
			if (ok[i][j])
				grane += 1 << j;

		for (int t=1; t<64; t++) {
			if (t & grane)
				hall[t]--;
		}

		for (int j=0; j<6; j++) {
			if (!ok[i][j])
				continue;
			// probaj da stavis j
			// proveri hall

			bool mucak = 0;
			for (int mask=1; mask<64; mask++) {
				if (mask & (1 << j)) {
					rem[mask]--;
				}
				if (hall[mask] < rem[mask])
					mucak = 1;
			}

			if (mucak) {
				for (int t=1; t<64; t++)
					if (t & (1 << j))
						rem[t]++;
			} else {
				k = true;
				p += (char)(j + 'a');
				break;
			}
		}
		if (!k) {
			cout << "Impossible\n";
			return 0;
		}
	}

	cout << p << '\n';
}