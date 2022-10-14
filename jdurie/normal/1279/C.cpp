#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef long double ld;

vector<ll> stck;
set<ll> fr;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	ll T;
	cin >> T;
	while(T--) {
		ll n, m;
		cin >> n >> m;
		stck.clear();
		fr.clear();
		for(ll i = 0; i < n; i++) {
			ll x; cin >> x;
			stck.push_back(x);
		}
		ll stackInd = 0, ans = 0;
		for(ll i = 0; i < m; i++) {
			ll q; cin >> q;
			if(fr.count(q)) fr.erase(q);
			else {
				ans += 2 * fr.size();
				while(stck[stackInd] != q) {
					fr.insert(stck[stackInd]);
					stackInd++;
					ans += 2;
				}
				stackInd++;
			}
			ans++;
		}
		cout << ans << endl;
	}
}