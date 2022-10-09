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

	int x, y, z;
	int p, q, r;
	cin >> p >> q >> r;	
	cin >> x >> y >> z;
	int a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;

	int w = 0;

	if (q < 0)
		w += a;
	else if (q > y)
		w += b;

	if (r < 0)
		w += c;
	else if (r > z)
		w += d;

	if (p < 0)
		w += e;
	else if (p > x)
		w += f;

	cout << w << '\n';
}