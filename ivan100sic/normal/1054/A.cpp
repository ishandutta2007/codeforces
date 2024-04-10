#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int x, y, z, t1, t2, t3;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> x >> y >> z >> t1 >> t2 >> t3;

	int lift = abs(z-x)*t2 + abs(x-y)*t2 + 3*t3;
	int stepke = abs(x-y) * t1;

	cerr << lift << ' ' << stepke << '\n';

	if (lift <= stepke) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}
}