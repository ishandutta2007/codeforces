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


void checkNum(ll *arr, ll n, ll ind){
	for (ll i = 0; i < n; ++i){
		if (i != ind && ind - arr[ind] == i - arr[i]){
			ll tmp = arr[ind];
			arr[ind] = arr[i];
			arr[i] = tmp;
			checkNum(arr, n, ind);
			checkNum(arr, n, i);
			break;
		}
	}
}


int main(){
	ll t, n;
	cin >> t;
	for (ll i = 0; i < t; ++i){
		cin >> n;
		ll arr[100];
		for (ll i = 0; i < n; ++i)
			cin >> arr[i];
		for (ll i = 0; i < n; ++i)
			checkNum(arr, n, i);
		for (ll i = 0; i < n; ++i)
			cout << arr[i] << " ";
		cout << endl;
	}
}