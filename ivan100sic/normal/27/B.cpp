#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int v[55][55];
int b[55];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n*(n-1)/2-1; i++) {
		int x, y;
		cin >> x >> y;
		v[x][y] = 1;
		v[y][x] = 1;
		b[x]++;
	}

	for (int i=1; i<=n; i++) {
		for (int j=i+1; j<=n; j++) {
			if (!v[i][j]) {
				if (b[i] > b[j])
					cout << i << ' ' << j << '\n';
				else
					cout << j << ' ' << i << '\n';
				return 0;
			}
		}
	}
}