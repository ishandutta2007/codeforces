#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m;
string s[505];
bool f[8][505][505][16];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=0; i<n; i++)
		cin >> s[i];

	for (int i=0; i+1<n; i++) {
		for (int j=0; j+1<m; j++) {
			int k = 0;
			k += int(s[i][j] == '*') << 0;
			k += int(s[i+1][j] == '*') << 1;
			k += int(s[i][j+1] == '*') << 2;
			k += int(s[i+1][j+1] == '*') << 3;
			f[0][i][j][k] = true;
		}
	}

	int sol = 0;

	for (int k=1; k<8; k++) {
		int h = 1 << k;
		int w = 2*h;
		for (int i=0; i+w<=n; i++) {
			for (int j=0; j+w<=m; j++) {
				bool smth = false;
				for (int mask=0; mask<16; mask++) {
					bool ok = true;

					if (mask & 1)
						ok &= f[k-1][i][j][15];
					else
						ok &= f[k-1][i][j][mask];

					if (mask & 2)
						ok &= f[k-1][i+h][j][15];
					else
						ok &= f[k-1][i+h][j][mask];

					if (mask & 4)
						ok &= f[k-1][i][j+h][15];
					else
						ok &= f[k-1][i][j+h][mask];

					if (mask & 8)
						ok &= f[k-1][i+h][j+h][15];
					else
						ok &= f[k-1][i+h][j+h][mask];

					f[k][i][j][mask] = ok;
					smth |= ok;
				}

				if (smth)
					sol++;
			}
		}
	}

	cout << sol << '\n';
}

/*
10 10
*.........
.*........
...**.....
..........
..*.....*.
.*.....*..
....*.*.*.
*.......*.
***...*...
..........
*/