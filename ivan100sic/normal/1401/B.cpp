// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int t;
	cin >> t;
	while (t--) {
		int a, b, c, x, y, z;
		cin >> a >> b >> c >> x >> y >> z;

		int p = min(c, y);
		int s = a+b+c;
		int q = max(0, b+z-(s-p));

		cout << 2*(p-q) << '\n';
	}
}