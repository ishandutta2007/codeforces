#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

ll rd() {
	int x, b;
	cin >> x >> b;
	ll z = 0;
	while (x--) {
		int y;
		cin >> y;
		z = b*z + y;
	}
	return z;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	ll x = rd();
	ll y = rd();
	cout << (x < y ? "<" : (x == y ? "=" : ">")) << '\n';
}