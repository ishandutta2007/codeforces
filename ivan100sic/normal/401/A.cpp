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

	int n, x, s=0;
	cin >> n >> x;
	while (n--) {
		int y;
		cin >> y;
		s += y;
	}
	cout << (abs(s) + x - 1) / x << '\n';
}