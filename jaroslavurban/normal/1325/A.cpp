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


ll gcd(ll a, ll b){
	while (a != 0){
		ll c = a;
		a = b % a;
		b = c;
	}
	return b;
}


int main(){
	ll n;
	cin >> n;
	for (ll i = 0; i < n; ++i){
		ll val;
		cin >> val;
		cout << val - 1 << " " << 1 << endl;
	}
}