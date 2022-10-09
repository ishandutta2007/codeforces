#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int a[1005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++)
		cin >> a[i];

	int sol = 1123123123, tt = -1;

	for (int t=1; t<=100; t++) {
		int z = 0;
		for (int i=1; i<=n; i++) {
			if (a[i] < t) {
				z += t - a[i] - 1;
			} else if (a[i] > t) {
				z += a[i] - t - 1;
			}
		}
		if (z < sol) {
			sol = z;
			tt = t;
		}
	}	
	cout << tt << ' ' << sol << '\n';
}