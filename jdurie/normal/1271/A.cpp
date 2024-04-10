#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef long double ld;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;
	if(e > f) {
		ll k = min(a, d);
		d -= k;
		cout << k * e + min(min(b, c), d) * f << endl;
	} else {
		ll k = min(min(b, c), d);
		d -= k;
		cout << k * f + min(a, d) * e << endl;
	}
}