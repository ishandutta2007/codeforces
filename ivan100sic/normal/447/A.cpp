#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int a[2333];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n, p;
	cin >> n >> p;
	for (int i=1; i<=p; i++) {
		int x;
		cin >> x;
		x %= n;
		if (a[x]) {
			cout << i;
			return 0;
		}
		a[x] = 1;
	}
	cout << -1;
}