#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int a[105];

map<vector<int>, int> mp;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++)
		cin >> a[i];
	sort(a, a+n);
	n = unique(a, a+n) - a;

	for (int mask=0; mask<(1<<15); mask++) {
		vector<int> d(n);
		for (int i=0; i<n; i++)
			d[i] = __builtin_popcount((a[i] & 0x7fff) ^ mask);
		for (int j=1; j<n; j++)
			d[j] -= d[0];
		d[0] = 0;
		mp[d] = mask;
	}

	for (int mask=0; mask<(1<<15); mask++) {
		vector<int> d(n);
		for (int i=0; i<n; i++)
			d[i] = 30 - (int)__builtin_popcount((a[i] >> 15) ^ mask);
		for (int j=1; j<n; j++)
			d[j] -= d[0];
		d[0] = 0;

		if (mp.count(d)) {
			cout << ((mask << 15) ^ mp[d]) << '\n';
			return 0;
		}
	}

	cout << "-1\n";

}