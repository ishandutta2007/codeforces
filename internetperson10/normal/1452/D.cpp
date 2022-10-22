#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll MOD = 998244353;

vector<ll> nums;

ll modpow(ll n, int e = MOD-2) {
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

ll two = modpow(2);
ll four = modpow(4);

int main() {
	nums.push_back(two);
	nums.push_back(two);
	nums.push_back(four);
	nums.push_back(four);
	for(int i = 4; i < 200001; i++) {
		ll x = two * nums[i-1];
		x %= MOD;
		ll y = four * nums[i-2];
		y %= MOD;
		nums.push_back((x+y)%MOD);
	}
	int n;
	cin >> n;
	cout << nums[n] << "\n";
}