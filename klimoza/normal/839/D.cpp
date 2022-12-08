#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <map>
#include <set>
#include <deque>
#include <cassert>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <random>

using namespace std;

typedef long long ll;

ll INF = 1e18;
int INFi = 2e9;
double eps = 1e-6;
ll mod = 1e9 + 7;

ll binpow(ll a, ll k) {
	if (k <= 0) return 1;
	if (k % 2 == 1) {
		ll b = binpow(a, k - 1);
		return (b * a) % mod;
	}
	ll b = binpow(a, k / 2);
	return (b * b) % mod;
}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	
	ll NN = 1e6 + 1;
	int n;
	cin >> n;
	vector<int> a(n);
	vector<int> p(NN);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		p[a[i]]++;
	}
	vector<ll> cnt(NN);
	for (int i = 1; i < NN; i++) {
		for (int j = i; j < NN; j += i) {
			cnt[i] += p[j];
		}
	}
	vector<ll> ans(NN);
	ll tot = 0;
	for (ll i = NN - 1; i > 1; i--) {
		if (cnt[i] == 0) continue;
		ans[i] = (cnt[i] * binpow(2, cnt[i] - 1)) % mod;
		for (int j = 2 * i; j < NN; j += i) {
			ans[i] -= ans[j];
			ans[i] = (ans[i] + mod) % mod;
		}
		tot += i * ans[i];
		tot %= mod;
		//cout << ans[i] << " " << i << " " << cnt[i] << endl;
	}
	cout << tot << endl;
	//system("pause");
	return 0;
}