#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, k;
ll sol;
map<int, ll> b, c;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k;
	for (int i=1; i<=n; i++) {
		int x;
		cin >> x;
		if (x % k == 0) {
			sol += c[x/k];
			c[x] += b[x/k];
		}
		b[x] += 1;
	}
	cout << sol << '\n';
}