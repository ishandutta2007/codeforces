// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int t;
	cin >> t;
	while (t--) {
		int x;
		cin >> x;
		int y = 0;
		while (x >= 10) {
			int r = x/10;
			y += r*10;
			x -= r*10;
			x += r;
		}
		cout << y+x << '\n';
	}
}