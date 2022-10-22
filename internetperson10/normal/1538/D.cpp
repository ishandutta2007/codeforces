#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

vector<ll> primes;

int factors(ll n) {
	int ans = 0;
	for(int i = 0; i < primes.size(); i++) {
		while(n%primes[i] == 0) {
			n /= primes[i];
			ans++;
		}
	}
	if(n > 1) ans++;
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	primes.push_back(2);
	for(ll i = 3; i < 32000; i++) {
		for(int j = 0; j <= primes.size(); j++) {
			if(j == primes.size()) {
				primes.push_back(i);
				break;
			}
			if(!(i%primes[j])) break;
		}
	}
	int t;
	cin >> t;
	while(t--) {
		ll a, b, k;
		cin >> a >> b >> k;
		if(a < b) swap(a, b);
		if(k == 1) {
			cout << ((a%b || a == b) ? "No\n" : "Yes\n");
		}
		else {
			cout << (factors(a) + factors(b) < k ? "No\n" : "Yes\n");
		}
	}
}