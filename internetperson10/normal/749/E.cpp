#include <bits/stdc++.h>

typedef long long ll;
using namespace std; // reset sublime thing

struct FTree {
	vector<ll> nums;
	int size = 1;
	void init(int n) {
		vector<ll>().swap(nums);
		while(size < n) size *= 2;
		nums.resize(size+1);
	}
	void add(int n, ll k) {
		while(n <= size) {
			nums[n] += k;
			n += (n & (-n));
		}
	}
	ll sum(int n) {
		ll ans = 0;
		while(n > 0) {
			ans += nums[n];
			n -= (n & (-n));
		}
		return ans;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n;
	long double inv = 0, exp = 0, tot = 0;
	cin >> n;
	FTree finv, fexp;
	finv.init(n);
	fexp.init(n);
	for(ll i = 1; i <= n; i++) {
		ll x;
		cin >> x;
		inv += finv.sum(n + 1 - x);
		finv.add(n + 1 - x, 1);
		exp += (long double)((n - i + 1) * (fexp.sum(n + 1 - x)))/((n * (n+1))/2);
		fexp.add(n + 1 - x, i);
		tot += (long double)((i * (i-1))/2 * (n - i + 1))/(n * (n+1));
	}
	// cout << inv << ' ' << exp << ' ' << tot << '\n';
	long double ans = 0;
	cout << fixed << setprecision(15) << inv - exp + tot << '\n';
}