#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int a, b, c, d, e, f, z = 0;
	cin >> a >> b >> c >> d >> e >> f;
	for (int x=0; x<=100000; x++) {
		if (x > a || x > d)
			break;
		int w = e * x;
		w += min({b, c, d-x}) * f;
		z = max(z, w);
	}
	cout << z << '\n';
}