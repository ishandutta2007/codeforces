#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, k;
ll val[7005], mask[7005];

ll u[7005], v[7005], c[7005], dp[7005];
bool h[7005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++)
		cin >> mask[i];
	for (int i=0; i<n; i++)
		cin >> val[i];

	vector<int> red(n);
	iota(red.begin(), red.end(), 0);
	sort(red.begin(), red.end(), [&](int i, int j) {
		return __builtin_popcountll(mask[i]) < __builtin_popcountll(mask[j]);
	});

	for (int i : red) {
		auto it = find(u, u+k, mask[i]) - u;
		u[it] = mask[i];
		v[it] += val[i];
		c[it]++;
		if (it == k)
			k++;
	}

	ll sol = 0;

	for (int i=k-1; i>=0; i--) {
		h[i] |= c[i] >= 2;
		for (int j=0; j<i; j++)
			if ((u[j] & u[i]) == u[j])
				h[j] |= h[i];
		sol += h[i] ? v[i] : 0;
	}

	cout << sol << '\n';

}