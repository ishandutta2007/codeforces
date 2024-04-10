// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int cost(char x, char y) {
	if (x <= y)
		return y-x;
	return 123123123;
}

int d[27][100005];
int p[27][100005];

void mn(int& x, int y) {
	x = min(x, y);
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	string s;
	cin >> s;

	int n = s.size();

	memset(d, 63, sizeof d);
	d[0][0] = 0;

	int l = 0;
	for (char c : s) {
		for (int i=0; i<26; i++) {
			int u = d[i][l] + cost(c, 'a' + i);
			if (u < d[i+1][l+1]) {
				d[i+1][l+1] = u;
				p[i+1][l+1] = 1;
			}

			u = d[i][l];
			if (u < d[i][l+1]) {
				d[i][l+1] = u;
				p[i][l+1] = 0;
			}
		}
		l++;
	}

	if (d[26][n] > 123123122) {
		cout << "-1\n";
		return 0;
	}

	string s2 = s;
	for (int i=n, j=26; i>0; i--) {
		if (p[j][i]) {
			j--;
			s2[i-1] = 'a' + j;
		}
	}

	cout << s2 << '\n';
}