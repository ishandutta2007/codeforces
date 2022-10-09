#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int c[4][2], p[4];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<4; i++) {
		for (int j=0; j<n; j++) {
			string s;
			cin >> s;
			for (int k=0; k<n; k++) {
				int t = s[k] == '1';
				c[i][0] += (t ^ j ^ k) & 1;
				c[i][1] += (t ^ j ^ k ^ 1) & 1;
			}
		}
	}

	iota(p, p+4, 0);
	int perms = 24, sol = 123123123;
	while (perms--) {
		sol = min(sol, c[p[0]][0] + c[p[1]][0] + c[p[2]][1] + c[p[3]][1]);
		next_permutation(p, p+4);
	}

	cout << sol << '\n';
}