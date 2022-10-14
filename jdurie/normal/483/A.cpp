#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef long double ld;


int main() {
	ll l, r;
	cin >> l >> r;
	if(r - l < 2 || ((l % 2) && r - l == 2)) cout << -1 << endl;
	else cout << r - r % 2 - 2 << " " << r - r % 2 - 1 << " " << r - r % 2 << endl;
	return 0;
}