#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
ll a[2005];

const ll MOD = 100005;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++)
		cin >> a[i];

	cout << n+1 << '\n';

	for (int i=n; i>=1; i--) {
		ll v = (i - a[i] % MOD + 2 * MOD);
		cout << "1 " << i << ' ' << v << '\n';
		for (int j=1; j<=i; j++)
			a[j] += v;
	}

	cout << "2 " << n << " 100005\n";
}