#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int a[100005], b[100005];
int c[100005], d[100005];

int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++) {
		int x;
		cin >> x;
		if (!a[x])
			a[x] = i;
		b[x] = i;
	}

	for (int i=1; i<=100000; i++) {
		if (a[i] > 0)
			c[a[i]]++;
		if (b[i] > 0)
			d[b[i]]++;
	}

	ll sol = 0, z = 0;
	for (int i=1; i<=n; i++) {
		sol += d[i] * 1ll * z;
		z += c[i];
	}
	cout << sol;
}