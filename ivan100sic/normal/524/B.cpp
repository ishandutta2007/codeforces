#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int w[1005], h[1005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> w[i] >> h[i];
	}

	int sol = 1123123123;

	for (int i=1; i<=1000; i++) {
		int ww = 0, ok = 1;
		for (int j=1; j<=n; j++) {
			if (max(w[j], h[j]) <= i) {
				ww += min(w[j], h[j]);
			} else if (min(w[j], h[j]) <= i) {
				ww += max(w[j], h[j]);
			} else {
				ok = 0;
			}
		}
		if (ok)
			sol = min(sol, ww * i);
	}
	cout << sol << '\n';

}