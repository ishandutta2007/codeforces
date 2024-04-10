#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m, k;
int c[505][505], d[505][505];

void mn(int& x, int y) {
	x = min(x, y);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m >> k;
	memset(c, 63, sizeof c);
	memset(d, 63, sizeof d);
	int z = 0;
	for (int i=0; i<n; i++) {
		string s;
		cin >> s;
		vector<int> a;
		for (int j=0; j<m; j++)
			if (s[j] == '1')
				a.push_back(j);
		z += a.size();
		for (int j=0; j<(int)a.size(); j++) {
			for (int k=j; k<(int)a.size(); k++) {
				mn(c[i][a.size() - (k-j+1)], a[k] - a[j] + 1);
			}
		}
		mn(c[i][a.size()], 0);
	}

	d[0][0] = 0;
	for (int i=0; i<n; i++) {
		for (int j=0; j<=k; j++) {
			for (int x=0; x+j<=k; x++) {
				mn(d[i+1][j+x], d[i][j] + c[i][x]);
			}
		}
	}
	cout << d[n][min(k, z)] << '\n';
}