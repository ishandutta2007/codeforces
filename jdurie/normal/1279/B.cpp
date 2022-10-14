#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef long double ld;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	ll T;
	cin >> T;
	while(T--) {
		ll n, s, mx = 0, maxInd = -1, sm = 0;
		cin >> n >> s;
		bool fuck = false;
		for(ll i = 0; i < n; i++) {
			ll a;
			cin >> a;
			sm += a;
			if(sm - max(a, mx) > s)
				fuck = true;
			if(!fuck && a > mx) {
				mx = a;
				maxInd = i + 1;
			}
		}
		if(sm <= s) cout << 0 << endl;
		else cout << maxInd << endl;
	}
}