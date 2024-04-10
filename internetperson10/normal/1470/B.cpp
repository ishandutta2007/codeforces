#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

vector<ll> nums, primes;
map<ll, int> m;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	primes.push_back(2);
	for(ll i = 3; i < 1000; i++) {
		bool sad = false;
		for(int j = 0; j < primes.size(); j++) {
			if(!(i%primes[j])) sad = true;
		}
		if(!sad) primes.push_back(i);
	}
	for(int j = 0; j < primes.size(); j++) {
		primes[j] *= primes[j];
		// cout << primes[j] << "\n";
	}
	int t;
	cin >> t;
	while(t--) {
		int n, a0, a1;
		a0 = a1 = 0;
		cin >> n;
		nums.resize(n);
		for(int i = 0; i < n; i++) cin >> nums[i];
		sort(nums.begin(), nums.end());
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < primes.size(); j++) {
				if(nums[i] < primes[j]) break;
				while(!(nums[i]%(primes[j]))) {
					nums[i] /= (primes[j]);
				}
			}
			m[nums[i]]++;
		}
		for(auto p : m) {
			a0 = max(a0, p.second);
			if(!(p.second%2) || p.first == 1) a1 += p.second;
		}
		a1 = max(a0, a1);
		int q;
		cin >> q;
		while(q--) {
			ll x;
			cin >> x;
			cout << ((x == 0) ? a0 : a1) << '\n';
		}
		vector<ll>().swap(nums);
		map<ll, int>().swap(m);
	}
}