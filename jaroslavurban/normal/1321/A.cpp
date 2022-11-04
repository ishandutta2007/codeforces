#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int main(){
	ll n;
	cin >> n;
	vector<ll> ro1;
	ll r1 = 0, r2 = 0;
	for (ll i = 0; i < n; i++){
		ll val;
		cin >> val;
		ro1.push_back(val);
	}
	for (ll i = 0; i < n; i++){
		ll val;
		cin >> val;
		if (val == ro1[i])
			continue;
		if (val)
			r2++;
		else
			r1++;
	}

	// cout << r1 << " " << r2 << endl;

	if (!r1)
		cout << -1 << endl;
	else{
		cout << r2 / r1 + 1 << endl;
	}
}