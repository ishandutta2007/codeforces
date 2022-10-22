#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

const ll MOD = 1000000007;

vector<ll> nums, sorted;
map<ll, int> m;

class FTree {
private:
	vector<ll> nums;
	int size = 1;
public:
	void init(int n) {
		vector<ll>().swap(nums);
		while(size < n) {
			size *= 2;
		}
		nums.resize(size+1);
	}
	void add(int n, int x) {
		while(n <= size) {
			nums[n] += x;
			n += (n & (-n));
		}
	}
	ll sum(int n) {
		ll ans = 0;
		while(n > 0) {
			ans += nums[n];
			n -= (n & (-n));
			ans %= MOD; // remove if too slo
		}
		return ans%MOD;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	nums.resize(n);
	sorted.resize(n);
	FTree f1, f2;
	f1.init(n+1); f2.init(n+1);
	ll ans = 0;
	for(int i = 0; i < n; i++) {
		cin >> nums[i];
		sorted[i] = nums[i];
		ll k = nums[i];
		k *= (n-i);
		k %= MOD;
		k *= (i+1);
		k %= MOD;
		ans += k;
		ans %= MOD;
	}
	sort(sorted.begin(), sorted.end());
	for(int i = 0; i < n; i++) {
		m[sorted[i]] = i+1;
	}
	for(int i = 0; i < n; i++) {
		ll k = nums[i] * (n-i);
		k %= MOD;
		k *= f1.sum(m[nums[i]]);
		k %= MOD;
		ans += k;
		ans %= MOD;
		f1.add(m[nums[i]], i+1);
	}
	reverse(nums.begin(), nums.end());
	for(int i = 0; i < n; i++) {
		ll k = nums[i] * (n-i);
		k %= MOD;
		k *= f2.sum(m[nums[i]]);
		k %= MOD;
		ans += k;
		ans %= MOD;
		f2.add(m[nums[i]], i+1);
	}
	cout << ans << '\n';
}