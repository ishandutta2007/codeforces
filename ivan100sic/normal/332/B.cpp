#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, k;
ll a[200005], b[200005], z[200005];
int x[200005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
		z[i] = z[i-1] + a[i];
	}

	ll sol = -1;
	int ai = -1, bi = -1;

	for (int i=n-k+1; i>=k+1; i--) {
		b[i] = z[i+k-1] - z[i-1];
		x[i] = i;
		if (b[i+1] > b[i]) {
			b[i] = b[i+1];
			x[i] = x[i+1];
		}
	}

	for (int i=1; i<=n-2*k+1; i++) {
		ll w = z[i+k-1] - z[i-1];
		if (w + b[i+k] > sol) {
			sol = w + b[i+k];
			ai = i;
			bi = x[i+k];
		}
	}

	cout << ai << ' ' << bi << '\n';
}