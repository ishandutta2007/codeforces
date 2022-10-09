// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

const int inf = 1e9;

int n;
int a[200005];
int d[2][200005];

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i=0; i<n; i++) cin >> a[i];
		d[0][n] = 0;
		d[1][n] = 0;
		d[0][n+1] = inf;
		d[1][n+1] = inf;
		for (int i=n-1; i>=0; i--) {
			for (int j=0; j<2; j++) {
				int v = inf;
				for (int l=1; l<=2; l++) {
					v = min(v, d[j^1][i+l] + j*accumulate(a+i, a+i+l, 0));
				}
				d[j][i] = v;
			}
		}
		cout << d[1][0] << '\n';
	}
}