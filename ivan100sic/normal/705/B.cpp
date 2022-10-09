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

	int n, y = 2;
	cin >> n;
	while (n--) {
		int x;
		cin >> x;
		if (x % 2 == 0)
			y = 3 - y;
		cout << y << '\n';
	}
}