#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int a[500005];

bool ok(int m) {
	for (int i=0; i<m; i++)
		if (a[i]*2 > a[n-m+i])
			return false;
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++)
		cin >> a[i];
	sort(a, a+n);
	int l=0, r=n/2, o=0;
	while (l <= r) {
		int m = (l+r) >> 1;
		if (ok(m)) {
			o = m;
			l = m + 1;
		} else {
			r = m - 1;
		}
	}
	cout << n-o << '\n';
}