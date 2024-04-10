#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int w[105], n, a, x, b, y;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> a >> x >> b >> y;
	a--, b--, x--, y--;
	while (a != -1 || b != -1) {
		if (a == b && a != -1) {
			cout << "YES\n";
			return 0;
		}
		
		if (a == x)
			a = -1;
		if (b == y)
			b = -1;

		if (a != -1)
			a = (a+1) % n;
		if (b != -1)
			b = (b+n-1) % n;
	}
	cout << "NO\n";
}