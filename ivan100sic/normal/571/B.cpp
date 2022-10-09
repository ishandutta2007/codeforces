#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, k;
int a[300005];
unordered_map<int, int> dp[300005];

void mn(int& x, int y) {
	x = min(x, y);
}

void add(int i, int j, int v) {
	auto it = dp[i].find(j);
	if (it == dp[i].end())
		dp[i][j] = v;
	else
		mn(it->second, v);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k;
	for (int i=0; i<n; i++)
		cin >> a[i];
	sort(a, a+n);
	int w = n/k;
	int big = n%k;
	int small = k-big;

	// cerr << "config: " << w << ' ' << big << ' ' << small << '\n';

	dp[0][0] = 0;
	for (int i=0; i<n; i++) {
		for (auto [b, q] : dp[i]) {
			int s = (i-b*(w+1))/w;
			// cerr << i << ' ' << b << ' ' << s << ' ' << q << '\n';
			if (b < big)
				add(i+w+1, b+1, q + a[i+w] - a[i]);
			if (s < small)
				add(i+w, b, q + a[i+w-1] - a[i]);
		}
	}
	cout << dp[n][big] << '\n';
}