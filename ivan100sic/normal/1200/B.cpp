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
		int n, m, k;
		cin >> n >> m >> k;
		vector<int> h(n);
		for (int i=0; i<n; i++)
			cin >> h[i];
		bool ok = true;
		for (int i=0; i<n-1; i++) {
			// da li mogu ikako da predjem?
			if (h[i] + m + k < h[i+1]) {
				ok = false;
				break;
			}

			if (h[i] + k < h[i+1]) {
				int delta = h[i+1] - h[i] - k;
				m -= delta;
				h[i] += delta; // nebitno
			} else {
				int delta = min(h[i], h[i] + k - h[i+1]);
				m += delta;
				h[i] -= delta;
			}
		}

		cout << (ok ? "YES\n" : "NO\n");
	}
}