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

	ll t, s, x;
	int z = 0;
	cin >> t >> s >> x;
	if (x < t)
		z = 0;
	else if (x == t)
		z = 1;
	else if (x == t + 1)
		z = 0;
	else if ((x-t) % s <= 1)
		z = 1;
	else
		z = 0;
	cout << (z ? "YES\n" : "NO\n");
}