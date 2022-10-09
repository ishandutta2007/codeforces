#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int a[300005], b[300005];

ll solve(basic_string<int> c) {
	sort(c.begin(), c.end());
	ll z = 0, t = 0;
	int y = -1;
	for (int x : c) {
		if (x == y)
			t++;
		else
			t = 0;
		y = x;
		z += t;
	}
	return z;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
		b[i] = b[i-1] ^ a[i];
	}

	ll z = 0;

	basic_string<int> c;
	for (int i=0; i<=n; i+=2)
		c += b[i];
	z += solve(c);
	c = {};
	for (int i=1; i<=n; i+=2)
		c += b[i];
	z += solve(c);
	cout << z << '\n';
}