#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int z[2521];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	ll x;
	cin >> x;
	for (int i=1; i<=2520; i++) {
		int ok = 1;
		for (int j=2; j<=10; j++)
			if (i % j == 0)
				ok = 0;
		z[i] = z[i-1] + ok;
	}
	cout << (x/2520)*z[2520] + z[x%2520] << '\n';
}