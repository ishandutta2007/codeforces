#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#include <deque>
#include <cassert>
#include <math.h>

using namespace std;

#define PI 3.14159265
typedef long long ll;

const ll INF = 4 * 1e18;
const int INFi = 2 * 1e9;
ll mod = 1e9 + 7;

ll gol(ll a, ll b) {
	return (log(a) / log(b));
}


int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

	ll n, b;
	cin >> n >> b;
	vector<pair<ll, ll>> cnt;
	for (ll i = 2; i <= sqrt(b); i++) {
		ll c = 0;
		while (b % i == 0) {
			b /= i;
			c++;
		}
		if (c) {
			cnt.push_back({ i, c });
		}
	}
	if (b != 1) cnt.push_back({ b, 1 });
	ll maxi = 1e18;
	for (auto f : cnt) {
		ll h = gol(n, f.first);
		//cout << h << " " << f.first << endl;
		ll d = f.first;
		ll c = 0;
		for (ll i = 1; i <= h; i++) {
			c += (n / d);
			d *= f.first;
		}
		maxi = min(maxi, c / f.second);
	}
	cout << maxi << endl;
	//system("pause");
	return 0;
}