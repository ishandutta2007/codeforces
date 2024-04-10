// I've decided to retire from ALL contests
// It's been a nice ride... but I need to move on
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

	int x, y=0;
	cin >> x;
	int p[6] = {0, 5, 3, 2, 4, 1};
	for (int i=0; i<6; i++) {
		int z = (x >> (5 - p[i])) & 1;
		y |= z << (5 - i);
	}
	cout << y << '\n';
}

// I will still practice daily...