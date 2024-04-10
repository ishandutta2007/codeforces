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
ll mod = 998244353;

bool cmp(pair<ll, ll> x, pair<ll, ll> y) {
	return x.first * x.second < y.first * y.second;
}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

	ll n;
	cin >> n;
	vector<pair<ll, ll>> a(n);
	vector<ll> b(n);
	vector<ll> f(n);
	for (ll i = 0; i < n; i++) {
		a[i].second = (i + 1) * (n  - i);
	}
	for (int i = 0; i < n; i++) cin >> a[i].first;
	for (int i = 0; i < n; i++) cin >> b[i];
	sort(a.begin(), a.end(), cmp); sort(b.begin(), b.end());
	reverse(b.begin(), b.end());
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		ans += (((a[i].first * a[i].second) % mod )* b[i]) % mod;
		ans %= mod;
	}
	cout << ans << endl;
	//system("pause");
	return 0;
}