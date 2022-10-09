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

	int t;
	cin >> t;
	while (t--) {
		int b, p, f, h, c, z = 0;
		cin >> b >> p >> f >> h >> c;
		for (int i=0; i<=min(b/2, p); i++) {
			int j = min((b-2*i)/2, f);
			z = max(z, h*i + c*j);
		}
		cout << z << '\n';
	}
}