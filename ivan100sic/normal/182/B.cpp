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

	int d, n;
	cin >> d >> n;
	int x = 1, y = 0;
	while (n--) {
		int a;
		cin >> a;
		// koliko ce prvog dana da menja?
		if (x != 1)
			y += d+1-x;
		// ostalih dana nece da menja
		x = a + 1;
		if (x == d+1)
			x = 1;
	}
	cout << y << '\n';
}