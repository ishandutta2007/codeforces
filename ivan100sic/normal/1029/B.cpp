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
	int y = 0, z = 0, c = 1;
	while (n--) {
		int x;
		cin >> x;
		if (x <= 2*y)
			c++;
		else
			c = 1;
		y = x;
		z = max(z, c);
	}

	cout << z;


}