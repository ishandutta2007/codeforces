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
int p = 47;

bool eq(pair<pair<ll, ll>, ll> x, pair<pair<ll, ll>, ll> y) {
	return (x.first.first == y.first.first) && (x.first.second = y.first.second) && (x.second == y.second);
}

ll gcd(ll a, ll b) {
	if (!b) return a;
	return gcd(b, a % b);
}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<pair<ll, ll>> po(n);
	for (int i = 0; i < n; i++) {
		cin >> po[i].first >> po[i].second;
	}
	vector<pair<pair<ll, ll>, ll>> lines;
	set<pair<pair<ll, ll>, ll>> lin;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			ll a, b, c;
			a = po[i].second - po[j].second;
			b = po[j].first - po[i].first;
			c = po[i].first * po[j].second - po[j].first * po[i].second;
			if (a < 0 || (a == 0 && b < 0)) {
				a *= -1; b *= -1; c *= -1;
			}
			ll t = gcd(gcd(abs(a), abs(b)), abs(c));
			a /= t; b /= t; c /= t;
			if (lin.find({ {a, b}, c }) == lin.end())
			lines.push_back({ { a, b}, c });
			lin.insert({ {a, b}, c });
		}
	}
	sort(lines.begin(), lines.end());
	ll cur = 1;
	ll sz = lines.size();
	ll ans = sz * (sz - 1) / 2;
	//cout << sz << endl;
	//cout << lines[0].first.first << " " << lines[0].first.second << " " << lines[0].second << endl;
	for (int i = 1; i < sz; i++) {
		//cout << lines[i].first.first << " " << lines[i].first.second << " " << lines[i].second << endl;
		if ((lines[i].first.first == lines[i - 1].first.first) && (lines[i].first.second == lines[i - 1].first.second)) cur++;
		else {
			ans -= (cur * (cur - 1) / 2);
			cur = 1;
		}
	}
	ans -= (cur * (cur - 1) / 2);
	cout << ans << endl;
	//system("pause");
	return 0;
}