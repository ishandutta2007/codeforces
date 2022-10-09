// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int f(int x) {
	return (x + 3*x*x) / 2;
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int t;
	cin >> t;
	while (t--) {
		int n, c=0;
		cin >> n;
		while (n > 1) {
			int x = 1;
			while (f(x+1) <= n)
				x++;
			n -= f(x);
			c++;
		}

		cout << c << '\n';
	}
}

// 2 + 5 + 8 + 11
// 2
// 7
// 15