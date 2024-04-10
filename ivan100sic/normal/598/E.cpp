// I've decided to retire from ALL contests
// It's been a nice ride... but I need to move on
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int g[55][55][55];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	memset(g, 63, sizeof g);
	for (int a=1; a<=50; a++) {
		for (int b=1; b<=50; b++) {
			for (int c=0; c<=50; c++) {
				int& v = g[a][b][c];
				if (c == a*b || c == 0)
					v = 0;

				for (int x=1; x<a; x++) {
					for (int d=0; d<=c; d++) {
						v = min(v, g[x][b][d] + g[a-x][b][c-d] + b*b);
					}
				}

				for (int y=1; y<b; y++) {
					for (int d=0; d<=c; d++) {
						v = min(v, g[a][y][d] + g[a][b-y][c-d] + a*a);
					}
				}
			}
		}
	}

	int t;
	cin >> t;
	while (t--) {
		int a, b, c;
		cin >> a >> b >> c;
		cout << g[a][b][c] << '\n';
	}
}

// I will still practice daily...