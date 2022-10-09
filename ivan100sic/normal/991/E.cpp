#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

string s;
int c0[10];
int c[10], n;

ll binom[21][21];

ll sol;

ll cist_multi() {
	ll f = binom[c[0]][c[1]], z = c[0] + c[1];
	for (int i=2; i<10; i++) {
		f *= binom[z][c[i]];
		z += c[i];
	}
	return f;
}

ll multi() {
	ll z = cist_multi();
	if (c[0] > 0) {
		c[0]--;
		z -= cist_multi();
		c[0]++;
	}
	return z;
}

void rek(int d) {
	if (d == 10) {
		sol += multi();
		return;
	}

	if (c0[d] > 0)
		for (int x=1; x<=c0[d]; x++) {
			c[d] = x;
			rek(d+1);
		}
	else
		rek(d+1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> s;
	n = s.size();

	for (char x : s)
		c0[x-'0']++;

	binom[0][0] = 1;
	for (int i=1; i<=20; i++)
		binom[0][i] = binom[i][0] = 1;

	for (int i=1; i<=20; i++)
		for (int j=1; j<=20; j++)
			binom[i][j] = binom[i-1][j] + binom[i][j-1];

	rek(0);
	cout << sol << '\n';
}