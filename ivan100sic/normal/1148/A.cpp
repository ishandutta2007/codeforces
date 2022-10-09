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

	ll x, y, z;
	cin >> x >> y >> z;
	ll sol = 0;

	// abab..ab(ababab)
	sol = max(sol, 2*min(x, y) + 2*z);
	// baba..bab(abab)
	sol = max(sol, 2*min(x, y-1)+1 + 2*z);
	// (abab)abababa
	sol = max(sol, 2*min(x-1, y)+1 + 2*z);
	
	cout << sol << '\n';
}