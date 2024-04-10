#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef long double ld;

ll a[200010];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	ll T;
	cin >> T;
	while(T--) {
		ll n;
		cin >> n;
		for(ll i = 0; i < n; i++) cin >> a[i];
		bool b = true;
		for(ll i = 0; i < n - 1; i++)
			if(b && abs(a[i] - a[i + 1]) > 1) {
				cout << "YES" << endl;
				cout << i + 1 << " " << i + 2 << endl;
				b = false;
			}
		if(b) cout << "NO" << endl;
	}
}