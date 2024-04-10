#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
ll a[100005], z[100005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> a[i];
		z[i+1] = z[i] + a[i];
	}

	sort(z, z+n);
	int y = 1, c = 1;
	for (int i=1; i<n; i++) {
		if (z[i] == z[i-1]) {
			c++;
		} else {
			c = 1;
		}
		y = max(y, c);
	}
	cout << n-y << '\n';
}