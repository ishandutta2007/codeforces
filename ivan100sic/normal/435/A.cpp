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

	int n, m;
	cin >> n >> m;
	int f = 0, z = 0;
	while (n--) {
		int x;
		cin >> x;
		if (f + x > m) {
			z++;
			f = x;
		} else {
			f += x;
		}
	}
	cout << z+1 << '\n';
}