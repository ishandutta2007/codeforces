#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

ll n, m, sol;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	sol += (n/5) * (m/5) * 5;

	sol += (n/5) * (m%5);
	sol += (m/5) * (n%5);

	for (ll i=1; i<=n%5; i++)
		for (ll j=1; j<=m%5; j++)
			if ((i+j) % 5 == 0)
				sol++;

	cout << sol << '\n';
}