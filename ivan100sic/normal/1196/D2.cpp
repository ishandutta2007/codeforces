#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int ord(char x) {
	if (x == 'R')
		return 0;
	else if (x == 'G')
		return 1;
	else if (x == 'B')
		return 2;
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int q;
	cin >> q;
	while (q--) {
		int n, k;
		cin >> n >> k;
		string s;
		cin >> s;
		vector<vector<vector<int>>> z(3, vector(3, vector<int>(n+1, 0)));
		for (int i=0; i<n; i++)
			z[ord(s[i])][i%3][i+1] = 1;
		for (int i=0; i<3; i++)
			for (int k=0; k<3; k++)
				for (int j=1; j<=n; j++)
					z[i][k][j] += z[i][k][j-1];
		int sol = k;
		for (int l=0; l+k<=n; l++) {
			for (int u=0; u<3; u++) {
				int ok = 0;
				for (int v=0; v<3; v++) {
					ok += z[v][(u+v)%3][l+k] - z[v][(u+v)%3][l];
				}
				sol = min(sol, k-ok);
			}
		}
		cout << sol << '\n';
	}
}