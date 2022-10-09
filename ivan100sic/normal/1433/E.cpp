// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	// http://oeis.org/A110468
	ll a[10] = {	1, 3, 40, 1260, 72576, 6652800, 889574400, 163459296000, 39520825344000, 12164510040883200};
	int x;
	cin >> x;
	cout << a[x/2-1] << '\n';
}