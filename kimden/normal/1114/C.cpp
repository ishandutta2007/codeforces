#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;

ll get(ll n, ll b, ll c) {
	ll ans = 0;
	n /= b;
	for (; n > 0; n /= b) {
		ans += n;
	}
	ans /= c;
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	ll n, b;
	cin >> n >> b;
	vector<ll> p;
	vector<ll> c;
	for (int i = 2; i * ll(i) <= b; ++i) {
		if (b % i == 0) {
			p.push_back(i);
			c.push_back(0);
			while (b % i == 0) {
				b /= i;
				++c.back();
			}
		}
	}
	if (b > 1) {
		c.push_back(1);
		p.push_back(b);
	}
	ll ans = 9000000000000000000LL;
	for (int i = 0; i < p.size(); ++i) {
		ans = min(ans, get(n, p[i], c[i]));
	}
	cout << ans << endl;
}