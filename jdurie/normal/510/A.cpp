#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef long double ld;

int main() {
	ll n, m;
	cin >> n >> m;
	for(ll i = 0; i < n; i++) {
		if(i % 2) {
			if(i % 4 == 3) cout << "#";
			for(ll j = 0; j < m - 1; j++) cout << ".";
			if(i % 4 == 1) cout << "#";
		} else for(ll j = 0; j < m; j++) cout << "#";
		cout << endl;
	}
	return 0;
}