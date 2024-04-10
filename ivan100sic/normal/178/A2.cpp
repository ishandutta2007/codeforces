#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
ll a[100005];
ll f[100005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++)
		cin >> a[i];
	for (int i=1; i<n; i++) {
		for (int j=(1<<20); j>=1; j>>=1) {
			if (i+j<=n) {
				f[i] += a[i];
				a[i+j] += a[i];
				a[i] = 0;
				break;
			}
		}
	}
	ll z = 0;
	for (int i=1; i<n; i++) {
		z += f[i];
		cout << z << '\n';
	}
}