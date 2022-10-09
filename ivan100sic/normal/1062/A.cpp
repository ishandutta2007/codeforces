#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int c[1005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n;
	cin >> n;
	while (n--) {
		int x;
		cin >> x;
		c[x] = 1;
	}

	c[0] = 1;
	c[1001] = 1;
	int x = 0, y = 0;
	for (int i=0; i<=1001; i++) {
		x++;
		if (!c[i]) x = 0;
		y = max(y, x - 2);
	}
	cout << y << '\n';
}