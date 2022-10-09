#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int k, b, n;
int a[100005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> k >> b >> n;
	for (int i=1; i<=n; i++)
		cin >> a[i];

	if (b == 0) {
		// broji nule samo lol
		ll sol = 0;
		int streak = 0;
		for (int i=1; i<=n; i++) {
			streak++;
			if (a[i])
				streak = 0;
			sol += streak;
		}
		cout << sol << '\n';
		return 0;
	}

	bool izbaci_nule = false;

	if (b == k-1) {
		b = 0;
		izbaci_nule = true;
	}

	int z = 0;
	map<int, int> mp;
	mp[0] = 1;
	ll sol = 0;
	for (int i=1; i<=n; i++) {
		z = (z + a[i]) % (k-1);
		sol += mp[(z-b+(k-1)) % (k-1)];
		mp[z]++;
	}

	if (izbaci_nule) {
		// broji nule samo lol
		int streak = 0;
		for (int i=1; i<=n; i++) {
			streak++;
			if (a[i])
				streak = 0;
			sol -= streak;
		}
	}

	cout << sol << '\n';
}