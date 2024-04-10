#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		vector<int> a(n);
		for (int i=0; i<n; i++)
			cin >> a[i];
		int sol = 1123123123, pos = -1;
		for (int i=0; i+k<n; i++) {
			int w = a[i+k] - a[i];
			if (w < sol) {
				sol = w;
				pos = (a[i+k] + a[i]) / 2;
			}
		}
		cout << pos << '\n';
	}
}