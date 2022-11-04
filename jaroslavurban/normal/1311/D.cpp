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

const ll maxNum = 100000;

int main(){
	ll t;
	cin >> t;
	for (ll i = 0; i < t; ++i){
		ll a, b, c;
		cin>>a>>b>>c;
		ll res = maxNum;
		ll res_a, res_b, res_c;

		for (ll _a = 1; _a < 2*a; ++_a){
			for (ll m1 = 1; _a*m1 < 2*b + a; ++m1){
				ll _b = _a * m1;
				for (ll m2 = 1; _b*m2 < 2*c + _b; ++m2){
					ll _c = _b * m2;
					if (res > abs(a-_a) + abs(b-_b) + abs(c-_c)){
						res = abs(a-_a) + abs(b-_b) + abs(c-_c);
						res_a = _a; res_b = _b; res_c = _c;
					}
				}
			}
		}

		cout << res << endl;
		cout << res_a << " " << res_b << " " << res_c << endl;
	}
}