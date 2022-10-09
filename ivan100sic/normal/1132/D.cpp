#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, k;
ll a[200005];
int b[200005];

bool moze(ll p) {
	basic_string<int> buff(k + 2, 0);
	int kk = 0;
	
	vector<basic_string<pair<int, int>>> pq(k);

	for (int i=0; i<n; i++) {
		ll t = a[i] / b[i] + 1;
		if (t < k)
			pq[t] += {1, i};
	}

	int t = 0;
	while (1) {
		while (t < k && pq[t].size() == 0)
			t++;
		if (t == k)
			break;

		auto [j, i] = pq[t].back(); pq[t].pop_back();

		kk++;
		buff[t]++;

		// cerr << t << ' ' << j << ' ' << i << '\n';

		if (kk == k+1)
			return false;
		ll t2 = (a[i] + j*p) / b[i] + 1;
		if (t2 < k)
			pq[t2] += {j+1, i};
	}

	for (int i=1; i<=k; i++) {
		buff[i] += buff[i-1];
		if (buff[i] > i)
			return false;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k;
	for (int i=0; i<n; i++)
		cin >> a[i];
	for (int i=0; i<n; i++)
		cin >> b[i];

	// moze(1);
	// return 0;

	ll l=0, r=3e12, o=-1;
	while (l <= r) {
		ll m = (l+r) >> 1;
		if (moze(m)) {
			o = m;
			r = m-1;
		} else {
			l = m+1;
		}
	}
	cout << o << '\n';
}