#include <bits/stdc++.h>
using namespace std;

int n, m;
string s;

//    a  p  i
int t[2][2][100005];
int u[100005];

struct segm {
	int l, r, cena;
};

long long b[100005], pmb[100005], c[100005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> s >> m;
	s = string(" ") + s;

	for (int i=1; i<=n; i++) {
		if (s[i] != '?') {
			t[s[i] - 'a'][i % 2][i]++;
		} else {
			u[i]++;
		}

		t[0][0][i] += t[0][0][i-1];
		t[0][1][i] += t[0][1][i-1];
		t[1][0][i] += t[1][0][i-1];
		t[1][1][i] += t[1][1][i-1];
		u[i] += u[i-1];
	}

	// nadji segmente i njihove cene
	for (int i=1; i+m-1 <= n; i++) {
		int l = i-1;
		int r = i+m-1;

		int cena = 0, upit = 0;
		cena += t[1][i%2][r] - t[1][i%2][l];
		cena += t[0][1-i%2][r] - t[0][1-i%2][l];

		upit = u[r] - u[l];

		if (cena == 0) {
			b[r] = 1000000 - upit;
		}
	}

	for (int i=m; i<=n; i++) {
		c[i] = max(c[i-1], b[i] + pmb[i-m]);
		pmb[i] = max(c[i], pmb[i-1]);
	}

	long long sol = pmb[n];

	cerr << sol << '\n';

	cout << (1000000 - sol % 1000000) % 1000000;
}