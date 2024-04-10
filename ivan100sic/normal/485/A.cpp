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

	int a, m;
	cin >> a >> m;
	for (int i=0; i<2*m; i++) {
		a = 2 * a % m;
		if (a == 0) {
			cout << "Yes\n";
			return 0;
		}
	}
	cout << "No\n";
}