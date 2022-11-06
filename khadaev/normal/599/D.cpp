#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
const ll K = 3 * 1000 * 1000;

int main() {
	ll x;
	scanf("%I64d", &x);
	vector<pair<ll, ll>> rectangles;
	for (ll n = 1; n < K; ++n) {
		ll rest = x - n * (2 * n + 1) * (n + 1) / 6;
		if (2 * rest % (n * (n + 1))) continue;
		ll rest1 = 2 * rest / (n * (n + 1));
		ll m = rest1 + n;
		if (m < n) continue;
		rectangles.push_back({n, m});
		if (n != m) rectangles.push_back({m, n});
	}
	sort(rectangles.begin(), rectangles.end());
	printf("%d\n", rectangles.size());
	for (auto p : rectangles) printf("%I64d %I64d\n", p.first, p.second);
}