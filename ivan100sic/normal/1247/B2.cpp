#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, k, d;
int a[200005];
int c[1000005], u;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		cin >> n >> k >> d;
		for (int i=0; i<n; i++)
			cin >> a[i];
		for (int i=0; i<d; i++)
			u += ++c[a[i]] == 1;
		int sol = 1e9;
		for (int i=0; i+d<=n; i++) {
			sol = min(sol, u);
			if (i+d < n) {
				u += ++c[a[i+d]] == 1;
				u -= --c[a[i]] == 0;
			}
		}
		cout << sol << '\n';
		for (int i=0; i<n; i++)
			c[a[i]] = 0;
		u = 0;
	}
}