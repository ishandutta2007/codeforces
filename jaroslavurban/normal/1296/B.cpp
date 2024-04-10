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
	ll t, n;
	cin >> t;
	for (ll i = 0; i < t; ++i){
		cin >> n;
		ll total = 0;
		for (ll i = 10; i >= 0; --i){
			ll over = ll(n / pow(10, i));
			if (over){
				total += over * (ll)pow(10, i);
				n -= over * (ll)pow(10, i);
				n += over * (ll)pow(10, i-1);
				i++;
			}
		}
		cout << total << endl;
	}
}