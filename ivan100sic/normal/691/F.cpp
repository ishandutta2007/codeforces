#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int a[1000005];
int c[3000005];
ll d[3000005];

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
	for (int i=1; i<=3000000; i++) {
		for (int j=1; i*j<=3000000; j++) {
			d[i*j] += c[i] * 1ll * c[j];
		}
	}
	for (int i=1; i<=n; i++) {
		if (a[i] * 1ll * a[i] <= 3000000) {
			d[a[i] * a[i]]--;
		}
	}
	for (int i=1; i<=3000000; i++)
		d[i] += d[i-1];
	int q;
	cin >> q;
	while (q--) {
		int x;
		cin >> x;
		cout << n*(n-1ll) - d[x-1] << '\n';
	}
}