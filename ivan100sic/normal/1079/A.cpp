#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n, k, z=0;
	cin >> n >> k;
	map<int, int> mp;
	for (int i=0; i<n; i++) {
		int x;
		cin >> x;
		z = max(z, ++mp[x]);
	}
	z = (z + k - 1) / k * k;
	cout << z* mp.size() - n << '\n';
}