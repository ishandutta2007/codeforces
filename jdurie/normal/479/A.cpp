#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef long double ld;


int main() {
	ll a, b, c, mx;
	cin >> a >> b >> c;
	mx = max(max(a + b + c, a * b * c), max(max(a + b * c, (a + b) * c), max(a * b + c, a * (b + c))));
	cout << mx << endl;
	return 0;
}