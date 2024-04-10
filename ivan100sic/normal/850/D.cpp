#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int HX = 66;
const int HY = HX*HX/2;

int m;
int a[35];
int dp[35][HX][HY];
bool fl[35][HX][HY];

bool dobar(int j, int k) {
	return k >= j*(j-1)/2;
}

bool mat[HY][HY];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> m;
	for (int i=0; i<m; i++)
		cin >> a[i];
	sort(a, a+m);
	
	memset(dp, 0xff, sizeof dp);
	dp[0][0][0] = -2;
	for (int i=0; i<=m; i++) {
		for (int j=0; j<HX; j++) {
			for (int k=0; k<HY; k++) {
				if (dp[i][j][k] == -1)
					continue;
				// mozemo da nastavimo da sibamo a[i-1]
				// ili da predjemo na a[i] ako moze
				if (i) {
					if (dobar(j+1, k+a[i-1])) {
						dp[i][j+1][k+a[i-1]] = a[i-1];
						fl[i][j+1][k+a[i-1]] = false;
					}
				}

				if (i < m) {
					if (dobar(j+1, k+a[i])) {
						dp[i+1][j+1][k+a[i]] = a[i];
						fl[i+1][j+1][k+a[i]] = true;
					}
				}
			}
		}
	}

	vector<int> path;

	for (int j=0; j<HX; j++) {
		if (dp[m][j][j*(j-1)/2] != -1) {
			cerr << "OK " << j << '\n';
			int x = m, y = j, z = j*(j-1)/2;
			while (1) {
				int t = dp[x][y][z];
				if (t == -2)
					break;
				int x2, y2, z2;
				x2 = x - fl[x][y][z];
				y2 = y - 1;
				z2 = z - t;
				x = x2, y = y2, z = z2;
				path.push_back(t);
			}
			break;
		}
	}

	if (path.empty()) {
		// nece da se desi ali ok
		cout << "=(\n";
		return 0;
	}

	int n = path.size();
	for (int x : path)
		cerr << x << ' ';
	cerr << '\n';

	vector<pair<int, int>> b;
	for (int i=0; i<n; i++)
		b.emplace_back(path[i], i);

	for (int i=0; i<n; i++) {
		sort(b.begin()+i, b.end(), greater<pair<int, int>>());
		// izgubi od ovih sa pocetka, pobedi ove na kraju
		auto [z, x] = b[i];
		for (int j=n-z; j<n; j++) {
			int y = b[j].second;
			mat[x][y] = 1;
		}

		for (int j=i+1; j<n-z; j++) {
			int y = b[j].second;
			mat[y][x] = 1;
			b[j].first--;
		}
	}

	cout << n << '\n';
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++)
			cout << mat[i][j];
		cout << '\n';
	}
}