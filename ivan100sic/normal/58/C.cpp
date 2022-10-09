#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int a[100005], b[100005], d[100005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	map<int, int> mp;

	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
		b[i] = 1 + min(i-1, n-i);
		d[i] = a[i] - b[i];
		mp[d[i]]++;
	}
	// najcesci broj >= 0
	int sol = 0;
	for (auto [x, y] : mp) {
		if (x >= 0)
			sol = max(sol, y);
	}
	cout << n - sol;
}