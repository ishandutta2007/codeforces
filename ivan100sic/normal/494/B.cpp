#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int M = 1000000007;

bool ima[100005];

void find_occ(string a, string b) {
	string s = a + '#' + b;
	int k = s.size();
	basic_string<int> z(k, 0);
	for (int i=1, l=0, r=0; i<k; i++) {
		if (i < r)
			z[i] = min(r-i, z[i-l]);
		while (i+z[i] < k && s[z[i]] == s[i+z[i]])
			z[i]++;
		if (i+z[i] > r) {
			r = i+z[i];
			l = i;
		}
	}

	int n = a.size();
	int m = b.size();

	for (int i=0; i<m; i++) {
		if (z[i+n+1] == n) {
			ima[i] = 1;
		}
	}
}

void ad(int& x, int y) {
	x += y;
	if (x >= M)
		x -= M;
}

int d[100005], dz[100005], dzz[100005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	string a, b;
	cin >> a >> b;
	find_occ(b, a);

	int n = a.size(), occ = -1;
	int m = b.size();
	for (int i=1; i<=n; i++) {
		if (i >= m && ima[i-m])
			occ = i-m;
		if (occ != -1) {
			int w = dzz[occ];
			ad(w, occ+1);
			d[i] = w;
		} else {
			d[i] = 0;
		}
		dz[i] = dz[i-1];
		dzz[i] = dzz[i-1];
		ad(dz[i], d[i]);
		ad(dzz[i], dz[i]);
	}
	int z = 0;
	for (int i=1; i<=n; i++)
		ad(z, d[i]);
	cout << z << '\n';
}