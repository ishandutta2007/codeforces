// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int n;
int a[200005];

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		int e = 0, f = n+1, l = -1;
		for (int i=1; i<=n; i++) {
			cin >> a[i];
			if (a[i] == i) {
				e++;
			} else {
				f = min(f, i);
				l = max(l, i);
			}
		}

		if (e == n) {
			cout << "0\n";
		} else if (l-f+1 == n-e) {
			cout << "1\n";
		} else {
			cout << "2\n";
		}
	}
}