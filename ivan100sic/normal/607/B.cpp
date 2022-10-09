#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int a[505];
int d[505][505];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++)
		cin >> a[i];
	for (int l=n; l>=1; l--) {
		for (int r=l; r<=n; r++) {
			if (l == r) {
				d[l][r] = 1;
			} else if (l == r-1) {
				d[l][r] = a[l] == a[r] ? 1 : 2;
			} else {
				d[l][r] = 1123123123;
				for (int k=l; k<r; k++)
					d[l][r] = min(d[l][r], d[l][k] + d[k+1][r]);
				if (a[l] == a[r])
					d[l][r] = min(d[l][r], d[l+1][r-1]);
			}
		}
	}
	cout << d[1][n] << '\n';
}