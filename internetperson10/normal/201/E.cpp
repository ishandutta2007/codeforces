#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

ll choose(ll n, int i) {
	ll ans = 1;
	for(int j = 1; j <= i; j++) {
		ans *= (n-j+1);
		ans /= j;
	}
	return ans;
}

bool good(int n, int m, int asks) {
	ll nums = (ll)m*asks;
	n--;
	int g = 1;
	while(n && g <= asks) {
		// cout << n << ' ';
		ll c = choose(asks, g);
		ll x = min(c, (ll)n);
		nums -= x*g;
		n -= x;
		g++;
	}
	if(nums >= 0 && n == 0) return true;
	return false;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n, m;
		cin >> n >> m;
		int l = -1, r = n-1;
		while(l+1 != r) {
			int mid = (l+r)/2;
			// cout << mid << ' ';
			if(!good(n, m, mid)) l = mid;
			else r = mid;
		}
		cout << r << '\n';
	}
}