// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

bool ly(int x) {
	if (x % 4 == 0) {
		if (x % 100 == 0) {
			return x % 400 == 0;
		}
		return true;
	}
	return false;
}

pair<int, bool> c[123126];

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int y0 = 172;
	int d0 = 2;

	while (y0 <= 123123) {
		c[y0] = {d0, ly(y0)};
		d0 = (d0 + (ly(y0) ? 2 : 1)) % 7;
		y0++;
	}

	int x;
	cin >> x;
	for (int y=x+1; y<x+123; y++) {
		if (c[y] == c[x]) {
			cout << y << '\n';
			return 0;
		}
	}

}