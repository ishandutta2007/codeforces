// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int n;
int a[55];

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i=0; i<n; i++)
			cin >> a[i];
		sort(a, a+n);
		int d = 1e9;
		for (int i=0; i<n-1; i++)
			d = min(d, a[i+1] - a[i]);
		cout << d << '\n';
	}
}