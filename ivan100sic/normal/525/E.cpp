// I've decided to retire from ALL contests
// It's been a nice ride... but I need to move on
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, k;
int a[25];
ll f[20], s;
map<pair<int, ll>, int> mp;

ll F(int x) {
	if (x >= 20)
		return s+1;
	return min(s+1, f[x]);
}

int gt(pair<int, ll> x) {
	auto it = mp.find(x);
	if (it == mp.end())
		return 0;
	return it->second;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	f[0] = 1;
	for (int i=1; i<20; i++)
		f[i] = f[i-1] * i;

	cin >> n >> k >> s;
	for (int i=0; i<n; i++)
		cin >> a[i];
	int h = n / 2;
	for (int choose=0; choose<(1<<n); choose+=(1<<h)) {
		for (int mask=choose; mask; mask = (mask-1) & choose) {
			ll z = 0;
			for (int i=h; i<n; i++) {
				if (choose & (1 << i)) {
					if (mask & (1 << i))
						z += F(a[i]);
					else
						z += a[i];
				}
			}
			mp[{__builtin_popcount(mask), z}]++;
		}

		{
			int mask = 0;

			ll z = 0;
			for (int i=h; i<n; i++) {
				if (choose & (1 << i)) {
					if (mask & (1 << i))
						z += F(a[i]);
					else
						z += a[i];
				}
			}
			mp[{__builtin_popcount(mask), z}]++;
		}
	}

	ll sol = 0;
	for (int choose=0; choose<(1<<h); choose++) {
		for (int mask=choose; mask; mask = (mask-1) & choose) {
			ll z = 0;
			for (int i=0; i<h; i++) {
				if (choose & (1 << i)) {
					if (mask & (1 << i))
						z += F(a[i]);
					else
						z += a[i];
				}
			}
			for (int kk=0; kk<=k; kk++)
				sol += gt({kk - __builtin_popcount(mask), s - z});
		}

		{
			int mask = 0;

			ll z = 0;
			for (int i=0; i<h; i++) {
				if (choose & (1 << i)) {
					if (mask & (1 << i))
						z += F(a[i]);
					else
						z += a[i];
				}
			}
			for (int kk=0; kk<=k; kk++)
				sol += gt({kk - __builtin_popcount(mask), s - z});
		}
	}
	cout << sol << '\n';
}

// I will still practice daily...