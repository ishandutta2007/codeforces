#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef long double ld;


int main() {
	ll x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	if(x1 != x2 && y1 != y2 && abs(x1 - x2) != abs(y1 - y2)) {
		cout << -1 << endl;
		return 0;
	}
	cout << (x1 == x2 ? x1 + y2 - y1 : x2) << " ";
	cout << (y1 == y2 ? y1 + x2 - x1 : y1) << " ";
	cout << (x1 == x2 ? x1 + y2 - y1 : x1) << " ";
	cout << (y1 == y2 ? y1 + x2 - x1 : y2) << endl;
	return 0;
}