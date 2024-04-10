#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
string s;
int dp[77][77][77][2];

int check(int v, int k, int x, char c) {
	string p = s;
	for (int i=0; i<n; i++) {
		if (p[i] == 'v' && v)
			p[i] = 0, v--;
		else if (p[i] == 'k' && k)
			p[i] = 0, k--;
		else if (p[i] == 'x' && x)
			p[i] = 0, x--;
	}
	for (int i=0, t=0; i<n; i++)
		if (p[i] == c)
			return t;
		else if (p[i])
			t++;
	return 123123;
}

void mn(int& x, int y) {
	x = min(x, y);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> s;
	for (char& c : s) {
		if (c == 'V')
			c = 'v';
		else if (c == 'K')
			c = 'k';
		else
			c = 'x';
	}

	memset(dp, 63, sizeof dp);
	dp[0][0][0][0] = 0;
	for (int v=0; v<n; v++) {
		for (int k=0; k<n; k++) {
			for (int x=0; x<n; x++) {
				for (int t=0; t<2; t++) {
					int ol = dp[v][k][x][t];
					// stavi v
					mn(dp[v+1][k][x][1], ol + check(v, k, x, 'v'));
					// stavi k
					if (t == 0)
						mn(dp[v][k+1][x][0], ol + check(v, k, x, 'k'));
					mn(dp[v][k][x+1][0], ol + check(v, k, x, 'x'));
				}
			}
		}
	}

	{
		int v = count(s.begin(), s.end(), 'v');
		int k = count(s.begin(), s.end(), 'k');
		int x = count(s.begin(), s.end(), 'x');
		cout << min(dp[v][k][x][0], dp[v][k][x][1]) << '\n';
	}
}