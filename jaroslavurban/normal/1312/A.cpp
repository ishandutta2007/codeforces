#ifndef __PROGTEST__
#include <bits/stdc++.h>
using namespace std;
#endif // __PROGTEST__

typedef long long ll;
typedef long double ld;
#define pb(x) push_back(x)
#define ff first
#define ss second
#define vec vector

int main(){
	ll t, n, m;
	cin >> t;
	for (ll i = 0; i < t; ++i){
		cin >> n >> m;
		if (n % m == 0) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}