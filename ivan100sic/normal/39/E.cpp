#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int a, b, n;
int c[50005][33];
int w[50005][33];

string out[3] = {"Missing", "Masha", "Stas"};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> a >> b >> n;

	for (int x=1; x<50005; x++) {
		c[x][1] = min(x, n);
		for (int y=2; y<33; y++) {
			c[x][y] = min(ll(n), c[x][y-1] * ll(x));
		}
	}

	for (int x=50003; x>=2; x--) {
		for (int y=31; y>=1; y--) {
			if (c[x][y] == n) {
				w[x][y] = 1;
			} else {
				if (w[x+1][y] == 2 || w[x][y+1] == 2)
					w[x][y] = 1;
				else
					w[x][y] = 2;
			}
		}
	}

	{
		int x = 1;
		for (int y=31; y>=1; y--) {
			if (w[x+1][y] == 2 || w[x][y+1] == 2)
				w[x][y] = 1;
			else if (w[x][y+1] == 0 || w[x+1][y] == 0)
				w[x][y] = 0;
			else
				w[x][y] = 2;
		}
	}

	cout << out[w[a][b]] << '\n';
}