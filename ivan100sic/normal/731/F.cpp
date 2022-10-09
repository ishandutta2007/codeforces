#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int a[200005], c[400005], z[400005];
int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
		c[a[i]]++;
	}
	for (int i=1; i<=400000; i++)
		z[i] = z[i-1] + c[i];

	ll y = 0;

	for (int i=1; i<=200000; i++) {
		if (c[i]) {
			ll t = 0;
			for (int j=i; j<=200000; j+=i)
				t += j * 1ll * (z[j+i-1] - z[j-1]);
			y = max(y, t);
		}
	}

	cout << y << '\n';
}