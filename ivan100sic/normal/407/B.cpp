#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int p[1005], n, d[1005];
const int m = 1'000'000'007;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> p[i];
		d[i] = (d[i-1]*2ll - d[p[i]-1] + 2 + 3ll*m) % m;
	}
	cout << d[n] << '\n';
}