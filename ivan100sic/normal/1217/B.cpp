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
		int n, x;
		cin >> n >> x;
		int bestdiff = 0, besthit = 0;
		while (n--) {
			int a, b;
			cin >> a >> b;
			besthit = max(besthit, a);
			bestdiff = min(bestdiff, b-a);
		}
		int z;
		if (x <= besthit)
			z = 1;
		else if (bestdiff >= 0)
			z = -1;
		else
			z = 1 + (x - besthit - bestdiff - 1) / -bestdiff;
		cout << z << '\n'; 
	}
}