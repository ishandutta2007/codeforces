// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i=0; i<n; i++) {
			cin >> a[i];
			a[i]--;
		}

		int p = n-1, v = 0;
		while (p >= 0) {
			int w = a[p] - v;
			if (p - w < 0) {
				break;
			}
			for (int i=0; i<w; i++) {
				if (a[p-w+i] != v+i) {
					p = -2;
					break;
				}
			}
			p -= w+1;
			v += w+1;
		}

		cout << (p == -1 ? "Yes\n" : "No\n");
	}
}