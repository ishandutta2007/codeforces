#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m;
string s[2005];
int z[2005][2005], c;

void st(int i, int j) {
	if (s[i][j] == '.')
		s[i][j] = '+';
}

int sm(int x, int y, int q) {
	return z[x][y] + z[x+q][y+q] - z[x][y+q] - z[x+q][y];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=0; i<n; i++) {
		cin >> s[i];
		for (int j=0; j<m; j++) 
			z[i+1][j+1] += s[i][j] == 'w';
	}

	for (int i=0; i<=n; i++)
		for (int j=0; j<=m; j++)
			z[i+1][j] += z[i][j];

	for (int i=0; i<=n; i++)
		for (int j=0; j<=m; j++)
			z[i][j+1] += z[i][j];

	int c = z[n][m];

	if (c == 1) {
		for (int i=0; i<n; i++) {
			cout << s[i] << "\n";
		}
		return 0;
	}

	int x = 123123, y = 123123;
	int x4 = -1, y4 = -1;
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			if (s[i][j] == 'w') {
				x4 = max(x4, i);
				y4 = max(y4, j);
				x = min(x, i);
				y = min(y, j);
			}
		}
	}

	int xx = -1, yy = -1, w = 123123123;

	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			if (i != x && j != y)
				continue;
			for (int q=2; q<=min(m-j, n-i); q++) {
				if (sm(i, j, q) - sm(i+1, j+1, q-2) == c) {
					if (q < w) {
						w = q;
						xx = i;
						yy = j;
					}
				}
			}
		}
	}

	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			if (i != x4 && j != y4)
				continue;
			for (int q=2; q<=min(i, j)+1; q++) {
				if (sm(i-q+1, j-q+1, q) - sm(i-q+2, j-q+2, q-2) == c) {
					if (q < w) {
						w = q;
						xx = i-q+1;
						yy = j-q+1;
					}
				}
			}
		}
	}
		

	if (w == 123123123) {
		cout << "-1\n";
		return 0;
	}

	cerr << "sol = " << xx << ' ' << yy << ' ' << w << '\n';

	for (int i=0; i<w; i++) {
		st(xx+i, yy);
		st(xx, yy+i);
		st(xx+i, yy+w-1);
		st(xx+w-1, yy+i);
	}

	for (int i=0; i<n; i++)
		cout << s[i] << '\n';
}