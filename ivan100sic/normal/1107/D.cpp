#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
bool a[5205][5205];
int z[5205][5205];

inline bool pure(int z, int d) {
	return z == d*d || z == 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++) {
		string s;
		cin >> s;
		for (int j=0; j<n; j+=4) {
			char x = s[j >> 2];
			int y;
			if (isdigit(x))
				y = x - '0';
			else
				y = x - 'A' + 10;
			for (int k=0; k<4; k++)
				a[i][j+k] = (y >> (3-k)) & 1;
		}
	}

	for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++)
			z[i][j] = a[i-1][j-1];

	for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++)
			z[i][j] += z[i-1][j];

	for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++)
			z[i][j] += z[i][j-1];

	for (int d=n; d>=1; d--) {
		if (n % d == 0) {
			bool ok = 1;
			for (int i=0; i<n; i+=d)
				for (int j=0; j<n; j+=d) {
					int w = z[i][j] + z[i+d][j+d] - z[i+d][j] - z[i][j+d];
					if (!pure(w, d)) {
						ok = 0;
						break;
					}
				}

				
			if (ok) {
				cout << d << '\n';
				return 0;
			}
		}
	}
}