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

	ll n, x, y;
	cin >> n >> x >> y;
	ll d1 = x+y-2;
	ll d2 = n+n-x-y;
	if (d1 <= d2) {
		cout << "White\n";
	} else {
		cout << "Black\n";
	}
}