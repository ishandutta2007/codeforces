/*

###
#X.
#.X

111
110
101

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
using namespace std;

int n, m;
int a[2005][2005];
bitset<2000> b[2000];
bitset<2000> c[2000];
int u[500005], v[500005];

template<class T>
void dbg(T x) {
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			cout << (int)x[i][j];
		}
		cout << '\n';
	}
	cout << '\n';
}

int main() {	
	cin >> n >> m;
	for (int i=0; i<m; i++) {
		cin >> u[i] >> v[i];
		a[u[i]][v[i]] = 1;
		b[u[i]-1][v[i]-1] = 1;
	}

	for (int i=0; i<n; i++) {
		c[i][i] = 1;
	}

	// dbg(b);

	for (int i=0; i<n; i++) {
		for (int j=i; j<n; j++) {
			if (b[j][i] == 1) {
				swap(b[i], b[j]);
				swap(c[i], c[j]);
				break;
			}
		}
		for (int j=i+1; j<n; j++) {
			if (b[j][i]) {
				b[j] ^= b[i];
				c[j] ^= c[i];
			}
		}
	}

	for (int i=n-1; i>0; i--) {
		for (int j=i-1; j>=0; j--) {
			if (b[j][i]) {
				b[j] ^= b[i];
				c[j] ^= c[i];
			}
		}
	}

	for (int i=0; i<m; i++) {
		int x = u[i] - 1, y = v[i] - 1;
		if (c[y][x]) {
			cout << "NO\n";
		} else {
			cout << "YES\n";
		}
	}

	// dbg(c);
	// dbg(b);
}