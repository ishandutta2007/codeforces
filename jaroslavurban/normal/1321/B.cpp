#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int main(){
	ll n;
	cin >> n;
	ll vals[1000000] = {};
	for (ll i = 0; i < n; ++i){
		ll val;
		cin >> val;
		vals[val - i + 500000] += val;
	}

	ll max = 0;
	for (ll i = 0; i < 1000000; ++i){
		if (vals[i] > max) max = vals[i];
	}

	cout << max << endl;
}