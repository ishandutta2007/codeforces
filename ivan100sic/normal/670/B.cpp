#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int a[200005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n, k;
	cin >> n >> k;
	for (int i=1; i<=n; i++)
		cin >> a[i];

	int r = 0;
	for (int j=1; j<=n; j++) {
		int lj = r+1;
		int rj = r+j;
		if (lj <= k && k <= rj) {
			cout << a[k-lj+1] << '\n';
			return 0;
		}
		r = rj;
	}
}