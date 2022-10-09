#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

typedef vector<double> vd;

vd mnozi(vd a, vd b) {
	vd c(128, 0);
	for (int i=0; i<128; i++)
		for (int j=0; j<128; j++)
			c[i^j] += a[i] * b[j];
	return c;
}

vd pw(vd a, int b) {
	if (b == 1)
		return a;
	auto c = pw(a, b >> 1);
	c = mnozi(c, c);
	if (b & 1)
		c = mnozi(c, a);
	return c;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n, k;
	cin >> n >> k;
	vd a(128);
	for (int i=0; i<=k; i++)
		cin >> a[i];
	a = pw(a, n);
	cout << fixed << setprecision(20) << 1 - a[0] << '\n';
}