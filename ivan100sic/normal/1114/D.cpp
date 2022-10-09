#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int a[5005];
int d[5005][5005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++)
		cin >> a[i];
	n = unique(a, a+n) - a;

	for (int l=n-1; l>=0; l--) {
		for (int r=l+1; r<n; r++) {
			d[l][r] = max(d[l+1][r], d[l][r-1]);
			if (a[l] == a[r])
				d[l][r] = max(d[l][r], d[l+1][r-1] + 1);
		}
	}

	cout << n - 1 - d[0][n-1] << '\n';
}