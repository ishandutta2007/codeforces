#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
ll z[100005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++) {
		int x;
		cin >> x;
		z[i] = z[i-1] + x;
	}

	ll c = 0, d = 0;
	for (int i=1; i<n; i++) {
		if (z[i]*3ll == z[n]*2ll)
			d += c;
		if (z[i]*3ll == z[n])
			c++;
	}

	cout << d << '\n';
}