#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll a[200005], n, k, z[200005];

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

	ll sum = 0;
	for (int i=k; i<=n; i++) {
		sum += z[i] - z[i-k];
	}

	cout.precision(20);
	cout << fixed << (double)(sum) / (n-k+1) << '\n';
}