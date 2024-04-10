// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int n, k;
int a[100005];

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int t;
	cin >> t;
	while (t--) {
		cin >> n >> k;
		for (int i=0; i<n; i++) {
			int x;
			cin >> x;
			if (x < k) x = -1;
			else if (x > k) x = 1;
			else x = 0;
			a[i] = x;
		}

		int k = 0, z = count(a, a+n, 0);

		for (int i=0; i<n-1; i++) {
			if (a[i] == 0 && a[i+1] == 0) k = 1;
			if (a[i] == 1 && a[i+1] == 1 && z) k = 1;
			if (a[i] + a[i+1] == 1) k = 1;
		}

		for (int i=0; i<n-2; i++) {
			if (a[i] == 1 && a[i+1] == -1 && a[i+2] == 1 && z) k = 1;
			if (a[i] + a[i+1] + a[i+2] == 0) k = 1;
			if (a[i] == 0 && a[i+1] == -1 && a[i+2] == 0) k = 1;
		}

		// for (int i=0; i<n-3; i++) {
		// 	if (a[i] == 0 && a[i+1] == -1 && a[i+2] == -1 && a[i+3] == 0) k = 1;
		// }

		if (z == n) k = 1;

		cout << (k ? "yes\n" : "no\n");
	}
}