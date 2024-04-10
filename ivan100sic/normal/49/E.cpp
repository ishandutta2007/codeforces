// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

string a, b;
vector<int> u[2];
int n, m, k;
int duz[2];
vector<tuple<int, int, int>> r3;
bool moze[2][55][55][26];

int duo[55][55];

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cin >> a >> b;
	n = a.size();
	m = b.size();
	duz[0] = n;
	duz[1] = m;
	for (char& c : a) u[0].push_back(c - 'a');
	for (char& c : b) u[1].push_back(c - 'a');
	cin >> k;
	for (int i=0; i<k; i++) {
		string t;
		cin >> t;
		int x = t[0] - 'a';
		int y = t[3] - 'a';
		int z = t[4] - 'a';
		r3.emplace_back(x, y, z);
	}

	for (int id=0; id<2; id++) {
		auto& dp = moze[id];
		int l = duz[id];
		for (int i=l-1; i>=0; i--) {
			dp[i][i+1][u[id][i]] = 1;
			for (int j=i+1; j<=l; j++) {
				for (int w=i+1; w<j; w++) {
					for (auto [x, y, z] : r3) {
						if (dp[i][w][y] && dp[w][j][z]) {
							dp[i][j][x] = 1;
						}
					}
				}
			}
		}
	}

	memset(duo, 63, sizeof duo);
	duo[0][0] = 0;
	for (int i=0; i<=n; i++) {
		for (int j=0; j<=m; j++) {
			for (int k=0; k<i; k++) {
				for (int l=0; l<j; l++) {
					for (int c=0; c<26; c++) {
						if (moze[0][k][i][c] && moze[1][l][j][c]) {
							duo[i][j] = min(duo[i][j], duo[k][l] + 1);
						}
					}
				}
			}
		}
	}

	int z = duo[n][m];
	if (z > 123123) z = -1;
	cout << z << '\n';
}