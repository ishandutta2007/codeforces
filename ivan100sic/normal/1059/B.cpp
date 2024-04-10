#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m;
string a[1005], b[1005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=0; i<n; i++) {
		cin >> a[i];
		b[i] = string(m, '.');
	}
	for (int i=1; i<n-1; i++)
		for (int j=1; j<m-1; j++) {
			bool belo = false;
			belo |= a[i-1][j] == '.';
			belo |= a[i+1][j] == '.';
			belo |= a[i-1][j-1] == '.';
			belo |= a[i][j-1] == '.';
			belo |= a[i+1][j-1] == '.';
			belo |= a[i-1][j+1] == '.';
			belo |= a[i][j+1] == '.';
			belo |= a[i+1][j+1] == '.';

			if (!belo) {
				// pisi
				b[i-1][j]   = '#';
				b[i+1][j]   = '#';
				b[i-1][j-1] = '#';
				b[i][j-1]   = '#';
				b[i+1][j-1] = '#';
				b[i-1][j+1] = '#';
				b[i][j+1]   = '#';
				b[i+1][j+1] = '#';
			}
		}
	for (int i=0; i<n; i++)
		if (a[i] != b[i]) {
			cout << "NO\n";
			return 0;
		}
	cout << "YES\n";
}