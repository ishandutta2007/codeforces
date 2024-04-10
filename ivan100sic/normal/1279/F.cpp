#include <bits/stdc++.h>
using namespace std;

typedef long double ld;

int n, k, l;
int a[2000005], z[2000005];
ld d[2000005];

int resi() {
	for (int i=0; i<2*n; i++)
		z[i+1] = z[i] + a[i];
	ld lo = 1e-7, hi = l+1;
	int steps = 50;
	while (steps--) {
		ld mid = (lo + hi) / 2;
		for (int i=l; i<=2*n; i++)
			d[i] = max(d[i-1], d[i-l] + (z[i] - z[i-l]) - mid);
		int tkn = 0;
		for (int i=2*n; i>=1;) {
			if (d[i] == d[i-1]) {
				i--;
			} else {
				i -= l;
				tkn++;
			}
		}
		(tkn <= k ? hi : lo) = mid;
	} 
	return z[2*n] - (int)round(d[2*n] + k * lo);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> k >> l;
	string s;
	cin >> s;
	for (int i=0; i<n; i++)
		a[i] = !!isupper(s[i]);
	int z = resi();
	for (int i=0; i<n; i++)
		a[i] = 1 - a[i];
	cout << min(resi(), z) << '\n';
}