#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, k, f;
int a[200005], z[200005];
map<int, int> mp;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k;
	f = (1 << k) - 1;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
		z[i] = a[i] ^ z[i-1];
	}
	for (int i=0; i<=n; i++)
		mp[min(z[i], f - z[i])]++;
	ll sol = n*(n+1ll) / 2;
	for (auto p : mp) {
		ll x = p.second / 2;
		ll y = p.second - x;
		sol -= x*(x-1) / 2;
		sol -= y*(y-1) / 2;
	}
	cout << sol << '\n';
}