#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m, k;
string a[105][105];

int daj(int x, int y, int z) {
	if (min({x, y, z}) < 0 || x >= n || y >= m || z >= k)
		return 0;
	return a[x][y][z] == '1';
}

int b1[3][3][3];
int r1[3][3][3];
int b2[3][3][3];
int r2[3][3][3];

template<class T>
void do_reach(T b, T r) {
	for (int i=0; i<3; i++)
	for (int j=0; j<3; j++)
	for (int k=0; k<3; k++)
		r[i][j][k] = b[i][j][k] << (i + 3*j + 9*k);

	for (int i=0; i<3; i++)
	for (int j=0; j<3; j++)
	for (int k=0; k<3; k++)
	{
		if (!r[i][j][k])
			continue;
		if (i < 2 && r[i+1][j][k]) r[i+1][j][k] |= r[i][j][k];
		if (j < 2 && r[i][j+1][k]) r[i][j+1][k] |= r[i][j][k];
		if (k < 2 && r[i][j][k+1]) r[i][j][k+1] |= r[i][j][k];
	}
}

int check(int x, int y, int z) {
	if (daj(x, y, z) == 0)
		return 0;
	for (int i=x-1; i<=x+1; i++)
	for (int j=y-1; j<=y+1; j++)
	for (int k=z-1; k<=z+1; k++)
		b1[i-x+1][j-y+1][k-z+1] = daj(i, j, k);

	memcpy(b2, b1, sizeof b1);
	b2[1][1][1] = 0;

	do_reach(b1, r1);
	do_reach(b2, r2);

	for (int i=0; i<3; i++)
	for (int j=0; j<3; j++)
	for (int k=0; k<3; k++)
	{
		if (i == 1 && j == 1 && k == 1)
			continue;
		if ((r1[i][j][k] ^ r2[i][j][k]) & 134209535)
			return 1;
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m >> k;
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			cin >> a[i][j];
		}
	}

	int sol = 0;
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			for (int z=0; z<k; z++) {
				sol += check(i, j, z);
			}
		}
	}
	cout << sol << '\n';
}