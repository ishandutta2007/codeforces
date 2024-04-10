#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

ll cbrt(ll x) {
	ll y = floor(pow(x, ld(1)/3));
	y += 2;
	while (y*y*y > x)
		y--;
	return y;
}

int steps(ll x) {
	int t = 0;
	while (x > 0) {
		t++;
		ll y = cbrt(x);
		x -= y*y*y;
	}
	return t;
}

int dp[10005], mv[10005];

pair<int, ll> solve(ll x) {
	if (x < 10005)
		return {dp[x], mv[x]};

	ll y = cbrt(x);
	auto [a1, b1] = solve(x-y*y*y);
	a1++;
	auto [a2, b2] = solve(y*y*y-(y-1)*(y-1)*(y-1));
	a2++;

	if (a1 >= a2)
		return {a1, b1 + y*y*y};
	return {a2, b2 + (y-1)*(y-1)*(y-1)};
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	for (int i=1; i<10005; i++) {
		int j = cbrt(i);
		dp[i] = dp[i-j*j*j] + 1;
	}

	for (int i=1; i<10005; i++) {
		mv[i] = i;
		if (dp[i] < dp[i-1]) {
			dp[i] = dp[i-1];
			mv[i] = mv[i-1];
		}
	}

	ll x;
	cin >> x;
	auto [a, b] = solve(x);
	cout << a << ' ' << b << '\n';
}