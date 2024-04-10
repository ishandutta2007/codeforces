#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef long double ld;

string key(vector<ll> primes, vector<ll> pows) {
	string s = "";
	for(ll i = 0; i < primes.size(); i++)
		s = s +  "(" + to_string(primes[i]) + ", " + to_string(pows[i]) + ")";
	return s;
}

ll a[100010];
map<string, int> mp;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n, k, ans = 0;
	cin >> n >> k;
	for(ll i = 0; i < n; i++) cin >> a[i];
	for(ll i = 0; i < n; i++) {
		vector<ll> primes, pows, xPows;
		for(ll p = 2; p * p <= a[i]; p++)
			if(a[i] % p == 0) {
				ll ct = 0;
				while(a[i] % p == 0) {
					ct++;
					a[i] /= p;
				}
				if(ct % k) {
					primes.push_back(p);
					pows.push_back(ct % k);
					xPows.push_back(k - ct % k);
				}
			}
		if(a[i] > 1) {
			primes.push_back(a[i]);
			pows.push_back(1);
			xPows.push_back(k - 1);
		}
		string k = key(primes, pows), rK = key(primes, xPows);
		if(mp.count(rK))
			ans += mp[rK];
		if(mp.count(k))
			mp[k]++;
		else mp[k] = 1;
	}
	cout << ans << endl;
	return 0;
}