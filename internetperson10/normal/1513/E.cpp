#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

const ll MOD = 1000000007;

vector<int> nums;

ll modpow(ll n, int e = 1000000005) {
	if(e == 0) return 1;
	if(e == 1) return n;
	ll x = modpow(n, e/2);
	x *= x;
	x %= MOD;
	if(e%2) {
		x *= n;
		x %= MOD;
	}
	return x;
}

ll fact(int n) {
	ll x = 1;
	for(int i = 1; i <= n; i++) {
		x *= i;
		x %= MOD;
	}
	return x;
}

int main() {
	int n;
	cin >> n;
	ll k = 0;
	nums.resize(n);
	for(int i = 0; i < n; i++) {
		cin >> nums[i];
		k += nums[i];
	}
	sort(nums.begin(), nums.end());
	ll ans;
	if(k%n) ans = 0;
	else {
		ans = fact(n);
		k /= n;
		int ct = 0, l = -1, r = n-1;
		for(int i = 0; i < n; i++) {
			ct++;
			if(i == n-1) {
				ans *= modpow(fact(ct));
				ct = 0;
				ans %= MOD;
			}
			else if(nums[i] != nums[i+1]) {
				ans *= modpow(fact(ct));
				ct = 0;
				ans %= MOD;
			}
		}
		for(int i = 0; i < n; i++) {
			if(nums[i] < k) l = i;
			if(nums[i] > k) {
				r = i;
				break;
			}
		}
		l++;
		r = n - r;
		if(l == 1 || r == 1) {
			cout << ans << '\n';
			return 0;
		}
		ans *= fact(l);
		ans %= MOD;
		ans *= fact(r);
		ans %= MOD;
		ans *= modpow(fact(l+r));
		ans %= MOD;
		ans *= 2;
		ans %= MOD;
	}
	cout << ans << '\n';
}