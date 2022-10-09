#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int val[4] = {0, 3, 1, 2};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int x;
	cin >> x;
	int tc = -1, yy = -1;
	for (int y=0; y<=2; y++) {
		int z = (x+y)%4;
		if (val[z] > tc) {
			tc = val[z];
			yy = y;
		}
	}
	cout << yy << ' ' << char('A'+3-tc) << '\n';
}