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

	int n;
	cin >> n;

	int e = 321321, f = -321321;
	int g = 321321, h = -321321;
	int z = 0;

	for (int i=0; i<n; i++) {
		int a, b, c, d;
		cin >> a >> c >> b >> d;
		e = min(e, a);
		f = max(f, b);
		g = min(g, c);
		h = max(h, d);
		z += (b-a)*(d-c);
	}

	cout << (z == (f-e)*(h-g) && f-e == h-g ? "YES\n" : "NO\n");
}