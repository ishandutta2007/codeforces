#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int BIG = 10000000;

ll best[BIG+1], ans[BIG+1], geet[BIG+1];
vector<int> primes;

bool is_prime(int n) {
	if(n == 1) return false;
	int x = sqrt(n) + 1;
	for(int i = 2; i < x; i++) {
		if(!(n%i)) return false;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	for(int i = 2; i <= 4000; i++) {
		if(is_prime(i)) {
			primes.push_back(i);
		}
	}
	for(int i = 1; i <= BIG; i++) {
		ans[i] = 1; best[i] = -1; geet[i] = 1;
	}
	for(int i = 0; i < primes.size(); i++) {
		for(int j = primes[i]; j <= BIG; j += primes[i]) {
			int k = j, x = 1, c = 1;
			while(!(k%primes[i])) { // largest prime power
				k /= primes[i];
				c *= primes[i];
				x += c;
			}
			// cout << j << ' ' << c << ' ' << x << '\n';
			geet[j] *= c; // number
			ans[j] *= x; // sum of divisors
		}
	}
	for(int i = 1; i <= BIG; i++) {
		if(geet[i] != i) {
			int g = i/geet[i];
			ans[i] *= (ll)g+1;
		}
	}
	for(int i = 10000000; i > 0; i--) {
		if(ans[i] <= BIG) {
			best[ans[i]] = i;
		}
	}
	int t;
	cin >> t;
	while(t--) {
		ll n;
		cin >> n;
		cout << best[n] << '\n';
	}
}