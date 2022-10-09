#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

ll c[11];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n;
	cin >> n;
	for (int i=1; i<=n; i++) {
		int x = i % 9;
		if (!x) x = 9;
		c[x]++;
	}

	ll z = 0;

	for (int i=1; i<=9; i++)
		for (int j=1; j<=9; j++)
			for (int k=1; k<=9; k++)
				if (i*j % 9 == k % 9)
					z += 1ll * c[i] * c[j] * c[k];

	ll y = 0;
	for (ll i=1; i<=n; i++)
		y += n / i;

	cout << z - y << '\n';
}