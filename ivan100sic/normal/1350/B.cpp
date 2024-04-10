// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int n;
int a[100005], d[100005];

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i=1; i<=n; i++) {
			cin >> a[i];
			d[i] = 0;
		}

		for (int i=1; i<=n; i++) {
			d[i] = max(d[i], 1);
			for (int j=i; j<=n; j+=i) {
				if (a[j] > a[i]) {
					d[j] = max(d[j], d[i] + 1);
				}
			}
		}

		cout << *max_element(d+1, d+n+1) << '\n';
	}
}