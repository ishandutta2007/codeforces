#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, k1, k2;
int a[1005], b[1005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k1 >> k2;
	for (int i=0; i<n; i++)
		cin >> a[i];
	for (int i=0; i<n; i++)
		cin >> b[i];

	while (k1--) {
		int j = 0;
		for (int i=1; i<n; i++) {
			if (abs(a[i] - b[i]) > abs(a[j] - b[j]))
				j = i;
		}
		if (a[j] > b[j])
			a[j]--;
		else
			a[j]++;
	}

	while (k2--) {
		int j = 0;
		for (int i=1; i<n; i++) {
			if (abs(a[i] - b[i]) > abs(a[j] - b[j]))
				j = i;
		}
		if (a[j] > b[j])
			b[j]++;
		else
			b[j]--;
	}

	ll e = 0;
	for (int i=0; i<n; i++)
		e += (a[i] - b[i]) * 1ll * (a[i] - b[i]);
	cout << e << '\n';
}