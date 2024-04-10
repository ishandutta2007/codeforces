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

	int n, p, k;
	cin >> n >> p >> k;
	map<int, int> mp;
	ll sol = 0;
	for (int i=0; i<n; i++) {
		int x;
		cin >> x;
		int y = x*1ll*x%p;
		y = y*1ll*y%p;
		y = ((y-k*1ll*x)%p+p)%p;
		sol += mp[y]++;
	}
	cout << sol << '\n';
}