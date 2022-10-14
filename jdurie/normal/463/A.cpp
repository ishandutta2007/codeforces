#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
 
using namespace std;
typedef long long int ll;
typedef long double ld;
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n, s, mx = 0;
	cin >> n >> s;
	bool works = false;
	while(n--) {
		ll d, c;
		cin >> d >> c;
		d = 100 * d + c;
		if(d <= 100 * s) { 
		    works = true;
		    mx = max(mx, (100 - c) % 100);
		}
	}
	cout << (works ? mx : -1) << endl;
}