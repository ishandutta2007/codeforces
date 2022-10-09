#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, t;
int a[100005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> t;
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}
	int r = 0;
	int z = 0;
	int s = 0;
	for (int l=0; l<n; l++) {
		while (r < n && z + a[r] <= t) {
			z += a[r++];
		}
		s = max(s, r-l);
		z -= a[l];
	}
	cout << s << '\n';
}